#ifndef SYSTEMS_PROGRAMMING_FIRST_PASS_PROCESSOR_H_
#define SYSTEMS_PROGRAMMING_FIRST_PASS_PROCESSOR_H_

#include <unordered_map>
#include <vector>

#include <QString>
#include <QMap>

#include "AssemblyOperation.h"
#include "OperationCode.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
class ApplicationUi;
}
QT_END_NAMESPACE

namespace systems_programming
{
class FirstPassProcessor
{
public:
    FirstPassProcessor() = default;

    void setup(const std::vector<AssemblyOperation>& sourceCode,
               const QMap<QString, OperationInfo>& operationCodes,
               Ui::ApplicationUi* ui);

    void performFirstPass();

private:
    void processLabeledLine(const AssemblyOperation& line);
    void processNonLabeledLine(const AssemblyOperation& line);

    void processDirectiveLabeledLine(const AssemblyOperation& line);
    void processCommandLabeledLine(const AssemblyOperation& line);

    void processDirectiveNonLabeledLine(const AssemblyOperation& line);
    void processCommandNonLabeledLine(const AssemblyOperation& line);

private:
    std::vector<AssemblyOperation> m_sourceCode;
    QMap<QString, OperationInfo> m_operationCodes;
    Ui::ApplicationUi* m_ui;

    QMap<QString, int> m_symbolicNamesTable;

    int m_addressCounter{ 0 };

    bool m_metError{ false };
};
}

#endif
