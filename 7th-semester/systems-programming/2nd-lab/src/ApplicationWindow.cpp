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

    m_ui->secondPassButton->setEnabled(false);

    m_ui->sourceCodeTable->setEditTriggers(QAbstractItemView::SelectedClicked);

    connect(m_ui->sourceCodeTable, &QTableWidget::cellClicked, this, [this](int row, int column) {
        m_ui->sourceCodeTable->editItem(m_ui->sourceCodeTable->item(row, column));
        if (QLineEdit* editor = m_ui->sourceCodeTable->findChild<QLineEdit*>()) {
            editor->deselect();
        }
    });

    // put in a function.....
    connect(m_ui->codeOperationTable, &QTableWidget::cellClicked, this, [this](int row, int column) {
        m_ui->codeOperationTable->editItem(m_ui->codeOperationTable->item(row, column));
        if (QLineEdit* editor = m_ui->codeOperationTable->findChild<QLineEdit*>()) {
            editor->deselect();
        }
    });
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

    connect(m_ui->sourceCodeTable, &QTableWidget::cellClicked,
            m_ui->helperTable, &QTableWidget::clear);
    connect(m_ui->sourceCodeTable, &QTableWidget::cellClicked,
            m_ui->binaryCode, &QTableWidget::clear);
    connect(m_ui->sourceCodeTable, &QTableWidget::cellClicked,
            m_ui->symbolicNamesTable, &QTableWidget::clear);
    connect(m_ui->sourceCodeTable, &QTableWidget::cellClicked,
            m_ui->setupTable, &QTableWidget::clear);

    connect(m_ui->codeOperationTable, &QTableWidget::cellClicked,
            m_ui->helperTable, &QTableWidget::clear);
    connect(m_ui->codeOperationTable, &QTableWidget::cellClicked,
            m_ui->binaryCode, &QTableWidget::clear);
    connect(m_ui->codeOperationTable, &QTableWidget::cellClicked,
            m_ui->symbolicNamesTable, &QTableWidget::clear);
    connect(m_ui->codeOperationTable, &QTableWidget::cellClicked,
            m_ui->setupTable, &QTableWidget::clear);

    connect(m_ui->sourceCodeTable, &QTableWidget::cellChanged,
            m_ui->helperTable, &QTableWidget::clear);
    connect(m_ui->sourceCodeTable, &QTableWidget::cellChanged,
            m_ui->binaryCode, &QTableWidget::clear);
    connect(m_ui->sourceCodeTable, &QTableWidget::cellChanged,
            m_ui->symbolicNamesTable, &QTableWidget::clear);

    connect(m_ui->codeOperationTable, &QTableWidget::cellChanged,
            m_ui->helperTable, &QTableWidget::clear);
    connect(m_ui->codeOperationTable, &QTableWidget::cellChanged,
            m_ui->binaryCode, &QTableWidget::clear);
    connect(m_ui->codeOperationTable, &QTableWidget::cellChanged,
            m_ui->symbolicNamesTable, &QTableWidget::clear);
}

void ApplicationWindow::performFirstPass()
{
    m_firstPass.setup(m_tableManager.getAssemblySourceCode(),
                      m_tableManager.getOperationCodes(),
                      m_ui);
    m_lastProgramAddress = m_firstPass.performFirstPass();

    m_ui->secondPassButton->setEnabled(true);
}

void ApplicationWindow::performSecondPass()
{
    m_secondPass.setup(m_tableManager.getSymbolicNames(),
                       m_lastProgramAddress,
                       m_ui);
    m_secondPass.performSecondPass();

    m_ui->secondPassButton->setEnabled(false);
}

void ApplicationWindow::clearHelperTable()
{
    m_ui->helperTable->clear();
}
}
