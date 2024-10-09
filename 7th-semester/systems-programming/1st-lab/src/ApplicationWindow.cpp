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

    m_firstPass.setup(m_tableManager.getAssemblySourceCode(),
                      m_tableManager.getOperationCodes(),
                      m_ui);

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
    m_firstPass.performFirstPass();
}

void ApplicationWindow::performSecondPass()
{
    std::cerr << "yoo\n";
}
}
