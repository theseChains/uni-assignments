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
    m_ui->RegistratorTabs->setCurrentIndex(0);
    m_ui->ClientSearchStackedWidget->setCurrentIndex(0);

    m_ui->FoundClientsTable->setHorizontalHeaderLabels(
        QStringList{} << "Фамилия" << "Имя" << "Отчество" << "Дата рождения");

    navigateToPage(constants::kLoginPage);

    QObject::connect(m_ui->LogInButton, &QPushButton::clicked,
                     this, &ApplicationView::onLoginButtonClicked);
    QObject::connect(m_ui->FindClientsButton, &QPushButton::clicked,
                     this, &ApplicationView::onFindClientsButtonClicked);
    QObject::connect(m_ui->BackToSearchButton, &QPushButton::clicked,
                     this, &ApplicationView::onBackToSearchButtonClicked);
}

void ApplicationView::onLoginButtonClicked()
{
    if (loginIsValid())
    {
        navigateToPage(constants::kRegistratorPage);
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

std::vector<std::array<QString, 4>> ApplicationView::findClients()
{
    std::vector<std::array<QString, 4>> clientData{};
    clientData.push_back({ "aaa", "bbb", "ccc", "10.10.1000"});
    clientData.push_back({ "zzz", "mmm", "add", "10.10.2000"});
    clientData.push_back({ "dataaa", "dataa", "data", "10.10.3000"});

    clientData.push_back({ "aaa", "bbb", "ccc", "10.10.1000"});
    clientData.push_back({ "zzz", "mmm", "add", "10.10.2000"});
    clientData.push_back({ "dataaa", "dataa", "data", "10.10.3000"});

    clientData.push_back({ "aaa", "bbb", "ccc", "10.10.1000"});
    clientData.push_back({ "zzz", "mmm", "add", "10.10.2000"});
    clientData.push_back({ "dataaa", "dataa", "data", "10.10.3000"});

    clientData.push_back({ "aaa", "bbb", "ccc", "10.10.1000"});
    clientData.push_back({ "zzz", "mmm", "add", "10.10.2000"});
    clientData.push_back({ "dataaa", "dataa", "data", "10.10.3000"});

    clientData.push_back({ "aaa", "bbb", "ccc", "10.10.1000"});
    clientData.push_back({ "zzz", "mmm", "add", "10.10.2000"});
    clientData.push_back({ "dataaa", "dataa", "data", "10.10.3000"});

    return clientData;
}

void ApplicationView::fillTableWithData(const std::vector<std::array<QString, 4>>& data)
{
    m_ui->FoundClientsTable->setRowCount(data.size());
    m_ui->FoundClientsTable->setColumnCount(4);

    // move this somewhere else?
    int fontSize{ 14 };
    QFont font;
    font.setPointSize(fontSize);

    for (std::size_t i{ 0 }; i < data.size(); ++i)
    {
        for (std::size_t j{ 0 }; j < 4; ++j)
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
        qDebug() << "could not find page " << pageName << '\n';
}

bool ApplicationView::searchStackedWidgetForPage(const QString& pageName,
                                                 QStackedWidget& stackedWidget)
{
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
