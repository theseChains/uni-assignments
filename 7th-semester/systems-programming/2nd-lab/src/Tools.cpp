#include "Tools.h"

#include <QMap>
#include <QSet>
#include <QHash>
#include <QDebug>
#include <QRegularExpression>

#include <cctype>
#include <iostream>
#include <ranges>

#include "Constants.h"

namespace systems_programming::checks
{
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

bool isRegister(const QString& operand)
{
    static const QSet<QString> registers{
        "R0", "R1", "R2", "R3", "R4", "R5", "R6", "R7",
        "R8", "R9", "R10", "R11", "R12", "R13", "R14", "R15"
    };

    return registers.contains(operand);
}

bool labelIsValid(const QString& label, const QMap<QString, OperationInfo>& operationCodes)
{
    bool symbolsAreValid{ std::all_of(label.begin(), label.end(), [](QChar ch) {
        return ch.isLetterOrNumber();
    }) };

    if (isDirective(label) || isRegister(label))
    {
        return false;
    }

    return (label[0].isLetter() && symbolsAreValid && !operationCodes.contains(label));
}

static bool reservingDirectiveIsCorrect(const QString& operand)
{
    bool converted{};
    operand.toInt(&converted);
    return converted;
}

// also return error msg
bool sourceCodeIsValid(const std::vector<AssemblyOperation>& sourceCode)
{
    bool metStart{ false };
    bool metEnd{ false };
    for (const auto& line : sourceCode)
    {
        QString mnemonic{ line.mnemonic };
        QString operand{ line.firstOperand };

        if (mnemonic == "START")
        {
            metStart = true;
        }
        else if (mnemonic == "END")
        {
            metEnd = true;
        }
        else if (isReservingDirective(mnemonic))
        {

        }
        else if (isDefiningDirective(mnemonic))
        {

        }
    }

    return (metStart && metEnd);
}

std::optional<QString> operationCodesAreValid(const QMap<QString, OperationInfo>& operationCodes)
{
    for (auto it = operationCodes.cbegin(); it != operationCodes.cend(); ++it) {
        const QString& opName{ it.key() };
        int opSize{ it.value().size };

        if ((opSize > 4 || opSize < 1) && !opName.isEmpty())
        {
            return opName;
        }
    }

    return std::nullopt;
}
}

namespace systems_programming::formatters
{
QString padWithZeroesToHex(int number, int padding)
{
    QString string = QString::number(number, 16).toUpper();
    return string.rightJustified(padding, '0');
}

QString formatSecondPassOperand(const QString& operand, const QString& mnemonic)
{
    QString formatted{};

    if (operand.front().isDigit())
    {
        int value{ operand.toInt() };
        if (mnemonic == "WORD")
        {
            formatted = padWithZeroesToHex(value, 6);
        }
        else
        {
            formatted = QString::number(value, 16).toUpper();
        }
    }
    else if (operand.front() == 'X')
    {
        int begin{ operand.indexOf('"') };
        int end{ operand.lastIndexOf('"') };

        formatted = operand.mid(begin + 1, end - begin - 1);
    }
    else if (operand.front() == 'C')
    {
        int begin{ operand.indexOf('"') };
        int end{ operand.lastIndexOf('"') };

        QString stringValue{ operand.mid(begin + 1, end - begin - 1) };
        QByteArray byteArray{ stringValue.toUtf8() };
        formatted = byteArray.toHex().toUpper();
    }

    return formatted;
}
}

namespace systems_programming::size_tools
{
std::optional<int> getOperandSize(const QString& operand)
{
    if (operand.front().isDigit())
    {
        return 1;
    }

    if (operand.front() != 'C' && operand.front() != 'X')
    {
        return std::nullopt;
    }

    std::string operandValue{ operand.toStdString().substr() };
    std::size_t begin{ operandValue.find('"') };
    std::size_t end{ operandValue.rfind('"') };

    if (end == begin || begin != 1 || end != operand.size() - 1u)
    {
        return std::nullopt;
    }

    if (operand.startsWith('X'))
    {
        QRegularExpression regex{ R"regex("([0-9A-Fa-f]+)")regex" };
        QRegularExpressionMatch match = regex.match(operand);
        if (!match.hasMatch() || (end - begin - 1) % 2 != 0)
        {
            return std::nullopt;
        }
    }

    std::size_t size{ end - begin - 1 };
    if (operand.startsWith('X'))
    {
        size /= 2;
    }

    return size;
}
}
