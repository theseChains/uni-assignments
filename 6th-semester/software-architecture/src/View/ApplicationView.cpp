#include "ApplicationView.h"
#include "ui_ApplicationViewUi.h"

#include <iostream>

#include <QDebug>
#include <QTableWidget>

#include "ViewConstants.h"
#include "StackedWidgetNavigator/StackedWidgetNavigator.h"

namespace polyclinic
{
ApplicationView::ApplicationView(ApplicationController& controller, QWidget* parent)
    : QMainWindow{ parent },
      m_controller{ controller },
      m_ui{ new Ui::ApplicationViewUi }
{
    m_ui->setupUi(this);
    m_registratorButtonsHandler.setUi(m_ui);
    m_registratorButtonsHandler.connectButtonsToSlots();
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

    QObject::connect(m_ui->LogInButton, &QPushButton::clicked,
                     this, &ApplicationView::onLoginButtonClicked);
    QObject::connect(m_ui->OpenOutpatientCardButton, &QPushButton::clicked,
                     this, &ApplicationView::onOpenOutpatientCardButtonClicked);

    QObject::connect(&m_controller, &ApplicationController::authenticationSuccess,
                     this, &ApplicationView::onAuthenticationSuccess);
    QObject::connect(&m_controller, &ApplicationController::authenticationFailed,
                     this, &ApplicationView::onAuthenticationFailed);
}

void ApplicationView::onLoginButtonClicked()
{
    m_controller.authenticateUser(
            m_ui->LoginInput->text(), m_ui->PasswordInput->text());
}

void ApplicationView::onAuthenticationSuccess(UserType userType)
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
}

void ApplicationView::onAuthenticationFailed()
{
    // todo: output a message in the app about this
    std::cerr << "invalid login or password\n";
}

void ApplicationView::onOpenOutpatientCardButtonClicked()
{
    navigateToPage(constants::kOutpatientCardPage);
}

bool ApplicationView::foundClients()
{
    return true;
}

ApplicationView::~ApplicationView()
{
    delete m_ui;
}
}
