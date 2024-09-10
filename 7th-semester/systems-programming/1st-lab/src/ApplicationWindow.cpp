#include "ApplicationWindow.h"

#include "ui_ApplicationUi.h"

namespace systems_programming
{
ApplicationWindow::ApplicationWindow(QWidget* parent)
    : QMainWindow{ parent }, m_ui{ new Ui::ApplicationUi }
{
    m_ui->setupUi(this);
}

ApplicationWindow::~ApplicationWindow()
{
    delete m_ui;
}
}
