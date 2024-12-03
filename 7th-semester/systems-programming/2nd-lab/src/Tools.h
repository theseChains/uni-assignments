#ifndef SYSTEMS_PROGRAMMING_TOOLS_H_
#define SYSTEMS_PROGRAMMING_TOOLS_H_

#include <QString>

#include <optional>
#include <vector>

#include "AssemblyOperation.h"
#include "OperationCode.h"

namespace systems_programming::checks
{
bool isDirective(const QString& mnemonic);
bool isReservingDirective(const QString& mnemonic);
bool isDefiningDirective(const QString& mnemonic);
bool isRegister(const QString& operand);

bool labelIsValid(const QString& label, const QMap<QString, OperationInfo>& operationCodes);

bool sourceCodeIsValid(const std::vector<AssemblyOperation>& sourceCode);
std::optional<QString> operationCodesAreValid(const QMap<QString, OperationInfo>& operationCodes);
}

namespace systems_programming::formatters
{
QString padWithZeroesToHex(int number, int padding);
QString formatSecondPassOperand(const QString& operand, const QString& mnemonic);
}

namespace systems_programming::size_tools
{
std::optional<int> getOperandSize(const QString& operand);
}

#endif
