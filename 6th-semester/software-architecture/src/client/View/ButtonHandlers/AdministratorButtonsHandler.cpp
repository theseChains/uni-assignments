#include "AdministratorButtonsHandler.h"
#include "../ui_ApplicationViewUi.h"

#include "common/data/DoctorData.h"
#include "common/data/RegistratorData.h"
#include "client/View/ButtonHandlers/AddSlotDialog.h"

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
    connect(m_client, &Client::getRegistratorsResult,
            this, &AdministratorButtonsHandler::onGetRegistratorsResult);
    connect(m_client, &Client::getDoctorsResult,
            this, &AdministratorButtonsHandler::onGetDoctorsResult);
    connect(m_client, &Client::deleteRegistratorResult,
            this, &AdministratorButtonsHandler::onDeleteRegistratorResult);
    connect(m_client, &Client::deleteDoctorResult,
            this, &AdministratorButtonsHandler::onDeleteDoctorResult);
    connect(m_client, &Client::getDoctorSlotsResult,
            this, &AdministratorButtonsHandler::onGetDoctorSlotsResultScheduleEdit);
    connect(m_client, &Client::getDoctorsBySpecializationResult,
            this, &AdministratorButtonsHandler::onGetDoctorsBySpecializationResult);

    connect(m_client, &Client::deleteSlotResult,
            this, &AdministratorButtonsHandler::onDeleteSlotResult);
    connect(m_client, &Client::deleteDayOfSlotsResult,
            this, &AdministratorButtonsHandler::onDeleteDayOfSlotsResult);
    connect(m_client, &Client::addSlotResult,
            this, &AdministratorButtonsHandler::onAddSlotResult);
    connect(m_client, &Client::addDayOfSlotsResult,
            this, &AdministratorButtonsHandler::onAddDayOfSlotsResult);
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
    connect(m_ui->SearchRegistratorsButton, &QPushButton::clicked,
            this, &AdministratorButtonsHandler::onSearchRegistratorsButtonClicked);
    connect(m_ui->SearchDoctorsButton, &QPushButton::clicked,
            this, &AdministratorButtonsHandler::onSearchDoctorsButtonClicked);
    connect(m_ui->DeleteRegistratorButton, &QPushButton::clicked,
            this, &AdministratorButtonsHandler::onDeleteRegistratorButtonClicked);
    connect(m_ui->DeleteDoctorButton, &QPushButton::clicked,
            this, &AdministratorButtonsHandler::onDeleteDoctorButtonClicked);

    connect(m_ui->AdminScheduleEditLastName,
            QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &AdministratorButtonsHandler::onDoctorOrDateChangedScheduleEdit);
    connect(m_ui->AdminScheduleEditDate, &QDateEdit::dateChanged,
            this, &AdministratorButtonsHandler::onDoctorOrDateChangedScheduleEdit);

    connect(m_ui->AdminScheduleEditSpecialization,
            QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &AdministratorButtonsHandler::onSpecializationChanged);

    connect(m_ui->AdminScheduleEditDeleteChosen, &QPushButton::clicked,
            this, &AdministratorButtonsHandler::onDeleteSlotButtonClicked);
    connect(m_ui->AdminScheduleEditDeleteDay, &QPushButton::clicked,
            this, &AdministratorButtonsHandler::onDeleteDayOfSlotsButtonClicked);
    connect(m_ui->AdminScheduleEditAddDay, &QPushButton::clicked,
            this, &AdministratorButtonsHandler::onAddDayOfSlotsButtonClicked);
    connect(m_ui->AdminScheduleEditAddSlot, &QPushButton::clicked,
            this, &AdministratorButtonsHandler::onAddSlotButtonClicked);
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
        QMessageBox::information(nullptr, "Success", "Регистратор успешно зарегистрирован.");
    } else {
        QMessageBox::critical(nullptr, "Error", "Не удалось добавить регистратора в базу данных.");
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
        QMessageBox::information(nullptr, "Success", "Врач успешно зарегистрирован.");
    } else {
        QMessageBox::critical(nullptr, "Error", "Не удалось добавить врача в базу данных.");
    }
}

void AdministratorButtonsHandler::onSearchRegistratorsButtonClicked()
{
    RegistratorData data{};
    data.lastName = m_ui->RegistratorSearchLastName->text();
    data.firstName = m_ui->RegistratorSearchFirstName->text();
    data.middleName = m_ui->RegistratorSearchMiddleName->text();

    m_client->sendGetRegistratorsRequest(data);
}

void AdministratorButtonsHandler::onGetRegistratorsResult(const std::vector<RegistratorData>& data)
{
    m_ui->RegistratorsTable->clearContents();
    m_ui->RegistratorsTable->setRowCount(data.size());
    m_ui->RegistratorsTable->setColumnCount(4);

    m_ui->RegistratorsTable->setHorizontalHeaderLabels(
            { "ID", "Фамилия", "Имя", "Отчество" });

    int fontSize{ 14 };
    QFont font{};
    font.setPointSize(fontSize);

    for (std::size_t i{ 0 }; i < data.size(); ++i)
    {
        // why an auto& here.. god knows
        const auto& registrator = data[i];
        const QStringList rowData{
            QString::number(registrator.id),
            registrator.lastName,
            registrator.firstName,
            registrator.middleName
        };

        for (std::size_t j{ 0 }; j < 4; ++j)
        {
            QTableWidgetItem* item{ new QTableWidgetItem(rowData[j]) };
            item->setFlags(item->flags() & ~Qt::ItemIsEditable);
            item->setFont(font);
            m_ui->RegistratorsTable->setItem(i, j, item);
        }
    }

    m_ui->RegistratorsTable->hideColumn(0);
}

void AdministratorButtonsHandler::onSearchDoctorsButtonClicked()
{
    DoctorData data{};
    data.lastName = m_ui->DoctorSearchLastName->text();
    data.firstName = m_ui->DoctorSearchFirstName->text();
    data.middleName = m_ui->DoctorSearchMiddleName->text();

    m_client->sendGetDoctorsRequest(data);
}

void AdministratorButtonsHandler::onGetDoctorsResult(const std::vector<DoctorData>& data)
{
    m_ui->DoctorsTable->clearContents();
    m_ui->DoctorsTable->setRowCount(data.size());
    m_ui->DoctorsTable->setColumnCount(4);

    m_ui->DoctorsTable->setHorizontalHeaderLabels(
            { "ID", "Фамилия", "Имя", "Отчество" });

    int fontSize{ 14 };
    QFont font{};
    font.setPointSize(fontSize);

    for (std::size_t i{ 0 }; i < data.size(); ++i)
    {
        // why an auto& here.. god knows
        const auto& doctor = data[i];
        const QStringList rowData{
            QString::number(doctor.id),
            doctor.lastName,
            doctor.firstName,
            doctor.middleName
        };

        for (std::size_t j{ 0 }; j < 4; ++j)
        {
            QTableWidgetItem* item{ new QTableWidgetItem(rowData[j]) };
            item->setFlags(item->flags() & ~Qt::ItemIsEditable);
            item->setFont(font);
            m_ui->DoctorsTable->setItem(i, j, item);
        }
    }

    m_ui->DoctorsTable->hideColumn(0);
}

void AdministratorButtonsHandler::onDeleteRegistratorButtonClicked()
{
    int selectedRow{ m_ui->RegistratorsTable->currentRow() };
    int registratorId{ m_ui->RegistratorsTable->item(selectedRow, 0)->text().toInt() };

    m_client->sendDeleteRegistratorRequest(registratorId);
}

void AdministratorButtonsHandler::onDeleteRegistratorResult(bool success)
{
    if (success) {
        QMessageBox::information(nullptr, "Success", "Регистратор удалён.");
    } else {
        QMessageBox::critical(nullptr, "Error", "Не удалось удалить регистратора.");
    }
}

void AdministratorButtonsHandler::onDeleteDoctorButtonClicked()
{
    int selectedRow{ m_ui->DoctorsTable->currentRow() };
    int doctorId{ m_ui->DoctorsTable->item(selectedRow, 0)->text().toInt() };

    m_client->sendDeleteDoctorRequest(doctorId);
}

void AdministratorButtonsHandler::onDeleteDoctorResult(bool success)
{
    if (success) {
        QMessageBox::information(nullptr, "Success", "Врач удалён.");
    } else {
        QMessageBox::critical(nullptr, "Error", "Не удалось удалить врача.");
    }
}

void AdministratorButtonsHandler::onSpecializationChanged()
{
    QString specialization{
            m_ui->AdminScheduleEditSpecialization->currentText() };
    m_client->sendGetDoctorsBySpecializationRequest(specialization);
}

void AdministratorButtonsHandler::onGetDoctorsBySpecializationResult(const std::vector<DoctorScheduleData>& data)
{
    for (const auto& doctor : data)
    {
        m_ui->AdminScheduleEditLastName->addItem(doctor.lastName, doctor.id);
    }
}

void AdministratorButtonsHandler::onDoctorOrDateChangedScheduleEdit()
{
    QVariant doctorIdVariant{ m_ui->AdminScheduleEditLastName->currentData() };

    if (doctorIdVariant.isValid())
    {
        int doctorId{ doctorIdVariant.toInt() };
        QDate date{ m_ui->AdminScheduleEditDate->date() };
        m_client->sendGetDoctorSlotsRequest(doctorId, date);
    }
}

void AdministratorButtonsHandler::onGetDoctorSlotsResultScheduleEdit(const std::vector<DoctorSlotData>& data)
{
    m_ui->AdminScheduleEditTable->clearContents();
    m_ui->AdminScheduleEditTable->setRowCount(data.size());
    m_ui->AdminScheduleEditTable->setColumnCount(4);

    m_ui->AdminScheduleEditTable->setHorizontalHeaderLabels(
            { "ID", "Начало", "Конец", "Статус" });

    // move this somewhere else?
    int fontSize{ 14 };
    QFont font{};
    font.setPointSize(fontSize);

    for (std::size_t i{ 0 }; i < data.size(); ++i)
    {
        // why an auto& here.. god knows
        const auto& slot = data[i];
        const QStringList rowData{
            QString::number(slot.id),
            slot.startTime.toString("hh:mm"),
            slot.endTime.toString("hh:mm"),
            slot.status
        };

        for (std::size_t j{ 0 }; j < 4; ++j)
        {
            QTableWidgetItem* item{ new QTableWidgetItem(rowData[j]) };
            item->setFlags(item->flags() & ~Qt::ItemIsEditable);
            item->setFont(font);
            m_ui->AdminScheduleEditTable->setItem(i, j, item);
        }
    }

    m_ui->AdminScheduleEditTable->hideColumn(0);
}

void AdministratorButtonsHandler::onDeleteSlotButtonClicked()
{
    int selectedRow{ m_ui->AdminScheduleEditTable->currentRow() };

    if (selectedRow != -1)
    {
        int slotId{ m_ui->AdminScheduleEditTable->item(selectedRow, 0)->text().toInt() };
        m_client->sendDeleteSlotRequest(slotId);
    }
}

void AdministratorButtonsHandler::onDeleteSlotResult(bool success)
{
    if (!success)
    {
        QMessageBox::critical(nullptr, "Error", "Ошибка при удалении слота");
    }
    else
    {
        onDoctorOrDateChangedScheduleEdit();
    }
}

void AdministratorButtonsHandler::onDeleteDayOfSlotsButtonClicked()
{
    QVariant doctorIdVariant{ m_ui->AdminScheduleEditLastName->currentData() };

    if (doctorIdVariant.isValid())
    {
        int doctorId{ doctorIdVariant.toInt() };
        QDate date{ m_ui->AdminScheduleEditDate->date() };
        m_client->sendDeleteDayOfSlotsRequest(doctorId, date);
    }
    else
    {
        QMessageBox::critical(nullptr, "Error", "Ошибка в получении данных");
    }
}

void AdministratorButtonsHandler::onDeleteDayOfSlotsResult(bool success)
{
    if (!success)
    {
        QMessageBox::critical(nullptr, "Error", "Ошибка при удалении слотов");
    }
    else
    {
        onDoctorOrDateChangedScheduleEdit();
    }
}

void AdministratorButtonsHandler::onAddSlotButtonClicked()
{
    QVariant doctorIdVariant{ m_ui->AdminScheduleEditLastName->currentData() };

    if (doctorIdVariant.isValid()) {
        int doctorId{ doctorIdVariant.toInt() };
        QDate date{ m_ui->AdminScheduleEditDate->date() };

        AddSlotDialog dialog{};
        if (dialog.exec() == QDialog::Accepted) {
            QTime startTime{ dialog.selectedTime() };
            m_client->sendAddSlotRequest(doctorId, date, startTime);
        }
    } else {
        QMessageBox::critical(nullptr, "Error", "Ошибка в получении данных");
    }
}

void AdministratorButtonsHandler::onAddSlotResult(bool success)
{
    if (!success)
    {
        QMessageBox::critical(nullptr, "Error", "Ошибка при добавлении слота");
    }
    else
    {
        onDoctorOrDateChangedScheduleEdit();
    }
}

void AdministratorButtonsHandler::onAddDayOfSlotsButtonClicked()
{
    QVariant doctorIdVariant{ m_ui->AdminScheduleEditLastName->currentData() };

    if (doctorIdVariant.isValid())
    {
        int doctorId{ doctorIdVariant.toInt() };
        QDate date{ m_ui->AdminScheduleEditDate->date() };
        m_client->sendAddDayOfSlotsRequest(doctorId, date);
    }
    else
    {
        QMessageBox::critical(nullptr, "Error", "Ошибка в получении данных");
    }
}

void AdministratorButtonsHandler::onAddDayOfSlotsResult(bool success)
{
    if (!success)
    {
        QMessageBox::critical(nullptr, "Error", "Ошибка при добавлении слотов");
    }
    else
    {
        onDoctorOrDateChangedScheduleEdit();
    }
}
}
