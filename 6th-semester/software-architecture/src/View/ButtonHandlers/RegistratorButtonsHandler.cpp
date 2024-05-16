#include "RegistratorButtonsHandler.h"
#include "../ui_ApplicationViewUi.h"
#include "View/ViewConstants.h"
#include "View/StackedWidgetNavigator/StackedWidgetNavigator.h"

#include <QPushButton>
#include <iostream>

namespace polyclinic
{
void RegistratorButtonsHandler::setUi(Ui::ApplicationViewUi* ui)
{
    m_ui = ui;
}

void RegistratorButtonsHandler::connectButtonsToSlots()
{
    QObject::connect(m_ui->OpenClientInfoButton, &QPushButton::clicked,
            this, &RegistratorButtonsHandler::onOpenClientInfoButtonClicked);
    QObject::connect(m_ui->FindClientsButton, &QPushButton::clicked,
            this, &RegistratorButtonsHandler::onFindClientsButtonClicked);
    QObject::connect(m_ui->BackToSearchButton, &QPushButton::clicked,
            this, &RegistratorButtonsHandler::onBackToSearchButtonClicked);
    QObject::connect(m_ui->BackToClientTableButton, &QPushButton::clicked,
            this, &RegistratorButtonsHandler::onBackToClientTableButtonClicked);
    QObject::connect(m_ui->ClientPageTalonButton, &QPushButton::clicked,
            this, &RegistratorButtonsHandler::onClientPageTalonButtonClicked);
    QObject::connect(m_ui->ClientTableTalonButton, &QPushButton::clicked,
            this, &RegistratorButtonsHandler::onClientTableTalonButtonClicked);
    QObject::connect(m_ui->BackFromTalonButton, &QPushButton::clicked,
            this, &RegistratorButtonsHandler::onBackFromTalonButtonClicked);
    QObject::connect(m_ui->TalonPageEditScheduleButton, &QPushButton::clicked,
            this, &RegistratorButtonsHandler::onTalonPageEditScheduleButtonClicked);
}

void RegistratorButtonsHandler::onOpenClientInfoButtonClicked()
{
    int selectedRow{ m_ui->FoundClientsTable->currentRow() };
    // it always chooses the first one if there is no choice
    // look into that if you have time
    if (selectedRow != -1)
    {
        // should really create a struct for this short kind of data
        std::array<QString, 4> clientData{};
        for (int col{ 0 }; col < m_ui->FoundClientsTable->columnCount(); ++col)
        {
            QTableWidgetItem *item{
                m_ui->FoundClientsTable->item(selectedRow, col) };
            clientData[col] = item->text();
        }

        // then we also fetch full data based on this client data from the table
        // cause we'll need it anyways
        // so if we have 2 clients with the same data.. well.. too bad xd

        m_ui->ClientPageLastName->setText(clientData[0]);
        m_ui->ClientPageFirstName->setText(clientData[1]);
        m_ui->ClientPageMiddleName->setText(clientData[2]);
        QStringList dateParts{ clientData[3].split('.') };
        QDate date{ dateParts[2].toInt(), dateParts[1].toInt(), dateParts[0].toInt() };
        // this should honeslty already be a QDate
        m_ui->ClientPageDateOfBirth->setDate(date);

        StackedWidgetNavigator::StackedWidgetNavigator::navigateToPage(*m_ui->ClientSearchStackedWidget, constants::kClientInfoPage);
    }
}

void RegistratorButtonsHandler::onBackToSearchButtonClicked()
{
    StackedWidgetNavigator::navigateToPage(*m_ui->ClientSearchStackedWidget, constants::kSeachClientsPage);
}

void RegistratorButtonsHandler::onBackToClientTableButtonClicked()
{
    StackedWidgetNavigator::navigateToPage(*m_ui->ClientSearchStackedWidget, constants::kFoundClientsPage);
}

void RegistratorButtonsHandler::onClientPageTalonButtonClicked()
{
    QString clientData{};

    clientData.append(m_ui->ClientPageLastName->text() + " ");
    clientData.append(m_ui->ClientPageFirstName->text() + " ");
    clientData.append(m_ui->ClientPageMiddleName->text() + " ");
    QDate date{ m_ui->ClientPageDateOfBirth->date() };
    clientData.append(date.toString("dd.MM.yyyy"));

    m_ui->TalonPageClientInfo->setText(clientData);

    m_lastClientStackedWidgetIndex = m_ui->ClientSearchStackedWidget->currentIndex();

    StackedWidgetNavigator::navigateToPage(*m_ui->ClientSearchStackedWidget, constants::kTalonPage);
}

void RegistratorButtonsHandler::onClientTableTalonButtonClicked()
{
    int selectedRow{ m_ui->FoundClientsTable->currentRow() };
    QString clientData{};
    for (int col{ 0 }; col < m_ui->FoundClientsTable->columnCount(); ++col)
    {
        QTableWidgetItem *item{ m_ui->FoundClientsTable->item(selectedRow, col) };
        clientData.append(item->text());
        clientData.append(" ");
    }

    m_ui->TalonPageClientInfo->setText(clientData);

    m_lastClientStackedWidgetIndex = m_ui->ClientSearchStackedWidget->currentIndex();

    StackedWidgetNavigator::navigateToPage(*m_ui->ClientSearchStackedWidget, constants::kTalonPage);
}

std::vector<std::array<QString, 4>> RegistratorButtonsHandler::findClients()
{
    std::vector<std::array<QString, 4>> clientData{};
    clientData.push_back({ "aaa", "bbb", "ccc", "10.10.1000"});
    clientData.push_back({ "zzz", "mmm", "add", "10.10.2000"});
    clientData.push_back({ "dataaa", "dataa", "data", "10.10.3000"});

    clientData.push_back({ "baa", "bba", "cac", "10.20.1000"});
    clientData.push_back({ "kkzzz", "mmm", "add", "10.30.2000"});
    clientData.push_back({ "kkdataaa", "dataa", "data", "10.40.3000"});

    clientData.push_back({ "llaaa", "bbb", "ccc", "10.50.1000"});
    clientData.push_back({ "llzzz", "mmm", "add", "10.60.2000"});
    clientData.push_back({ "lldataaa", "dataa", "data", "40.10.3000"});

    clientData.push_back({ "lllaaa", "bbb", "ccc", "30.10.1000"});
    clientData.push_back({ "lllzzz", "mmm", "add", "30.10.2000"});
    clientData.push_back({ "llldataaa", "dataa", "data", "80.10.3000"});

    clientData.push_back({ "aaaa", "bbb", "ccc", "10.10.8000"});
    clientData.push_back({ "azzz", "mmm", "add", "10.10.8000"});
    clientData.push_back({ "adataaa", "dataa", "data", "10.10.3000"});

    return clientData;
}

void RegistratorButtonsHandler::fillTableWithData(const std::vector<std::array<QString, 4>>& data)
{
    m_ui->FoundClientsTable->setRowCount(data.size());
    m_ui->FoundClientsTable->setColumnCount(constants::kNumberOfClientsTableColumns);

    // move this somewhere else?
    int fontSize{ 14 };
    QFont font;
    font.setPointSize(fontSize);

    for (std::size_t i{ 0 }; i < data.size(); ++i)
    {
        for (std::size_t j{ 0 }; j < constants::kNumberOfClientsTableColumns; ++j)
        {
            QTableWidgetItem *item{};
            if (m_ui->FoundClientsTable->item(i, j))
            {
                item = m_ui->FoundClientsTable->item(i, j);
            }
            else
            {
                item = new QTableWidgetItem{};
                m_ui->FoundClientsTable->setItem(i, j, item);
            }
            item->setFlags(item->flags() & ~Qt::ItemIsEditable);
            item->setText(data[i][j]);
            item->setFont(font);
        }
    }
}

void RegistratorButtonsHandler::onFindClientsButtonClicked()
{
    std::vector<std::array<QString, 4>> data{ findClients() };
    if (!data.empty())
    {
        fillTableWithData(data);
        StackedWidgetNavigator::navigateToPage(*m_ui->ClientSearchStackedWidget, constants::kFoundClientsPage);
    }
    else
    {
        std::cerr << "nothing was found\n";
    }
}

void RegistratorButtonsHandler::onBackFromTalonButtonClicked()
{
    m_ui->ClientSearchStackedWidget->setCurrentIndex(m_lastClientStackedWidgetIndex);
}

void RegistratorButtonsHandler::onTalonPageEditScheduleButtonClicked()
{
    // hmm
    m_ui->RegistratorTabs->setCurrentIndex(2);
}
}
