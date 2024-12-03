#ifndef SYSTEMS_PROGRAMMING_APPLICATION_WINDOW_H_
#define SYSTEMS_PROGRAMMING_APPLICATION_WINDOW_H_

#include <QMainWindow>

#include "FirstPassProcessor.h"
#include "SecondPassProcessor.h"
#include "TableManager.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
class ApplicationUi;
}
QT_END_NAMESPACE

namespace systems_programming
{
class ApplicationWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ApplicationWindow(QWidget* parent = nullptr);
    ~ApplicationWindow();

    void connectButtonSlots();

private slots:
    void performFirstPass();
    void performSecondPass();
    void clearHelperTable();

private:
    Ui::ApplicationUi* m_ui{};

    TableManager m_tableManager;
    FirstPassProcessor m_firstPass;
    SecondPassProcessor m_secondPass;

    int m_lastProgramAddress{};
};
}

#endif
