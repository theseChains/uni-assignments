#include "ApplicationView.h"
#include "ui_ApplicationViewUi.h"

#include <iostream>

#include <QDebug>
#include <QTableWidget>
#include <QMessageBox>

#include "ViewConstants.h"
#include "StackedWidgetNavigator/StackedWidgetNavigator.h"

namespace polyclinic
{
ApplicationView::ApplicationView(QWidget* parent)
    : QMainWindow{ parent },
      m_ui{ new Ui::ApplicationViewUi },
      m_client{ new Client{ this } },
      m_registratorButtonsHandler{ m_client },
      m_validatorSetup{ this }
{
    m_ui->setupUi(this);
    m_registratorButtonsHandler.setUi(m_ui);
    m_registratorButtonsHandler.connectButtonsToSlots();

    m_validatorSetup.setupValidators(*m_ui);

    m_ui->AdministratorTabs->setCurrentIndex(0);
    m_ui->RegistratorTabs->setCurrentIndex(0);
    m_ui->ClientSearchStackedWidget->setCurrentIndex(0);
    m_ui->DoctorStackedWidget->setCurrentIndex(0);
    m_ui->TalonPageTabs->setCurrentIndex(0);

    m_ui->FoundClientsTable->setHorizontalHeaderLabels(
        QStringList{} << "Фамилия" << "Имя" << "Отчество" << "Дата рождения");
    m_ui->FoundClientsTable->setSelectionMode(QAbstractItemView::SingleSelection);
    m_ui->FoundClientsTable->setSelectionBehavior(QAbstractItemView::SelectRows);

    StackedWidgetNavigator::navigateToPage(*m_ui->UserStackedWidget, constants::kLoginPage);

    // qobject here or not?
    QObject::connect(m_ui->LogInButton, &QPushButton::clicked,
                     this, &ApplicationView::onLoginButtonClicked);
    QObject::connect(m_ui->OpenOutpatientCardButton, &QPushButton::clicked,
                     this, &ApplicationView::onOpenOutpatientCardButtonClicked);

    connect(&m_registratorButtonsHandler, &RegistratorButtonsHandler::errorOccurred,
            this, &ApplicationView::displayErrorMessage);

    m_client->connectToServer();
    connect(m_client, &Client::loginResult,
            this, &ApplicationView::onAuthentication);
}

void ApplicationView::onLoginButtonClicked()
{
    LoginInputData inputData{};
    inputData.username = m_ui->LoginInput->text();
    inputData.password = m_ui->PasswordInput->text();

    m_client->sendLoginRequest(inputData);
}

void ApplicationView::onAuthentication(UserType userType)
{
    if (userType == UserType::kAdministrator)
    {
        StackedWidgetNavigator::navigateToPage(*m_ui->UserStackedWidget, constants::kAdministratorPage);
    }
    else if (userType == UserType::kDoctor)
    {
        StackedWidgetNavigator::navigateToPage(*m_ui->UserStackedWidget, constants::kDoctorPage);
    }
    else if (userType == UserType::kRegistrator)
    {
        StackedWidgetNavigator::navigateToPage(*m_ui->UserStackedWidget, constants::kRegistratorPage);
    }
    else
    {
        QMessageBox::critical(this, "Ошибка", "Неправильный логин или пароль.");
    }
}

void ApplicationView::displayErrorMessage(const QString& message)
{
    QMessageBox::critical(this, "Ошибка", message);
}

void ApplicationView::onOpenOutpatientCardButtonClicked()
{
    /* navigateToPage(constants::kOutpatientCardPage); */
}

ApplicationView::~ApplicationView()
{
    delete m_ui;
}
}
