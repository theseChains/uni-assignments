#ifndef SYSTEMS_PROGRAMMING_TABLE_MANAGER_H_
#define SYSTEMS_PROGRAMMING_TABLE_MANAGER_H_

#include <QTableWidget>
#include <QString>
#include <QMap>

#include <vector>

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
class TableManager
{
public:
    TableManager() = default;

    void setUi(Ui::ApplicationUi* ui);

    void loadAssemblyToSourceTable();
    void loadCodeOperationTable();

    static void addRowToTable(QTableWidget* table,
                              const std::vector<QString>& values);

    std::vector<AssemblyOperation> getAssemblySourceCode() const;
    QMap<QString, OperationInfo> getOperationCodes() const;

private:
    Ui::ApplicationUi* m_ui;
};
}

#endif
