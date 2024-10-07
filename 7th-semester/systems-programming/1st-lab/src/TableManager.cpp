#include "TableManager.h"

#include "ui_ApplicationUi.h"

#include <QTableWidgetItem>

namespace systems_programming
{
void TableManager::setUi(Ui::ApplicationUi* ui)
{
    m_ui = ui;
}

void TableManager::loadAssemblyToSourceTable()
{
    addRowToSourceTable("PROG", "START", "100");
    addRowToSourceTable("", "JMP", "L1");
    addRowToSourceTable("A1", "RESB", "10");
    addRowToSourceTable("A2", "RESW", "20");
    addRowToSourceTable("B1", "WORD", "40");
    addRowToSourceTable("B2", "BYTE", R"(X"2F4C008A")");
    addRowToSourceTable("B3", "BYTE", R"(C"Hello!")");
    addRowToSourceTable("B4", "BYTE", "12");
    addRowToSourceTable("L1", "LOADR1", "B1");
    addRowToSourceTable("", "LOADR2", "B4");
    addRowToSourceTable("", "ADD", "R1", "R2");
    addRowToSourceTable("", "SAVER1", "B1");
    addRowToSourceTable("", "INT", "200");
    addRowToSourceTable("", "END", "100");
    addRowToSourceTable("", "", "");
    addRowToSourceTable("", "", "");
    addRowToSourceTable("", "", "");
    addRowToSourceTable("", "", "");
    addRowToSourceTable("", "", "");
}

void TableManager::loadCodeOperationTable()
{
    addRowToCodeOperationTable("JMP", "01", "4");
    addRowToCodeOperationTable("LOADR1", "02", "4");
    addRowToCodeOperationTable("LOADR2", "03", "4");
    addRowToCodeOperationTable("ADD", "04", "4");
    addRowToCodeOperationTable("SAVER1", "05", "4");
    addRowToCodeOperationTable("INT", "06", "2");
    addRowToCodeOperationTable("", "", "");
    addRowToCodeOperationTable("", "", "");
    addRowToCodeOperationTable("", "", "");
    addRowToCodeOperationTable("", "", "");
}

// this kinda sucks already
void TableManager::addRowToSourceTable(const QString& first,
                                       const QString& second,
                                       const QString& third,
                                       const QString& fourth)
{
    auto* table = m_ui->sourceCodeTable;
    int row = table->rowCount();
    table->insertRow(row);
    table->setItem(row, 0, new QTableWidgetItem{ first });
    table->setItem(row, 1, new QTableWidgetItem{ second });
    table->setItem(row, 2, new QTableWidgetItem{ third });
    table->setItem(row, 3, new QTableWidgetItem{ fourth });
}

void TableManager::addRowToCodeOperationTable(const QString& name,
                                              const QString& code,
                                              const QString& size)
{
    auto* table = m_ui->codeOperationTable;
    int row = table->rowCount();
    table->insertRow(row);
    table->setItem(row, 0, new QTableWidgetItem{ name });
    table->setItem(row, 1, new QTableWidgetItem{ code });
    table->setItem(row, 2, new QTableWidgetItem{ size });
}
}
