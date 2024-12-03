#ifndef SYSTEMS_PROGRAMMING_SECOND_PASS_PROCESSOR_H_
#define SYSTEMS_PROGRAMMING_SECOND_PASS_PROCESSOR_H_

#include <QMap>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui
{
class ApplicationUi;
}
QT_END_NAMESPACE

namespace systems_programming
{
class SecondPassProcessor
{
public:
    SecondPassProcessor() = default;

    void setup(const QMap<QString, int>& symbolicNamesTable,
               int lastProgramAddress,
               Ui::ApplicationUi* ui);

    void performSecondPass();

    QString getLineInfo();

private:
    QString processCommandOrDirective(int row);
    QString processReservingDirective(int row);
    QString processDefiningDirective(int row);

private:
    QMap<QString, int> m_symbolicNamesTable;
    int m_lastProgramAddress{};
    Ui::ApplicationUi* m_ui;

    bool m_metError{ false };

    int m_lineNumber{ 0 };
};
}

#endif
