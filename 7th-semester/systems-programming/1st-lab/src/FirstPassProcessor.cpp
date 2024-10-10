#include "FirstPassProcessor.h"

#include "ui_ApplicationUi.h"
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

void FirstPassProcessor::performFirstPass()
{
    for (const auto& line: m_sourceCode)
    {
        if (line.label.has_value())
        {
            processLabeledLine(line);
        }
        else
        {
            processNonLabeledLine(line);
        }

        if (m_metError)
        {
            qDebug() << "error at mnemonic: " << line.mnemonic << '\n';
            break;
        }
    }
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
        TableManager::addRowToTable(helperTable,
                { line.label.value(),
                  line.mnemonic,
                  line.firstOperand.rightJustified(6, '0') });
        m_addressCounter = line.firstOperand.toInt(nullptr, 16);
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
        std::cout << "yo end\n";
    }
    // could anything else be here?
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
    QString mnemonic{ line.mnemonic };
    int commandSize{ m_operationCodes[mnemonic].size };
    // check this later
    int addresationType{ commandSize > 2 ? 1 : 0 };
    int commandCode{ m_operationCodes[mnemonic].code.toInt(nullptr, 16) };
    int realBinaryCode{ 4 * commandCode + addresationType };

    qDebug() << "command:" << mnemonic << "size:" << commandSize
            << "code:" << commandCode;

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
    // so WORD can only contain positive numbers i guess
    // BYTE can contain numbers (0 to 255), strings and hex numbers
    QString operand{ line.firstOperand };
    QString directive{ line.mnemonic };
    int valueSize{ size_tools::getOperandSize(operand) };

    QString address{ formatters::padWithZeroesToHex(m_addressCounter, 6) };

    auto* helperTable{ m_ui->helperTable };
    TableManager::addRowToTable(helperTable, { address, directive, operand });
    m_addressCounter += (directive == "WORD" ? 3 : valueSize);
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
        m_addressCounter += reservationSize;
    }
    else if (directive == "RESW")
    {
        m_addressCounter += reservationSize * 3;
    }
}

bool FirstPassProcessor::labelAlreadyInSymbolicTable(const QString& label)
{
    if (m_symbolicNamesTable.contains(label))
    {
        m_metError = true;
        // output to error
        qDebug() << "met the same symbolic twice: " << label;
        return true;
    }

    return false;
}

bool FirstPassProcessor::mnemonicNotInOperationCodes(const QString& mnemonic)
{
    if (!m_operationCodes.contains(mnemonic))
    {
        m_metError = true;
        qDebug() << "unknown labeled mnemonic command: " << mnemonic;
        return true;
    }

    return false;
}
}
