#include "AdministratorButtonsHandler.h"
#include "../ui_ApplicationViewUi.h"

#include "common/data/DoctorData.h"
#include "common/data/RegistratorData.h"

#include <QPushButton>
#include <QMessageBox>

namespace polyclinic
{
AdministratorButtonsHandler::AdministratorButtonsHandler(Client* client, QObject* parent)
    : QObject{ parent }, m_client{ client }
{
    connect(m_client, &Client::addRegistratorResult,
            this, &AdministratorButtonsHandler::onRegistratorRegistrationResult);
    connect(m_client, &Client::addDoctorResult,
            this, &AdministratorButtonsHandler::onDoctorRegistrationResult);
}

void AdministratorButtonsHandler::setUi(Ui::ApplicationViewUi* ui)
{
    m_ui = ui;
}

void AdministratorButtonsHandler::connectButtonsToSlots()
{
    connect(m_ui->RegisterRegistratorButton, &QPushButton::clicked,
            this, &AdministratorButtonsHandler::onRegisterRegistratorButtonClicked);
    connect(m_ui->RegisterDoctorButton, &QPushButton::clicked,
            this, &AdministratorButtonsHandler::onRegisterDoctorButtonClicked);
}

void AdministratorButtonsHandler::onRegisterRegistratorButtonClicked()
{
    RegistratorData data{};
    data.login = m_ui->RegistratorRegLogin->text();
    data.password = m_ui->RegistratorRegPassword->text();
    data.lastName = m_ui->RegistratorRegLastName->text();
    data.firstName = m_ui->RegistratorRegFirstName->text();
    data.middleName = m_ui->RegistratorRegMiddleName->text();
    data.phoneNumber = m_ui->RegistratorRegPhoneNumber->text();

    m_client->sendAddRegistratorRequest(data);
}

void AdministratorButtonsHandler::onRegistratorRegistrationResult(bool success)
{
    if (success) {
        QMessageBox::information(nullptr, "Success", "Пациент успешно зарегистрирован.");
    } else {
        QMessageBox::critical(nullptr, "Error", "Не удалось добавить пациента в базу данных.");
    }
}

void AdministratorButtonsHandler::onRegisterDoctorButtonClicked()
{
    DoctorData data{};
    data.login = m_ui->DoctorRegLogin->text();
    data.password = m_ui->DoctorRegPassword->text();
    data.lastName = m_ui->DoctorRegLastName->text();
    data.firstName = m_ui->DoctorRegFirstName->text();
    data.middleName = m_ui->DoctorRegMiddleName->text();
    data.phoneNumber = m_ui->DoctorRegPhoneNumber->text();
    data.specialization = m_ui->DoctorRegSpecialization->currentText();
    data.cabinetNumber = m_ui->DoctorRegCabinetNumber->text().toInt();

    m_client->sendAddDoctorRequest(data);
}

void AdministratorButtonsHandler::onDoctorRegistrationResult(bool success)
{
    if (success) {
        QMessageBox::information(nullptr, "Success", "Пациент успешно зарегистрирован.");
    } else {
        QMessageBox::critical(nullptr, "Error", "Не удалось добавить пациента в базу данных.");
    }
}
}
