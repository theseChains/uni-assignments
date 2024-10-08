#include "RegistratorButtonsHandler.h"
#include "../ui_ApplicationViewUi.h"
#include "client/View/ViewConstants.h"
#include "client/View/StackedWidgetNavigator/StackedWidgetNavigator.h"
#include "client/View/InputValidator.h"
#include "common/data/PatientData.h"
#include "common/data/PatientSearchData.h"
#include "client/View/ButtonHandlers/AddSlotDialog.h"

#include <QPushButton>
#include <QMessageBox>
#include <iostream>

namespace polyclinic
{
RegistratorButtonsHandler::RegistratorButtonsHandler(Client* client, QObject* parent)
    : QObject{ parent }, m_client{ client }
{
    connect(m_client, &Client::patientRegistrationResult,
            this, &RegistratorButtonsHandler::onPatientRegistration);
    connect(m_client, &Client::getAllPatientsBriefDataResult,
            this, &RegistratorButtonsHandler::onGetAllPatientBriefDataResult);
    connect(m_client, &Client::getPatientBriefDataResult,
            this, &RegistratorButtonsHandler::onGetPatientsBriefDataResult);
    connect(m_client, &Client::getPatientInfoResult,
            this, &RegistratorButtonsHandler::onPatientInfoResult);
    connect(m_client, &Client::updatePatientInfoResult,
            this, &RegistratorButtonsHandler::onUpdatePatientInfoResult);
    connect(m_client, &Client::getDoctorsBySpecializationResult,
            this, &RegistratorButtonsHandler::onGetDoctorsBySpecializationResult);
    // this aint it i feel like..
    connect(m_client, &Client::getDoctorSlotsResult,
            this, &RegistratorButtonsHandler::onGetDoctorSlotsResultScheduleEdit);
    connect(m_client, &Client::getDoctorSlotsResult,
            this, &RegistratorButtonsHandler::onGetDoctorSlotsResultTalon);

    connect(m_client, &Client::deleteSlotResult,
            this, &RegistratorButtonsHandler::onDeleteSlotResult);
    connect(m_client, &Client::deleteDayOfSlotsResult,
            this, &RegistratorButtonsHandler::onDeleteDayOfSlotsResult);
    connect(m_client, &Client::addSlotResult,
            this, &RegistratorButtonsHandler::onAddSlotResult);
    connect(m_client, &Client::addDayOfSlotsResult,
            this, &RegistratorButtonsHandler::onAddDayOfSlotsResult);
    connect(m_client, &Client::addAppointmentResult,
            this, &RegistratorButtonsHandler::onGetAppointmentResult);
}

void RegistratorButtonsHandler::setUi(Ui::ApplicationViewUi* ui)
{
    m_ui = ui;

    m_specializationComboBoxes.append(m_ui->ScheduleEditDoctorSpecialization);
    m_specializationComboBoxes.append(m_ui->PatientTalonDoctorSpecialization);

    for (QComboBox* comboBox : m_specializationComboBoxes)
    {
        connect(comboBox, &QComboBox::currentTextChanged,
                this, &RegistratorButtonsHandler::onSpecializationChanged);
    }

    m_specializationToDoctorMap[m_ui->ScheduleEditDoctorSpecialization]
        .append(m_ui->ScheduleEditDoctorLastName);
    m_specializationToDoctorMap[m_ui->PatientTalonDoctorSpecialization]
        .append(m_ui->PatientTalonDoctorLastName);
}

void RegistratorButtonsHandler::setUserId(int id)
{
    m_registratorId = id;
}

void RegistratorButtonsHandler::connectButtonsToSlots()
{
    connect(m_ui->RegisterClientButton, &QPushButton::clicked,
            this, &RegistratorButtonsHandler::onRegisterPatientButtonClicked);

    connect(m_ui->FindAllPatientsButton, &QPushButton::clicked,
            this, &RegistratorButtonsHandler::onFindAllPatientsButtonClicked);
    connect(m_ui->FindPatientsButton, &QPushButton::clicked,
            this, &RegistratorButtonsHandler::onFindPatientsButtonClicked);

    connect(m_ui->OpenPatientInfoButton, &QPushButton::clicked,
            this, &RegistratorButtonsHandler::onOpenPatientInfoButtonClicked);
    connect(m_ui->UpdatePatientInfoButton, &QPushButton::clicked,
            this, &RegistratorButtonsHandler::onUpdatePatientInfoButtonClicked);

    connect(m_ui->ScheduleEditDoctorLastName,
            QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &RegistratorButtonsHandler::onDoctorOrDateChangedScheduleEdit);
    connect(m_ui->ScheduleEditDate, &QDateEdit::dateChanged,
            this, &RegistratorButtonsHandler::onDoctorOrDateChangedScheduleEdit);

    connect(m_ui->PatientTalonDoctorLastName,
            QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &RegistratorButtonsHandler::onDoctorOrDateChangedTalon);
    connect(m_ui->PatientTalonAppointmentDate, &QDateEdit::dateChanged,
            this, &RegistratorButtonsHandler::onDoctorOrDateChangedTalon);

    connect(m_ui->ScheduleEditDeleteChosenButton, &QPushButton::clicked,
            this, &RegistratorButtonsHandler::onDeleteSlotButtonClicked);
    connect(m_ui->ScheduleEditDeleteDayButton, &QPushButton::clicked,
            this, &RegistratorButtonsHandler::onDeleteDayOfSlotsButtonClicked);
    connect(m_ui->ScheduleEditAddDayButton, &QPushButton::clicked,
            this, &RegistratorButtonsHandler::onAddDayOfSlotsButtonClicked);
    connect(m_ui->ScheduleEditAddSlotButton, &QPushButton::clicked,
            this, &RegistratorButtonsHandler::onAddSlotButtonClicked);

    connect(m_ui->PatientTalonSaveButton, &QPushButton::clicked,
            this, &RegistratorButtonsHandler::onPatientTalonSaveButtonClicked);

    connect(m_ui->BackToSearchButton, &QPushButton::clicked,
            this, &RegistratorButtonsHandler::onBackToSearchButtonClicked);
    connect(m_ui->BackToClientTableButton, &QPushButton::clicked,
            this, &RegistratorButtonsHandler::onBackToClientTableButtonClicked);
    connect(m_ui->ClientTableTalonButton, &QPushButton::clicked,
            this, &RegistratorButtonsHandler::onClientTableTalonButtonClicked);
    connect(m_ui->BackFromTalonButton, &QPushButton::clicked,
            this, &RegistratorButtonsHandler::onBackFromTalonButtonClicked);
}

void RegistratorButtonsHandler::onRegisterPatientButtonClicked()
{
    QString errorMessage{ InputValidator::patientRegistrationInputIsValid(*m_ui) };
    if (!errorMessage.isEmpty())
    {
        emit errorOccurred(errorMessage);
        return;
    }

    PatientData data{};
    data.lastName = m_ui->PatientRegLastName->text();
    data.firstName = m_ui->PatientRegFirstName->text();
    data.middleName = m_ui->PatientRegMiddleName->text();
    data.dateOfBirth = m_ui->PatientRegDateOfBirth->date();
    data.gender = m_ui->PatientRegGender->currentText();
    data.documentType = m_ui->PatientRegDocument->currentText();
    data.documentNumber = m_ui->PatientRegDocumentNumber->text();
    data.documentSeries = m_ui->PatientRegDocumentSeries->text();
    data.medicalInsuranceNumber = m_ui->PatientRegMedicalInsurance->text();
    data.individualInsuranceNumber = m_ui->PatientRegIndividualInsurance->text();
    data.phoneNumber = m_ui->PatientRegPhoneNumber->text();
    data.city = m_ui->PatientRegCity->text();
    data.street = m_ui->PatientRegStreet->text();
    data.houseNumber = m_ui->PatientRegHouseNumber->text().toInt();
    data.apartmentNumber = m_ui->PatientRegApartmentNumber->text().toInt();

    m_client->sendPatientRegistrationRequest(data);
}

void RegistratorButtonsHandler::onPatientRegistration(bool success)
{
    if (success) {
        QMessageBox::information(nullptr, "Success", "Пациент успешно зарегистрирован.");
    } else {
        QMessageBox::critical(nullptr, "Error", "Не удалось добавить пациента в базу данных.");
    }
}

void RegistratorButtonsHandler::onFindAllPatientsButtonClicked()
{
    m_isSpecificSearch = false;
    m_client->sendGetAllPatientBriefDataRequest();
}

void RegistratorButtonsHandler::onGetAllPatientBriefDataResult(const std::vector<PatientBriefData>& data)
{
    if (!data.empty())
    {
        fillTableWithData(data);
        StackedWidgetNavigator::navigateToPage(*m_ui->ClientSearchStackedWidget, constants::kFoundClientsPage);
    }
    else
    {
        QMessageBox::critical(nullptr, "Error", "Не удалось найти пациентов в базе данных.");
    }
}

void RegistratorButtonsHandler::onFindPatientsButtonClicked()
{
    PatientSearchData data{};
    bool searchEnabled{ false };
    if (m_ui->PatientSearchLastNameCheckBox->isChecked())
    {
        data.lastName = m_ui->PatientSearchLastName->text();
        searchEnabled = true;
    }
    if (m_ui->PatientSearchFirstNameCheckBox->isChecked())
    {
        data.firstName = m_ui->PatientSearchFirstName->text();
        searchEnabled = true;
    }
    if (m_ui->PatientSearchMiddleNameCheckBox->isChecked())
    {
        data.middleName = m_ui->PatientSearchMiddleName->text();
        searchEnabled = true;
    }
    if (m_ui->PatientSearchDateOfBirthCheckBox->isChecked())
    {
        data.dateOfBirth = m_ui->PatientSearchDateOfBirth->date();
        searchEnabled = true;
    }
    if (m_ui->PatientSearchDocumentTypeCheckBox->isChecked())
    {
        data.documentType = m_ui->PatientSearchDocumentType->currentText();
        searchEnabled = true;
    }
    if (m_ui->PatientSearchDocumentSeriesCheckBox->isChecked())
    {
        data.documentSeries = m_ui->PatientSearchDocumentSeries->text();
        searchEnabled = true;
    }
    if (m_ui->PatientSearchDocumentNumberCheckBox->isChecked())
    {
        data.documentNumber = m_ui->PatientSearchLastName->text();
        searchEnabled = true;
    }
    if (m_ui->PatientSearchGenderCheckBox->isChecked())
    {
        data.gender = m_ui->PatientSearchGender->currentText();
        searchEnabled = true;
    }

    if (searchEnabled)
    {
        m_isSpecificSearch = true;
        m_lastSearchCriteria = data;
        m_client->sendGetPatientBriefDataRequest(data);
    }
    else
    {
        QMessageBox::critical(nullptr, "Error", "Укажите хотя бы один критерий для поиска");
    }
}

void RegistratorButtonsHandler::onGetPatientsBriefDataResult(const std::vector<PatientBriefData>& data)
{
    if (!data.empty())
    {
        fillTableWithData(data);
        StackedWidgetNavigator::navigateToPage(*m_ui->ClientSearchStackedWidget, constants::kFoundClientsPage);
    }
    else
    {
        QMessageBox::critical(nullptr, "Error", "Не удалось найти пациентов по вашему запросу.");
    }
}

void RegistratorButtonsHandler::onOpenPatientInfoButtonClicked()
{
    int selectedRow{ m_ui->FoundClientsTable->currentRow() };
    // it always chooses the first one if there is no choice
    // look into that if you have time
    if (selectedRow != -1)
    {
        int patientId{ m_ui->FoundClientsTable->item(selectedRow, 0)->text().toInt() };
        m_currentPatientId = patientId;
        m_client->sendGetPatientInfoRequest(patientId);
    }
}

void RegistratorButtonsHandler::onPatientInfoResult(const PatientData& data)
{
    m_ui->PatientPageLastName->setText(data.lastName);
    m_ui->PatientPageFirstName->setText(data.firstName);
    m_ui->PatientPageMiddleName->setText(data.middleName);
    m_ui->PatientPageDateOfBirth->setDate(data.dateOfBirth);
    m_ui->PatientPageGender->setCurrentText(data.gender);
    m_ui->PatientPageDocumentType->setCurrentText(data.documentType);
    m_ui->PatientPageDocumentNumber->setText(data.documentNumber);
    m_ui->PatientPageDocumentSeries->setText(data.documentSeries);
    m_ui->PatientPageMedicalInsuranceNumber->setText(data.medicalInsuranceNumber);
    m_ui->PatientPageIndividualInsuranceNumber->setText(data.individualInsuranceNumber);
    m_ui->PatientPagePhoneNumber->setText(data.phoneNumber);
    m_ui->PatientPageCity->setText(data.city);
    m_ui->PatientPageStreet->setText(data.street);
    m_ui->PatientPageHouseNumber->setText(QString::number(data.houseNumber));
    m_ui->PatientPageApartmentNumber->setText(QString::number(data.apartmentNumber));

    StackedWidgetNavigator::navigateToPage(*m_ui->ClientSearchStackedWidget, constants::kClientInfoPage);
}

void RegistratorButtonsHandler::onUpdatePatientInfoButtonClicked()
{
    PatientData data{};
    data.lastName = m_ui->PatientPageLastName->text();
    data.firstName = m_ui->PatientPageFirstName->text();
    data.middleName = m_ui->PatientPageMiddleName->text();
    data.dateOfBirth = m_ui->PatientPageDateOfBirth->date();
    data.gender = m_ui->PatientPageGender->currentText();
    data.documentType = m_ui->PatientPageDocumentType->currentText();
    data.documentNumber = m_ui->PatientPageDocumentNumber->text();
    data.documentSeries = m_ui->PatientPageDocumentSeries->text();
    data.medicalInsuranceNumber = m_ui->PatientPageMedicalInsuranceNumber->text();
    data.individualInsuranceNumber = m_ui->PatientPageIndividualInsuranceNumber->text();
    data.phoneNumber = m_ui->PatientPagePhoneNumber->text();
    data.city = m_ui->PatientPageCity->text();
    data.street = m_ui->PatientPageStreet->text();
    data.houseNumber = m_ui->PatientPageHouseNumber->text().toInt();
    data.apartmentNumber = m_ui->PatientPageApartmentNumber->text().toInt();

    m_client->sendUpdatePatientInfoRequest(data, m_currentPatientId);
}

void RegistratorButtonsHandler::onUpdatePatientInfoResult(bool success)
{
    if (success) {
        QMessageBox::information(nullptr, "Success", "Данные успешно обновлены.");
    } else {
        QMessageBox::critical(nullptr, "Error", "Не удалось обновить данные пациента.");
    }
}


void RegistratorButtonsHandler::onBackToSearchButtonClicked()
{
    StackedWidgetNavigator::navigateToPage(*m_ui->ClientSearchStackedWidget, constants::kSeachClientsPage);
}

void RegistratorButtonsHandler::onBackToClientTableButtonClicked()
{
    if (m_isSpecificSearch && m_lastSearchCriteria.has_value())
    {
        m_client->sendGetPatientBriefDataRequest(m_lastSearchCriteria.value());
    }
    else
    {
        m_client->sendGetAllPatientBriefDataRequest();
    }

    StackedWidgetNavigator::navigateToPage(*m_ui->ClientSearchStackedWidget, constants::kFoundClientsPage);
}

void RegistratorButtonsHandler::onSpecializationChanged()
{
    QComboBox* senderComboBox{ qobject_cast<QComboBox*>(sender()) };
    if (senderComboBox)
    {
        m_lastUpdatedSpecializationComboBox = senderComboBox;
        QString specialization{ senderComboBox->currentText() };
        m_client->sendGetDoctorsBySpecializationRequest(specialization);
    }
}

void RegistratorButtonsHandler::onGetDoctorsBySpecializationResult(const std::vector<DoctorScheduleData>& data)
{

    if (!m_lastUpdatedSpecializationComboBox)
    {
        return;
    }

    QVector<QComboBox*> relatedDoctorComboBoxes = m_specializationToDoctorMap.value(m_lastUpdatedSpecializationComboBox);
    if (relatedDoctorComboBoxes.isEmpty())
    {
        return;
    }

    for (QComboBox* doctorComboBox : relatedDoctorComboBoxes)
    {
        doctorComboBox->clear();
        for (const auto& doctor : data)
        {
            doctorComboBox->addItem(doctor.lastName, doctor.id);
        }
    }

    m_lastUpdatedSpecializationComboBox = nullptr;
}

void RegistratorButtonsHandler::onDoctorOrDateChangedScheduleEdit()
{
    QVariant doctorIdVariant{ m_ui->ScheduleEditDoctorLastName->currentData() };

    if (doctorIdVariant.isValid())
    {
        int doctorId{ doctorIdVariant.toInt() };
        QDate date{ m_ui->ScheduleEditDate->date() };
        m_client->sendGetDoctorSlotsRequest(doctorId, date);
    }
}

void RegistratorButtonsHandler::onGetDoctorSlotsResultScheduleEdit(const std::vector<DoctorSlotData>& data)
{
    fillSlotTable(m_ui->ScheduleEditTable, data);
}

// could refactor those
void RegistratorButtonsHandler::onDoctorOrDateChangedTalon()
{
    QVariant doctorIdVariant{ m_ui->PatientTalonDoctorLastName->currentData() };

    if (doctorIdVariant.isValid())
    {
        int doctorId{ doctorIdVariant.toInt() };
        QDate date{ m_ui->PatientTalonAppointmentDate->date() };
        m_client->sendGetDoctorSlotsRequest(doctorId, date);
    }
}

void RegistratorButtonsHandler::onGetDoctorSlotsResultTalon(const std::vector<DoctorSlotData>& data)
{
    fillSlotTable(m_ui->PatientTalonScheduleTable, data);
}

void RegistratorButtonsHandler::onDeleteSlotButtonClicked()
{
    int selectedRow{ m_ui->ScheduleEditTable->currentRow() };

    if (selectedRow != -1)
    {
        int slotId{ m_ui->ScheduleEditTable->item(selectedRow, 0)->text().toInt() };
        m_client->sendDeleteSlotRequest(slotId);
    }
}

void RegistratorButtonsHandler::onDeleteSlotResult(bool success)
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

void RegistratorButtonsHandler::onDeleteDayOfSlotsButtonClicked()
{
    QVariant doctorIdVariant{ m_ui->ScheduleEditDoctorLastName->currentData() };

    if (doctorIdVariant.isValid())
    {
        int doctorId{ doctorIdVariant.toInt() };
        QDate date{ m_ui->ScheduleEditDate->date() };
        m_client->sendDeleteDayOfSlotsRequest(doctorId, date);
    }
    else
    {
        QMessageBox::critical(nullptr, "Error", "Ошибка в получении данных");
    }
}

void RegistratorButtonsHandler::onDeleteDayOfSlotsResult(bool success)
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

void RegistratorButtonsHandler::onAddSlotButtonClicked()
{
    QVariant doctorIdVariant{ m_ui->ScheduleEditDoctorLastName->currentData() };

    if (doctorIdVariant.isValid()) {
        int doctorId{ doctorIdVariant.toInt() };
        QDate date{ m_ui->ScheduleEditDate->date() };

        AddSlotDialog dialog{};
        if (dialog.exec() == QDialog::Accepted) {
            QTime startTime{ dialog.selectedTime() };
            m_client->sendAddSlotRequest(doctorId, date, startTime);
        }
    } else {
        QMessageBox::critical(nullptr, "Error", "Ошибка в получении данных");
    }
}

void RegistratorButtonsHandler::onAddSlotResult(bool success)
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

void RegistratorButtonsHandler::onAddDayOfSlotsButtonClicked()
{
    QVariant doctorIdVariant{ m_ui->ScheduleEditDoctorLastName->currentData() };

    if (doctorIdVariant.isValid())
    {
        int doctorId{ doctorIdVariant.toInt() };
        QDate date{ m_ui->ScheduleEditDate->date() };
        m_client->sendAddDayOfSlotsRequest(doctorId, date);
    }
    else
    {
        QMessageBox::critical(nullptr, "Error", "Ошибка в получении данных");
    }
}

void RegistratorButtonsHandler::onAddDayOfSlotsResult(bool success)
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

void RegistratorButtonsHandler::onPatientTalonSaveButtonClicked()
{
    AppointmentData data{};
    int selectedRow{ m_ui->PatientTalonScheduleTable->currentRow() };
    data.slotId = m_ui->PatientTalonScheduleTable->item(selectedRow, 0)->text().toInt();
    QVariant doctorIdVariant{ m_ui->PatientTalonDoctorLastName->currentData() };
    data.doctorId = doctorIdVariant.toInt();
    data.patientId = m_currentPatientId;
    data.registratorId = m_registratorId;

    m_client->sendAddAppointmentRequest(data);
}

void RegistratorButtonsHandler::onGetAppointmentResult(bool success)
{
    if (!success)
    {
        QMessageBox::critical(nullptr, "Error", "Ошибка при добавлении записи");
    }
}

void RegistratorButtonsHandler::onClientTableTalonButtonClicked()
{
    int selectedRow{ m_ui->FoundClientsTable->currentRow() };
    QString clientData{};
    m_currentPatientId = m_ui->FoundClientsTable->item(selectedRow, 0)->text().toInt();
    for (int col{ 1 }; col < m_ui->FoundClientsTable->columnCount(); ++col)
    {
        QTableWidgetItem* item{ m_ui->FoundClientsTable->item(selectedRow, col) };
        clientData.append(item->text());
        clientData.append(" ");
    }

    m_ui->TalonPageClientInfo->setText(clientData);

    m_lastClientStackedWidgetIndex = m_ui->ClientSearchStackedWidget->currentIndex();

    StackedWidgetNavigator::navigateToPage(*m_ui->ClientSearchStackedWidget, constants::kTalonPage);
}

void RegistratorButtonsHandler::fillTableWithData(const std::vector<PatientBriefData>& data)
{
    m_ui->FoundClientsTable->setRowCount(data.size());
    m_ui->FoundClientsTable->setColumnCount(constants::kNumberOfClientsTableColumns);

    m_ui->FoundClientsTable->setHorizontalHeaderLabels(
            { "ID", "Фамилия", "Имя", "Отчество", "Дата рождения" });

    // move this somewhere else?
    int fontSize{ 14 };
    QFont font{};
    font.setPointSize(fontSize);

    for (std::size_t i{ 0 }; i < data.size(); ++i)
    {
        // why an auto& here.. god knows
        const auto& patient = data[i];
        const QStringList rowData{
            QString::number(patient.id),
            patient.lastName,
            patient.firstName,
            patient.middleName,
            patient.dateOfBirth.toString("dd-MM-yyyy")
        };

        for (std::size_t j{ 0 }; j < constants::kNumberOfClientsTableColumns; ++j)
        {
            QTableWidgetItem* item{ new QTableWidgetItem(rowData[j]) };
            item->setFlags(item->flags() & ~Qt::ItemIsEditable);
            item->setFont(font);
            m_ui->FoundClientsTable->setItem(i, j, item);
        }
    }

    m_ui->FoundClientsTable->hideColumn(0);
}

void RegistratorButtonsHandler::fillSlotTable(QTableWidget* table, const std::vector<DoctorSlotData>& data)
{
    table->clearContents();
    table->setRowCount(data.size());
    table->setColumnCount(4);

    table->setHorizontalHeaderLabels(
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
            table->setItem(i, j, item);
        }
    }

    table->hideColumn(0);
}

void RegistratorButtonsHandler::updateDoctorComboBox(QComboBox* specializationComboBox)
{
    QString specialization{ specializationComboBox->currentText() };
    m_client->sendGetDoctorsBySpecializationRequest(specialization);
}

void RegistratorButtonsHandler::onBackFromTalonButtonClicked()
{
    m_ui->ClientSearchStackedWidget->setCurrentIndex(m_lastClientStackedWidgetIndex);
}
}
