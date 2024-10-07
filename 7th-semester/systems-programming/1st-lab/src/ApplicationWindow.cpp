#include "ApplicationWindow.h"

#include "ui_ApplicationUi.h"

#include <iostream>

namespace systems_programming
{
ApplicationWindow::ApplicationWindow(QWidget* parent)
    : QMainWindow{ parent },
      m_ui{ new Ui::ApplicationUi }
{
    m_ui->setupUi(this);
    m_tableManager.setUi(m_ui);

    m_tableManager.loadAssemblyToSourceTable();
    m_tableManager.loadCodeOperationTable();

    connectButtonSlots();
}

ApplicationWindow::~ApplicationWindow()
{
    delete m_ui;
}

void ApplicationWindow::connectButtonSlots()
{
    connect(m_ui->firstPassButton, &QPushButton::clicked,
            this, &ApplicationWindow::performFirstPass);
    connect(m_ui->secondPassButton, &QPushButton::clicked,
            this, &ApplicationWindow::performSecondPass);
}

void ApplicationWindow::performFirstPass()
{
    std::cerr << "yo\n";
}

void ApplicationWindow::performSecondPass()
{
    std::cerr << "yoo\n";
}
}
