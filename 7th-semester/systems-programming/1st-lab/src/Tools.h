#ifndef SYSTEMS_PROGRAMMING_TOOLS_H_
#define SYSTEMS_PROGRAMMING_TOOLS_H_

#include <QString>

namespace systems_programming::checks
{
bool isDirective(const QString& mnemonic);
bool isReservingDirective(const QString& mnemonic);
bool isDefiningDirective(const QString& mnemonic);
}

namespace systems_programming::formatters
{
QString padWithZeroesToHex(int number, int padding);
}

namespace systems_programming::size_tools
{
int getOperandSize(const QString& operand);
}

#endif
