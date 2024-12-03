#include "SecondPassProcessor.h"

#include "ui_ApplicationUi.h"
#include "TableManager.h"
#include "Tools.h"

#include <QDebug>

namespace systems_programming
{
void SecondPassProcessor::setup(const QMap<QString, int>& symbolicNamesTable,
                                int lastProgramAddress,
                                Ui::ApplicationUi* ui)
{
    m_symbolicNamesTable = symbolicNamesTable;
    m_lastProgramAddress = lastProgramAddress;
    m_ui = ui;
}

void SecondPassProcessor::performSecondPass()
{
    if (!m_ui->firstPassageErrors->text().isEmpty())
    {
        return;
    }

    m_metError = false;
    m_ui->binaryCode->setRowCount(0);
    m_ui->setupTable->setRowCount(0);
    m_ui->secondPassageErrors->clear();

    auto* helperTable{ m_ui->helperTable };
    auto* binaryCode{ m_ui->binaryCode };

    int helperTableSize{ helperTable->rowCount() };
    for (int row{ 0 }; row < helperTableSize; ++row)
    {
        m_lineNumber = row + 1;
        QString rowText{};
        if (row == 0)
        {
            QString programName{ helperTable->item(row, 0)->text() };
            QString initialAddress{ helperTable->item(row, 2)->text() };
            QString programSize{
                    formatters::padWithZeroesToHex(
                            m_lastProgramAddress -
                                    initialAddress.toInt(nullptr, 16), 6) };
            rowText = "H " + programName + " " + initialAddress + " " +
                        programSize;
        }
        else if (row == helperTableSize - 1)
        {
            int initialAddress{ helperTable->item(row, 2)->text().toInt(nullptr, 16) };
            QString address{
                    formatters::padWithZeroesToHex(initialAddress, 6)
            };
            TableManager::addRowToTable(binaryCode, { "E " + address });
        }
        else
        {
            rowText = processCommandOrDirective(row);
        }

        TableManager::addRowToTable(binaryCode, { rowText });

        if (m_metError)
        {
            m_ui->binaryCode->clear();
            m_ui->setupTable->clear();
            break;
        }
    }

    if (!m_metError)
    {
        m_ui->secondPassageErrors->clear();
    }
}

QString SecondPassProcessor::processCommandOrDirective(int row)
{
    auto* helperTable{ m_ui->helperTable };
    auto* setupTable{ m_ui->setupTable };

    QString mnemonicCode{ helperTable->item(row, 1)->text() };
    if (checks::isReservingDirective(mnemonicCode))
    {
        return processReservingDirective(row);
    }
    else if (checks::isDefiningDirective(mnemonicCode))
    {
        return processDefiningDirective(row);
    }

    QString result{};
    QString address{ helperTable->item(row, 0)->text() };
    QString operand{ helperTable->item(row, 2)->text() };

    if (operand.startsWith('[') && operand.endsWith(']'))
    {
        operand = operand.mid(1, operand.length() - 2);
        if (m_symbolicNamesTable.contains(operand))
        {
            QString operandAddress{
                formatters::padWithZeroesToHex(m_symbolicNamesTable[operand], 6)
            };
            int addressNumber = operandAddress.toInt(nullptr, 16);
            QString addressNextStr = helperTable->item(row + 1, 0)->text();
            int addressNext = addressNextStr.toInt(nullptr, 16);
            int difference = addressNumber - addressNext;
            QString objectCodeAddress{
                formatters::padWithZeroesToHex(difference & 0xFFFFFF, 6)
            };
            QString objectCode{ mnemonicCode + objectCodeAddress };

            QString length{ formatters::padWithZeroesToHex(objectCode.size(), 2) };
            result = "T " + address + " " + length + " " + objectCode;
        }
    }
    else if (m_symbolicNamesTable.contains(operand))
    {
        QString operandAddress{
            formatters::padWithZeroesToHex(m_symbolicNamesTable[operand], 6)
        };
        TableManager::addRowToTable(setupTable, { address });
        QString objectCode{ mnemonicCode + operandAddress };
        QString length{ formatters::padWithZeroesToHex(objectCode.size(), 2) };
        result = "T " + address + " " + length + " " + objectCode;
    }
    else if (checks::isRegister(operand))
    {
        /* qDebug() << "mnemonic: " << helperTable->item(row, 1)->text(); */
        QString numberPart{ operand.mid(1) };
        int number{ numberPart.toInt(nullptr) };
        QString registerNumber{ QString::number(number, 16).toUpper() };
        QString secondOperand{ helperTable->item(row, 3)->text() };
        if (!secondOperand.isEmpty())
        {
            numberPart = secondOperand.mid(1);
            number = numberPart.toInt(nullptr);
            secondOperand = QString::number(number, 16).toUpper();
        }
        QString length{
            formatters::padWithZeroesToHex(registerNumber.size() +
                    secondOperand.size() + mnemonicCode.size(), 2)
        };
        // mess
        result = "T " + address + " " + length + " " + mnemonicCode + registerNumber + secondOperand;
    }
    else if (operand.front().isDigit() || operand.front() == '-')
    {
        bool ok{};
        int number{ operand.toInt(&ok, 10) };
        if (number > 255 || number < 0 || !ok)
        {
            m_metError = true;
            m_ui->secondPassageErrors->setText(getLineInfo() + "Операндная часть не является числом от 0 до 255");
            return "";
        }

        QString hexNumber{ formatters::padWithZeroesToHex(number, 2) };
        QString length{
                formatters::padWithZeroesToHex(hexNumber.size() +
                    mnemonicCode.size(), 2) };
        result = "T " + address + " " + length + " " + mnemonicCode + hexNumber;
    }
    else
    {
        m_metError = true;
        m_ui->secondPassageErrors->setText(getLineInfo() + "Неверно задан операнд");
    }

    return result;
}

QString SecondPassProcessor::processReservingDirective(int row)
{
    auto* helperTable{ m_ui->helperTable };

    int reserveSize{ helperTable->item(row, 2)->text().toInt() };
    if (helperTable->item(row, 1)->text() == "RESW")
    {
        reserveSize *= 3;
    }

    QString address{ helperTable->item(row, 0)->text() };

    /* return "T " + address + " " + QString::number(reserveSize, 16).toUpper(); */
    return "T " + address + " " + "00";
}

QString SecondPassProcessor::processDefiningDirective(int row)
{
    auto* helperTable{ m_ui->helperTable };

    QString address{ helperTable->item(row, 0)->text() };
    QString mnemonicCode{ helperTable->item(row, 1)->text() };
    QString operand{ helperTable->item(row, 2)->text() };

    QString formatted{
        formatters::formatSecondPassOperand(operand, mnemonicCode)
    };
    QString length{ formatters::padWithZeroesToHex(formatted.length(), 2) };

    return "T " + address + " " + length + " " + formatted;
}

QString SecondPassProcessor::getLineInfo()
{
    return "Строка " + QString::number(m_lineNumber) + ": ";
}
}
