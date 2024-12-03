#include "FirstPassProcessor.h"

#include "ui_ApplicationUi.h"
#include "Constants.h"
#include "TableManager.h"
#include "Tools.h"

#include <algorithm>
#include <iostream>
#include <QDebug>

namespace systems_programming
{
void FirstPassProcessor::setup(const std::vector<AssemblyOperation>& sourceCode,
        const QMap<QString, OperationInfo>& operationCodes, Ui::ApplicationUi* ui)
{
    m_sourceCode = sourceCode;
    m_operationCodes = operationCodes;
    m_ui = ui;
}

bool FirstPassProcessor::operationCodesTableIsValid(QTableWidget* table)
{
    for (int row = 0; row < table->rowCount(); ++row)
    {
        QString operation = table->item(row, 0)->text();
        QString code = table->item(row, 1)->text();
        QString size = table->item(row, 2)->text();

        if (operation.isEmpty() && (!code.isEmpty() || !size.isEmpty()))
        {
            return false;
        }

        if (!operation.isEmpty() && (code.isEmpty() || size.isEmpty()))
        {
            return false;
        }

        if (operation.isEmpty() && code.isEmpty() && size.isEmpty())
        {
            continue;
        }

        bool ok{};
        int codeNumber{ code.toInt(&ok, 16) };
        /* qDebug() << "code number: " << codeNumber << '\n'; */
        if (codeNumber > 63 || !ok || codeNumber < 1)
        {
            return false;
        }
    }

    return true;
}

int FirstPassProcessor::performFirstPass()
{
    clear();
    m_lineNumber = 0;

    // could be put in a single function
    if (auto name = checks::operationCodesAreValid(m_operationCodes); name.has_value())
    {
        clear();
        m_ui->firstPassageErrors->setText(getLineInfo() + "Неправильный размер для операции " + name.value());
        return 0;
    }

    if (!operationCodesTableIsValid(m_ui->codeOperationTable))
    {
        clear();
        m_ui->firstPassageErrors->setText(getLineInfo() + "Неправильная запись в таблице кодов операций");
        return 0;
    }

    for (const auto& line : m_sourceCode)
    {
        ++m_lineNumber;
        if (line.mnemonic.toUpper() == "START" && m_metStart)
        {
            clear();
            m_ui->firstPassageErrors->setText(getLineInfo() + "Начало программы встречается дважды");
            m_metError = true;
            break;
        }

        if (line.mnemonic.isEmpty())
        {
            clear();
            m_ui->firstPassageErrors->setText(getLineInfo() + "Поле МКОП не может быть пустым");
            m_metError = true;
            break;
        }

        if (line.firstOperand.isEmpty() && line.mnemonic != "END" && line.mnemonic != "START")
        {
            clear();
            m_ui->firstPassageErrors->setText(getLineInfo() + "Поле операнда не может быть пустым");
            m_metError = true;
            break;
        }

        if (m_lineNumber == 1 && line.mnemonic.toUpper() != "START")
        {
            clear();
            m_ui->firstPassageErrors->setText(getLineInfo() + "Диркетива START не найдена");
            m_metError = true;
            break;
        }

        if (line.label.has_value() && line.label.value().length() > 10 && line.mnemonic.toUpper() != "START")
        {
            clear();
            m_ui->firstPassageErrors->setText(getLineInfo() + "Название метки не должно превышать 10 символов");
            m_metError = true;
            break;
        }

        if (line.label.has_value() && line.mnemonic != "START" && !checks::labelIsValid(line.label.value(), m_operationCodes))
        {
            clear();
            m_ui->firstPassageErrors->setText(getLineInfo() + "Некорректное название метки");
            m_metError = true;
            break;
        }
        
        if (line.label.has_value() || m_lineNumber == 1)
        {
            processLabeledLine(line);
        }
        else
        {
            processNonLabeledLine(line);
        }

        if (m_addressCounter > constants::kMaxAddress)
        {
            m_metError = true;
            m_ui->firstPassageErrors->setText(getLineInfo() + "Адрес программы на МКОП " + line.mnemonic + " превышает максимальный");
            break;
        }

        if (m_metError)
        {
            m_ui->helperTable->setRowCount(0);
            m_ui->symbolicNamesTable->setRowCount(0);
            m_symbolicNamesTable.clear();
            break;
        }

        if (m_metEnd)
        {
            break;
        }
    }

    if (!m_metStart && !m_metError)
    {
        clear();
        m_ui->firstPassageErrors->setText(getLineInfo() + "Отсутствует директива START");
        return 0;
    }

    if (!m_metEnd && !m_metError)
    {
        clear();
        m_ui->firstPassageErrors->setText(getLineInfo() + "Отсутствует директива END");
        return 0;
    }

    if (!m_metError)
        m_ui->firstPassageErrors->clear();

    return m_addressCounter;
}

void FirstPassProcessor::processLabeledLine(const AssemblyOperation& line)
{
    if (checks::isDirective(line.mnemonic))
    {
        processDirectiveLabeledLine(line);
    }
    else
    {
        processCommandLabeledLine(line);
    }
}

void FirstPassProcessor::processNonLabeledLine(const AssemblyOperation& line)
{
    if (checks::isDirective(line.mnemonic))
    {
        processDirectiveNonLabeledLine(line);
    }
    else
    {
        processCommandNonLabeledLine(line);
    }
}

void FirstPassProcessor::processDirectiveLabeledLine(const AssemblyOperation& line)
{
    auto* helperTable{ m_ui->helperTable };

    if (line.mnemonic == "START")
    {
        m_metStart = true;

        if (!line.label.has_value())
        {
            m_metError = true;
            m_ui->firstPassageErrors->setText(getLineInfo() + "Название программы не задано");
            return;
        }

        if (line.label.value().length() > 10)
        {
            m_metError = true;
            m_ui->firstPassageErrors->setText(getLineInfo() + "Название программы слишком длинное (>10 символов)");
            return;
        }

        TableManager::addRowToTable(helperTable,
                { line.label.value(),
                  line.mnemonic,
                  line.firstOperand.rightJustified(6, '0') });
        m_addressCounter = 0;
        m_startAddress = line.firstOperand.toInt(nullptr, 16);

        if (m_addressCounter != 0)
        {
            m_metError = true;
            m_ui->firstPassageErrors->setText(getLineInfo() + "Адрес загрузки должен быть 0");
            return;
        }

        if (m_addressCounter > constants::kMaxAddress)
        {
            m_metError = true;
            m_ui->firstPassageErrors->setText(getLineInfo() + "Адрес загрузки превышает максимальный");
            return;
        }

        if (m_addressCounter < 0)
        {
            m_metError = true;
            m_ui->firstPassageErrors->setText(getLineInfo() + "Адрес загрузки отрицательный");
            return;
        }
    }
    else
    {
        QString label{ line.label.value() };

        if (labelAlreadyInSymbolicTable(label))
        {
            return;
        }

        m_symbolicNamesTable[label] = m_addressCounter;

        auto* symbolicNamesTable{ m_ui->symbolicNamesTable };
        TableManager::addRowToTable(symbolicNamesTable,
                { label, formatters::padWithZeroesToHex(m_addressCounter, 6) });

        QString directive{ line.mnemonic };
        if (checks::isDefiningDirective(directive))
        {
            processDefiningDirective(line);
        }
        else if (checks::isReservingDirective(directive))
        {
            processReservingDirective(line);
        }
    }
}

void FirstPassProcessor::processCommandLabeledLine(const AssemblyOperation& line)
{
    QString label{ line.label.value() };
    QString mnemonic{ line.mnemonic };
    if (labelAlreadyInSymbolicTable(label) || mnemonicNotInOperationCodes(mnemonic))
    {
        return;
    }

    m_symbolicNamesTable[label] = m_addressCounter;

    auto* symbolicNamesTable{ m_ui->symbolicNamesTable };
    TableManager::addRowToTable(symbolicNamesTable,
            { label, formatters::padWithZeroesToHex(m_addressCounter, 6) });

    processCommand(line);
}

void FirstPassProcessor::processDirectiveNonLabeledLine(const AssemblyOperation& line)
{
    if (line.mnemonic == "END")
    {
        QString address{ line.firstOperand };
        if (address.isEmpty())
        {
            address = QString::number(m_startAddress, 16);
        }
        else
        {
            bool ok{};
            int number = address.toInt(&ok, 16);
            if (!ok || number < m_startAddress || number > m_addressCounter)
            {
                m_metError = true;
                m_ui->firstPassageErrors->setText(getLineInfo() + "Неверный адрес точки входа");
                return;
            }
        }

        m_metEnd = true;

        QString convertedAddress{ formatters::padWithZeroesToHex(m_addressCounter, 6) };
        auto* helperTable{ m_ui->helperTable };
        TableManager::addRowToTable(helperTable,
                        { convertedAddress, "END", address, "" });
    }
}

void FirstPassProcessor::processCommandNonLabeledLine(const AssemblyOperation& line)
{
    QString mnemonic{ line.mnemonic };
    if (mnemonicNotInOperationCodes(mnemonic))
    {
        return;
    }

    processCommand(line);
}

void FirstPassProcessor::processCommand(const AssemblyOperation& line)
{
    if (checks::isRegister(line.firstOperand) && !checks::isRegister(line.secondOperand.value_or("")))
    {
        m_metError = true;
        m_ui->firstPassageErrors->setText(getLineInfo() + "Отсутствует второй регистр у команды " + line.mnemonic);
        return;
    }

    if (line.mnemonic == "ADD" && (!checks::isRegister(line.firstOperand) || !checks::isRegister(line.secondOperand.value_or(""))))
    {
        m_metError = true;
        m_ui->firstPassageErrors->setText(getLineInfo() + "У команды ADD операнды должны быть регистрами");
        return;
    }

    QString mnemonic{ line.mnemonic };
    int commandSize{ m_operationCodes[mnemonic].size };
    int addresationType{ commandSize > 2 ? 1 : 0 };
    int commandCode{ m_operationCodes[mnemonic].code.toInt(nullptr, 16) };

    if (line.firstOperand.startsWith('[') && line.firstOperand.endsWith(']') && commandSize > 2)
    {
        addresationType = 2;
    }

    int realBinaryCode{ 4 * commandCode + addresationType };

    QString address{ formatters::padWithZeroesToHex(m_addressCounter, 6) };
    QString binary{ formatters::padWithZeroesToHex(realBinaryCode, 2) };
    QString secondOperand{};
    if (line.secondOperand.has_value())
    {
        secondOperand = line.secondOperand.value();
    }

    auto* helperTable{ m_ui->helperTable };
    TableManager::addRowToTable(helperTable,
                        { address, binary, line.firstOperand, secondOperand });

    m_addressCounter += commandSize;
}

void FirstPassProcessor::processDefiningDirective(const AssemblyOperation& line)
{
    // BYTE can contain numbers (0 to 255), strings and hex numbers
    QString operand{ line.firstOperand };
    QString directive{ line.mnemonic };
    auto valueSize{ size_tools::getOperandSize(operand) };
    if (!valueSize.has_value())
    {
        m_metError = true;
        m_ui->firstPassageErrors->setText(getLineInfo() + "Неверный операнд: " + operand);
        return;
    }
    if (directive == "WORD")
    {
        bool ok{};
        int number{ operand.toInt(&ok) };
        if (!ok || number < 0)
        {
            m_metError = true;
            m_ui->firstPassageErrors->setText(getLineInfo() + "Операнд у WORD не является числом или является отрицательным числом");
            return;
        }
    }
    else if (directive == "BYTE")
    {
        if (operand.front().isDigit())
        {
            bool ok{};
            int number = operand.toInt(&ok);
            if (number < 0 || number > 255 || !ok)
            {
                m_metError = true;
                m_ui->firstPassageErrors->setText(getLineInfo() + "Операнд у BYTE не является корректным числом");
                return;
            }
        }
    }

    QString address{ formatters::padWithZeroesToHex(m_addressCounter, 6) };

    auto* helperTable{ m_ui->helperTable };
    TableManager::addRowToTable(helperTable, { address, directive, operand });
    m_addressCounter += (directive == "WORD" ? 3 : valueSize.value());
}

void FirstPassProcessor::processReservingDirective(const AssemblyOperation& line)
{
    int reservationSize{ line.firstOperand.toInt() };

    QString directive{ line.mnemonic };
    auto* helperTable{ m_ui->helperTable };
    QString address{ formatters::padWithZeroesToHex(m_addressCounter, 6) };
    TableManager::addRowToTable(helperTable, { address, directive, line.firstOperand });

    if (directive == "RESB")
    {
        if (reservationSize > 255 || reservationSize < 0)
        {
            m_metError = true;
            m_ui->firstPassageErrors->setText(getLineInfo() + "Превышен максимальный резервируемый объем памяти");
            return;
        }
        m_addressCounter += reservationSize;
    }
    else if (directive == "RESW")
    {
        if (reservationSize > constants::kMaxAddress || reservationSize < 0)
        {
            m_metError = true;
            m_ui->firstPassageErrors->setText(getLineInfo() + "Превышен максимальный резервируемый объем памяти");
            return;
        }
        m_addressCounter += reservationSize * 3;
    }
}

bool FirstPassProcessor::labelAlreadyInSymbolicTable(const QString& label)
{
    if (m_symbolicNamesTable.contains(label))
    {
        m_metError = true;
        m_ui->firstPassageErrors->setText(getLineInfo() + "Символическое имя " + label + " встречается дважды");
        return true;
    }

    return false;
}

bool FirstPassProcessor::mnemonicNotInOperationCodes(const QString& mnemonic)
{
    if (!m_operationCodes.contains(mnemonic))
    {
        m_metError = true;
        m_ui->firstPassageErrors->setText(getLineInfo() + "Неизвестный код операции: " + mnemonic);
        return true;
    }

    return false;
}

QString FirstPassProcessor::getLineInfo()
{
    return "Строка " + QString::number(m_lineNumber) + ": ";
}

void FirstPassProcessor::clear()
{
    m_ui->symbolicNamesTable->setRowCount(0);
    m_ui->helperTable->setRowCount(0);
    m_ui->binaryCode->setRowCount(0);
    m_ui->firstPassageErrors->clear();
    m_ui->secondPassageErrors->clear();
    m_symbolicNamesTable.clear();

    m_addressCounter = 0;
    // m_lineNumber = 0;
    m_metError = false;
    m_metStart = false;
    m_metEnd = false;
}
}
