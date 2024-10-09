#include "FirstPassProcessor.h"

#include "ui_ApplicationUi.h"
#include "TableManager.h"

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

// move to another file
// also to hex
QString padWithZeroes(int address)
{
    int number = address;  // Convert the string to an integer
    // Convert the number to a hexadecimal string
    QString hexString = QString::number(number, 16).toUpper();  // Convert to uppercase hex

    // Pad with leading zeroes
    return hexString.rightJustified(6, '0');
}

// yo, overload maybe?
QString toTwoChars(int number)
{
    QString string = QString::number(number, 16).toUpper();
    return string.rightJustified(2, '0');
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

// move to another file
bool isDirective(const QString& mnemonic)
{
    return (mnemonic == "RESB" || mnemonic == "RESW" ||
            mnemonic == "BYTE" || mnemonic == "WORD" ||
            mnemonic == "START" || mnemonic == "END");
}

bool isReservingDirective(const QString& directive)
{
    return (directive == "RESB" || directive == "RESW");
}

bool isDefiningDirective(const QString& directive)
{
    return (directive == "BYTE" || directive == "WORD");
}

void FirstPassProcessor::processLabeledLine(const AssemblyOperation& line)
{
    qDebug() << "processLabeledLine mnemonic:" << line.mnemonic;
    if (isDirective(line.mnemonic))
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
    if (isDirective(line.mnemonic))
    {
        processDirectiveNonLabeledLine(line);
    }
    else
    {
        processCommandNonLabeledLine(line);
    }
}

int getHexNumberSize(const QString&)
{
    // for now
    return 4;
}

void FirstPassProcessor::processDirectiveLabeledLine(const AssemblyOperation& line)
{
    auto* helperTable{ m_ui->helperTable };

    qDebug() << "processDirectiveLabeledLine mnemonic: " << line.mnemonic;
    if (line.mnemonic == "START")
    {
        TableManager::addRowToTable(helperTable,
                { line.label.value(),
                line.mnemonic,
                line.firstOperand.rightJustified(6, '0') });
        // maybe add an exception here too..
        m_addressCounter = line.firstOperand.toInt(nullptr, 16);
    }
    // this shouldnt be here
    else if (line.mnemonic == "END")
    {
        std::cout << "yo end\n";
    }
    else
    {
        QString label{ line.label.value() };

        // should be put in a function
        if (m_symbolicNamesTable.contains(label))
        {
            m_metError = true;
            qDebug() << "met the same symbolic twice: " << label;
            return;
        }

        // convert later i guess..
        // i should figure this out properly
        m_symbolicNamesTable[label] = m_addressCounter;

        auto* symbolicNamesTable{ m_ui->symbolicNamesTable };
        TableManager::addRowToTable(symbolicNamesTable,
                { label, padWithZeroes(m_addressCounter) });

        QString directive{ line.mnemonic };
        qDebug() << "directive labeled line mnemonic:" << directive;
        if (isDefiningDirective(directive))
        {
            QString value{ line.firstOperand };
            int size{ 0 };
            qDebug() << "value: " << value << '\n';

            if (value.startsWith('X'))
            {
                size = getHexNumberSize(value);
            }
            else if (value.startsWith('C'))
            {
                // for now
                size = 6;
            }
            else
            {
                // this is for number.. temporary
                size = 1;
            }
            QString address{ padWithZeroes(m_addressCounter) };
            TableManager::addRowToTable(helperTable, { address, directive, value });
            m_addressCounter += (directive == "WORD" ? 3 : size);
        }
        else if (isReservingDirective(directive))
        {
            int reservationSize{ line.firstOperand.toInt() };

            // put this into function as well i guess
            QString address{ padWithZeroes(m_addressCounter) };
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
    }
}

void FirstPassProcessor::processCommandLabeledLine(const AssemblyOperation& line)
{
    QString label{ line.label.value() };
    QString mnemonic{ line.mnemonic };
    if (!m_operationCodes.contains(mnemonic))
    {
        m_metError = true;
        qDebug() << "unknown labeled mnemonic command: " << mnemonic;
        return;
    }

    if (m_symbolicNamesTable.contains(label))
    {
        m_metError = true;
        qDebug() << "met the same symbolic twice: " << label;
        return;
    }

    m_symbolicNamesTable[label] = m_addressCounter;

    auto* helperTable{ m_ui->helperTable };
    auto* symbolicNamesTable{ m_ui->symbolicNamesTable };
    TableManager::addRowToTable(symbolicNamesTable,
            { label, padWithZeroes(m_addressCounter) });

    // should parse commands in a different function i guess
    // also nondirective means command i think?
    // so i can call it that instead

    // check for size too i guess
    // we support 1 through 4
    int commandSize{ m_operationCodes[mnemonic].size };
    // check this later
    int addresationType{ commandSize > 2 ? 1 : 0 };
    int commandCode{ m_operationCodes[mnemonic].code.toInt(nullptr, 16) };
    // change name
    qDebug() << "command:" << mnemonic << "size:" << commandSize
            << "code:" << commandCode;
    int realBinaryCode{ 4 * commandCode + addresationType };

    QString address{ padWithZeroes(m_addressCounter) };
    QString binary{ toTwoChars(realBinaryCode) };
    QString secondOperand{};
    if (line.secondOperand.has_value())
    {
        secondOperand = line.secondOperand.value();
    }
    TableManager::addRowToTable(helperTable,
                                { address, binary, line.firstOperand, secondOperand });

    m_addressCounter += commandSize;
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
    if (!m_operationCodes.contains(mnemonic))
    {
        m_metError = true;
        qDebug() << "unknown non-labeled mnemonic command: " << mnemonic;
        return;
    }

    // duplicate
    auto* helperTable{ m_ui->helperTable };
    int commandSize{ m_operationCodes[mnemonic].size };
    // check this later
    int addresationType{ commandSize > 2 ? 1 : 0 };
    int commandCode{ m_operationCodes[mnemonic].code.toInt(nullptr, 16) };
    // change name
    int realBinaryCode{ 4 * commandCode + addresationType };

    qDebug() << "command:" << mnemonic << "size:" << commandSize
            << "code:" << commandCode;

    QString address{ padWithZeroes(m_addressCounter) };
    QString binary{ toTwoChars(realBinaryCode) };
    QString secondOperand{};
    if (line.secondOperand.has_value())
    {
        secondOperand = line.secondOperand.value();
    }
    TableManager::addRowToTable(helperTable,
                                { address, binary, line.firstOperand, secondOperand });

    m_addressCounter += commandSize;
}
}
