#ifndef SYSTEMS_PROGRAMMING_FIRST_PASS_PROCESSOR_H_
#define SYSTEMS_PROGRAMMING_FIRST_PASS_PROCESSOR_H_

#include <unordered_map>
#include <vector>

#include <QTableWidget>
#include <QObject>
#include <QMap>
#include <QString>

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
class FirstPassProcessor : public QObject
{
    Q_OBJECT

public:
    FirstPassProcessor() = default;

    void setup(const std::vector<AssemblyOperation>& sourceCode,
               const QMap<QString, OperationInfo>& operationCodes,
               Ui::ApplicationUi* ui);

    int performFirstPass();

private:
    void processLabeledLine(const AssemblyOperation& line);
    void processNonLabeledLine(const AssemblyOperation& line);

    void processDirectiveLabeledLine(const AssemblyOperation& line);
    void processCommandLabeledLine(const AssemblyOperation& line);

    void processDirectiveNonLabeledLine(const AssemblyOperation& line);
    void processCommandNonLabeledLine(const AssemblyOperation& line);

    void processCommand(const AssemblyOperation& line);
    void processDefiningDirective(const AssemblyOperation& line);
    void processReservingDirective(const AssemblyOperation& line);

    bool labelAlreadyInSymbolicTable(const QString& label);
    bool mnemonicNotInOperationCodes(const QString& mnemonic);

    bool operationCodesTableIsValid(QTableWidget* table);

    QString getLineInfo();
    void clear();

private:
    std::vector<AssemblyOperation> m_sourceCode;
    QMap<QString, OperationInfo> m_operationCodes;
    Ui::ApplicationUi* m_ui;

    QMap<QString, int> m_symbolicNamesTable;

    int m_lineNumber{ 0 };
    int m_addressCounter{ 0 };

    bool m_metError{ false };

    int m_startAddress{};

    bool m_metStart{};
    bool m_metEnd{};
};
}

#endif
