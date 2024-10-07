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

std::vector<AssemblyOperation> TableManager::getAssemblySourceCode() const
{
    const auto* table = m_ui->sourceCodeTable;
    std::vector<AssemblyOperation> sourceCode{};

    for (int row{ 0 }; row < table->rowCount(); ++row)
    {
        QString labelText{ table->item(row, 0)->text() };
        auto label{ labelText.isEmpty()
                    ? std::make_optional(labelText)
                    : std::nullopt };
        QString operation{ table->item(row, 1)->text() };
        QString firstOperand{ table->item(row, 2)->text() };
        QString secondOperandText{ table->item(row, 3)->text() };
        auto secondOperand{ secondOperandText.isEmpty()
                            ? std::make_optional(secondOperandText)
                            : std::nullopt };

        sourceCode.emplace_back(label, operation, firstOperand, secondOperand);
    }

    return sourceCode;
}

std::vector<OperationCode> TableManager::getOperationCodes() const
{
    const auto* table = m_ui->codeOperationTable;
    std::vector<OperationCode> operationCodes{};

    for (int row{ 0 }; row < table->rowCount(); ++row)
    {
        QString label{ table->item(row, 0)->text() };
        QString code{ table->item(row, 1)->text() };
        // maybe throw an exception here in the future
        int size{ table->item(row, 2)->text().toInt() };

        operationCodes.emplace_back(label, code, size);
    }
}
}
