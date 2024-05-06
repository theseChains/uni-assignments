#include "ApplicationView.h"
#include "ui_ApplicationViewUi.h"

#include <iostream>

#include <QDebug>
#include <QTableWidget>

#include "ViewConstants.h"

namespace polyclinic
{
ApplicationView::ApplicationView(ApplicationController& controller, QWidget* parent)
    : QMainWindow{ parent },
      m_controller{ controller },
      m_ui{ new Ui::ApplicationViewUi }
{
    m_ui->setupUi(this);
    m_ui->AdministratorTabs->setCurrentIndex(0);
    m_ui->RegistratorTabs->setCurrentIndex(0);
    m_ui->ClientSearchStackedWidget->setCurrentIndex(0);
    m_ui->TalonPageTabs->setCurrentIndex(0);

    m_ui->FoundClientsTable->setHorizontalHeaderLabels(
        QStringList{} << "Фамилия" << "Имя" << "Отчество" << "Дата рождения");
    m_ui->FoundClientsTable->setSelectionMode(QAbstractItemView::SingleSelection);
    m_ui->FoundClientsTable->setSelectionBehavior(QAbstractItemView::SelectRows);

    navigateToPage(constants::kLoginPage);

    QObject::connect(m_ui->LogInButton, &QPushButton::clicked,
                     this, &ApplicationView::onLoginButtonClicked);
    QObject::connect(m_ui->FindClientsButton, &QPushButton::clicked,
                     this, &ApplicationView::onFindClientsButtonClicked);
    QObject::connect(m_ui->BackToSearchButton, &QPushButton::clicked,
                     this, &ApplicationView::onBackToSearchButtonClicked);
    QObject::connect(m_ui->OpenClientInfoButton, &QPushButton::clicked,
                     this, &ApplicationView::onOpenClientInfoButtonClicked);
    QObject::connect(m_ui->BackToClientTableButton, &QPushButton::clicked,
                     this, &ApplicationView::onBackToClientTableButtonClicked);
    QObject::connect(m_ui->ClientPageTalonButton, &QPushButton::clicked,
                     this, &ApplicationView::onClientPageTalonButtonClicked);
    QObject::connect(m_ui->ClientTableTalonButton, &QPushButton::clicked,
                     this, &ApplicationView::onClientTableTalonButtonClicked);
    QObject::connect(m_ui->BackFromTalonButton, &QPushButton::clicked,
                     this, &ApplicationView::onBackFromTalonButtonClicked);
    QObject::connect(m_ui->TalonPageEditScheduleButton, &QPushButton::clicked,
                     this, &ApplicationView::onTalonPageEditScheduleButtonClicked);
    QObject::connect(m_ui->OpenOutpatientCardButton, &QPushButton::clicked,
                     this, &ApplicationView::onOpenOutpatientCardButtonClicked);
}

void ApplicationView::onLoginButtonClicked()
{
    if (loginIsValid())
    {
        navigateToPage(constants::kDoctorPage);
    }
    else
    {
        std::cerr << "invalid login or password\n";
    }
}

void ApplicationView::onBackToSearchButtonClicked()
{
    navigateToPage(constants::kSeachClientsPage);
}

void ApplicationView::onOpenClientInfoButtonClicked()
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

        navigateToPage(constants::kClientInfoPage);
    }
}

void ApplicationView::onBackToClientTableButtonClicked()
{
    navigateToPage(constants::kFoundClientsPage);
}

void ApplicationView::onClientPageTalonButtonClicked()
{
    QString clientData{};

    clientData.append(m_ui->ClientPageLastName->text() + " ");
    clientData.append(m_ui->ClientPageFirstName->text() + " ");
    clientData.append(m_ui->ClientPageMiddleName->text() + " ");
    QDate date{ m_ui->ClientPageDateOfBirth->date() };
    clientData.append(date.toString("dd.MM.yyyy"));

    m_ui->TalonPageClientInfo->setText(clientData);

    m_lastClientStackedWidgetIndex = m_ui->ClientSearchStackedWidget->currentIndex();

    navigateToPage(constants::kTalonPage);
}

void ApplicationView::onClientTableTalonButtonClicked()
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

    navigateToPage(constants::kTalonPage);
}

std::vector<std::array<QString, 4>> ApplicationView::findClients()
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

void ApplicationView::fillTableWithData(const std::vector<std::array<QString, 4>>& data)
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

void ApplicationView::onFindClientsButtonClicked()
{
    std::vector<std::array<QString, 4>> data{ findClients() };
    if (!data.empty())
    {
        fillTableWithData(data);
        navigateToPage(constants::kFoundClientsPage);
    }
    else
    {
        std::cerr << "nothing was found\n";
    }
}

void ApplicationView::onBackFromTalonButtonClicked()
{
    m_ui->ClientSearchStackedWidget->setCurrentIndex(m_lastClientStackedWidgetIndex);
}

void ApplicationView::onTalonPageEditScheduleButtonClicked()
{
    // hmm
    m_ui->RegistratorTabs->setCurrentIndex(2);
}

void ApplicationView::onOpenOutpatientCardButtonClicked()
{
    navigateToPage(constants::kOutpatientCardPage);
}

bool ApplicationView::loginIsValid()
{
    return true;
}

bool ApplicationView::foundClients()
{
    return true;
}

void ApplicationView::navigateToPage(const QString& pageName)
{
    bool foundPage{ false };

    foundPage = searchStackedWidgetForPage(pageName, *m_ui->UserStackedWidget);

    // that's not cool
    if (!foundPage)
        foundPage = searchStackedWidgetForPage(pageName, *m_ui->ClientSearchStackedWidget);

    if (!foundPage)
        foundPage = searchStackedWidgetForPage(pageName, *m_ui->DoctorStackedWidget);

    if (!foundPage)
        qDebug() << "could not find page " << pageName << '\n';
}

bool ApplicationView::searchStackedWidgetForPage(const QString& pageName,
                                                 QStackedWidget& stackedWidget)
{
    // im pretty sure i can just use indices instead of this
    // this is kind of more safe in case i delete some page but idk..
    for (int i{ 0 }; i < stackedWidget.count(); ++i)
    {
        QWidget* foundWidget{ stackedWidget.widget(i) };
        if (foundWidget && foundWidget->objectName() == pageName)
        {
            stackedWidget.setCurrentIndex(i);
            return true;
        }
    }

    return false;
}

ApplicationView::~ApplicationView()
{
    delete m_ui;
}
}
