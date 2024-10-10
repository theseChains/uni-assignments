#include "Tools.h"

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
}

namespace systems_programming::formatters
{
QString padWithZeroesToHex(int number, int padding)
{
    QString string = QString::number(number, 16).toUpper();
    return string.rightJustified(padding, '0');
}
}

namespace systems_programming::size_tools
{
int getOperandSize(const QString& operand)
{
    if (operand.front().isDigit())
    {
        return 1;
    }

    std::string operandValue{ operand.toStdString().substr() };
    std::size_t begin{ operandValue.find('"') };
    std::size_t end{ operandValue.rfind('"') };

    std::size_t size{ end - begin - 1 };
    if (operand.startsWith('X'))
    {
        size /= 2;
    }

    return size;
}
}
