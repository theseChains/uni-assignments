#ifndef SYSTEMS_PROGRAMMING_APPLICATION_WINDOW_H_
#define SYSTEMS_PROGRAMMING_APPLICATION_WINDOW_H_

#include <QMainWindow>

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
public:
    ApplicationWindow(QWidget* parent = nullptr);
    ~ApplicationWindow();

private:
    Ui::ApplicationUi* m_ui{};
};
}

#endif
