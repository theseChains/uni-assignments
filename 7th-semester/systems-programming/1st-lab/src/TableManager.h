#ifndef SYSTEMS_PROGRAMMING_TABLE_MANAGER_H_
#define SYSTEMS_PROGRAMMING_TABLE_MANAGER_H_

#include <QTableWidget>

#include <string_view>

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

    void addRowToSourceTable(const QString& first, const QString& second,
                             const QString& third, const QString& fourth = "");
    void addRowToCodeOperationTable(const QString& name, const QString& code,
                                    const QString& size);

private:
    Ui::ApplicationUi* m_ui;
};
}

#endif
