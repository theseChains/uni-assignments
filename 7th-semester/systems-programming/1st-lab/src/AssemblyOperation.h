#ifndef SYSTEMS_PROGRAMMING_ASSEMBLY_OPERATION_H_
#define SYSTEMS_PROGRAMMING_ASSEMBLY_OPERATION_H_

#include <optional>

#include <QString>

namespace systems_programming
{
struct AssemblyOperation
{
    std::optional<QString> label;
    QString operation;
    QString firstOperand;
    std::optional<QString> secondOperand;
};
}

#endif
