#include "TableManager.h"

#include "ui_ApplicationUi.h"

#include <QTableWidgetItem>
#include <QDebug>

#include <optional>

namespace systems_programming
{
void TableManager::setUi(Ui::ApplicationUi* ui)
{
    m_ui = ui;
}

void TableManager::loadAssemblyToSourceTable()
{
    auto* table = m_ui->sourceCodeTable;

    addRowToTable(table, { "PROG", "START", "0" });
    addRowToTable(table, { "", "JMP", "[L1]" });
    addRowToTable(table, { "A1", "RESB", "10" });
    addRowToTable(table, { "A2", "RESW", "20" });
    addRowToTable(table, { "B1", "WORD", "40" });
    addRowToTable(table, { "B2", "BYTE", R"(X"2F4C008A")" });
    addRowToTable(table, { "B3", "BYTE", R"(C"Hello!")" });
    addRowToTable(table, { "B4", "BYTE", "12" });
    addRowToTable(table, { "L1", "LOADR1", "B1" });
    addRowToTable(table, { "", "LOADR2", "B4" });
    addRowToTable(table, { "", "ADD", "R1", "R2" });
    addRowToTable(table, { "", "SAVER1", "B1" });
    addRowToTable(table, { "", "END", "10" });
    addRowToTable(table, { "", "", "" });
    addRowToTable(table, { "", "", "" });
    addRowToTable(table, { "", "", "" });
}

void TableManager::loadCodeOperationTable()
{
    auto* table = m_ui->codeOperationTable;

    addRowToTable(table, { "JMP", "01", "4" });
    addRowToTable(table, { "LOADR1", "02", "4" });
    addRowToTable(table, { "LOADR2", "03", "4" });
    addRowToTable(table, { "ADD", "04", "2" });
    addRowToTable(table, { "SAVER1", "05", "4" });
    addRowToTable(table, { "", "", "" });
    addRowToTable(table, { "", "", "" });
}

void TableManager::addRowToTable(QTableWidget* table,
                                 const std::vector<QString>& values)
{
    int row = table->rowCount();
    table->insertRow(row);

    for (int column{ 0 }; column < table->columnCount(); ++column)
    {
        if (column >= static_cast<int>(values.size()))
        {
            table->setItem(row, column, new QTableWidgetItem{ "" });
        }
        else
        {
            table->setItem(row, column, new QTableWidgetItem{ values.at(column) });
        }
    }
}

std::vector<AssemblyOperation> TableManager::getAssemblySourceCode() const
{
    const auto* table = m_ui->sourceCodeTable;
    std::vector<AssemblyOperation> sourceCode{};

    for (int row{ 0 }; row < table->rowCount(); ++row)
    {
        QString labelText{ table->item(row, 0)->text() };
        auto label{ !labelText.isEmpty()
                    ? std::make_optional(labelText)
                    : std::nullopt };
        QString operation{ table->item(row, 1)->text().toUpper() };
        QString firstOperand{ table->item(row, 2)->text() };
        QString secondOperandText{ table->item(row, 3)->text() };
        auto secondOperand{ !secondOperandText.isEmpty()
                            ? std::make_optional(secondOperandText)
                            : std::nullopt };

        /* if (labelText.isEmpty() && operation.isEmpty() && firstOperand.isEmpty() && secondOperandText.isEmpty()) */
        /* { */
        /*     continue; */
        /* } */

        sourceCode.emplace_back(label, operation, firstOperand, secondOperand);
    }

    return sourceCode;
}

QMap<QString, OperationInfo> TableManager::getOperationCodes() const
{
    const auto* table = m_ui->codeOperationTable;
    QMap<QString, OperationInfo> operationCodes{};

    for (int row{ 0 }; row < table->rowCount(); ++row)
    {
        QString label{ table->item(row, 0)->text() };
        QString code{ table->item(row, 1)->text() };
        // maybe throw an exception here in the future
        int size{ table->item(row, 2)->text().toInt() };

        operationCodes[label] = { code, size };
    }

    return operationCodes;
}

QMap<QString, int> TableManager::getSymbolicNames() const
{
    const auto* table = m_ui->symbolicNamesTable;
    QMap<QString, int> symbolicNames{};

    for (int row{ 0 }; row < table->rowCount(); ++row)
    {
        QString name{ table->item(row, 0)->text() };
        int address{ table->item(row, 1)->text().toInt(nullptr, 16) };

        symbolicNames[name] = address;
    }

    return symbolicNames;
}
}
