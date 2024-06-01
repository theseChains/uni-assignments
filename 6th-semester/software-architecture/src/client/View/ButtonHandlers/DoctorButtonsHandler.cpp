#include "DoctorButtonsHandler.h"
#include "../ui_ApplicationViewUi.h"
#include "client/View/StackedWidgetNavigator/StackedWidgetNavigator.h"
#include "client/View/ViewConstants.h"

#include <QMessageBox>
#include <iostream>

namespace polyclinic
{
DoctorButtonsHandler::DoctorButtonsHandler(Client* client, QObject* parent)
    : QObject{ parent }, m_client{ client }
{
    connect(m_client, &Client::getDoctorAppointmentsResult,
            this, &DoctorButtonsHandler::onGetDoctorAppointmentsResult);
    connect(m_client, &Client::addMedicalRecordResult,
            this, &DoctorButtonsHandler::onAddMedicalRecordResult);
    connect(m_client, &Client::getOutpatientCardsResult,
            this, &DoctorButtonsHandler::onGetOutpatientCardsResult);
    connect(m_client, &Client::getMedicalRecordsResult,
            this, &DoctorButtonsHandler::onGetMedicalRecordsResult);
}

void DoctorButtonsHandler::setUi(Ui::ApplicationViewUi* ui)
{
    m_ui = ui;
}

void DoctorButtonsHandler::setUserId(int id)
{
    m_doctorId = id;
}

void DoctorButtonsHandler::connectButtonsToSlots()
{
    connect(m_ui->ShowAppointedPatientsButton, &QPushButton::clicked,
            this, &DoctorButtonsHandler::onShowAppointedPatientsButtonClicked);
    connect(m_ui->OpenNewMedicalRecordButton, &QPushButton::clicked,
            this, &DoctorButtonsHandler::onOpenNewMedicalRecordButtonClicked);
    connect(m_ui->BackToAppointedClientsButton, &QPushButton::clicked,
            this, &DoctorButtonsHandler::onBackToAppointedClientsButtonClicked);
    connect(m_ui->SearchOutpatientCardsButton, &QPushButton::clicked,
            this, &DoctorButtonsHandler::onSearchOutpatientCardsButtonClicked);
    connect(m_ui->OpenOutpatientCardButton, &QPushButton::clicked,
            this, &DoctorButtonsHandler::onOpenOutpatientCardButtonClicked);
    connect(m_ui->SaveMedRecordButton, &QPushButton::clicked,
            this, &DoctorButtonsHandler::onSaveMedRecordButtonClicked);
}

void DoctorButtonsHandler::onShowAppointedPatientsButtonClicked()
{
    QDate date{ m_ui->AppointmentDate->date() };
    m_client->sendGetDoctorAppointmentsRequest(date, m_doctorId);
}

void DoctorButtonsHandler::onGetDoctorAppointmentsResult(const std::vector<AppointmentFullData>& data)
{
    fillAppointmentsTable(data);
}

void DoctorButtonsHandler::fillAppointmentsTable(const std::vector<AppointmentFullData>& data)
{
    m_ui->AppointedPatientsTable->clearContents();
    m_ui->AppointedPatientsTable->setRowCount(data.size());
    m_ui->AppointedPatientsTable->setColumnCount(5);

    m_ui->AppointedPatientsTable->setHorizontalHeaderLabels(
            { "ID", "Время", "ФИО", "Дата рождения", "Направил" });

    int fontSize{ 14 };
    QFont font{};
    font.setPointSize(fontSize);

    for (std::size_t i{ 0 }; i < data.size(); ++i)
    {
        // why an auto& here.. god knows
        const auto& appointment = data[i];
        const QStringList rowData{
            QString::number(appointment.patientId),
            appointment.startTime.toString("hh:mm") + " " +
                appointment.endTime.toString("hh:mm"),
            appointment.patientLastName + " " +
                appointment.patientFirstName + " " +
                appointment.patientMiddleName,
            appointment.dateOfBirth.toString("dd-MM-yyyy"),
            appointment.registratorLastName
        };

        for (std::size_t j{ 0 }; j < 4; ++j)
        {
            QTableWidgetItem* item{ new QTableWidgetItem(rowData[j]) };
            item->setFlags(item->flags() & ~Qt::ItemIsEditable);
            item->setFont(font);
            m_ui->AppointedPatientsTable->setItem(i, j, item);
        }
    }

    m_ui->AppointedPatientsTable->hideColumn(0);
}

void DoctorButtonsHandler::onOpenNewMedicalRecordButtonClicked()
{
    std::cerr << "opening new med record\n";
    int selectedRow{ m_ui->AppointedPatientsTable->currentRow() };
    QString patientData{};
    for (int col{ 1 }; col < 3; ++col)
    {
        QTableWidgetItem* item{ m_ui->AppointedPatientsTable->item(selectedRow, col) };
        patientData.append(item->text());
        patientData.append(" ");
    }

    m_ui->MedRecordPatientInfo->setText(patientData);

    m_currentPatientId =
            m_ui->AppointedPatientsTable->item(selectedRow, 0)->text().toInt();
    std::cerr << "curr patient id: " << m_currentPatientId << '\n';

    StackedWidgetNavigator::navigateToPage(*m_ui->DoctorStackedWidget,
            constants::kMedicalRecordPage);
}

void DoctorButtonsHandler::onBackToAppointedClientsButtonClicked()
{
    StackedWidgetNavigator::navigateToPage(*m_ui->DoctorStackedWidget,
            constants::kListOfAppointedClientsPage);
}

void DoctorButtonsHandler::onSaveMedRecordButtonClicked()
{
    MedicalRecordData data{};
    data.patientId = m_currentPatientId;
    data.complaints = m_ui->ComplaintsLineEdit->text();
    data.diagnosis = m_ui->DiagnosisLineEdit->text();
    data.treatment = m_ui->TreatmentLineEdit->text();
    data.tests = m_ui->TestsLineEdit->text();
    data.notes = m_ui->NotesLineEdit->text();

    m_client->sendAddMedicalRecordRequest(data);
}

void DoctorButtonsHandler::onAddMedicalRecordResult(bool success)
{
    if (!success)
    {
        QMessageBox::critical(nullptr, "Error", "Ошибка при добавлении записи");
    }
}

void DoctorButtonsHandler::onSearchOutpatientCardsButtonClicked()
{
    PatientBriefData data{};
    data.lastName = m_ui->OutpatientSearchLastName->text();
    data.firstName = m_ui->OutpatientSearchFirstName->text();
    data.middleName = m_ui->OutpatientSearchFirstName->text();

    m_client->sendGetOutpatientCardsRequest(data);
}

void DoctorButtonsHandler::onGetOutpatientCardsResult(const std::vector<OutpatientCardData>& data)
{
    fillOutpatientCardsTable(data);
}

void DoctorButtonsHandler::fillOutpatientCardsTable(const std::vector<OutpatientCardData>& data)
{
    m_ui->OutpatientCardsTable->clearContents();
    m_ui->OutpatientCardsTable->setRowCount(data.size());
    m_ui->OutpatientCardsTable->setColumnCount(4);

    m_ui->OutpatientCardsTable->setHorizontalHeaderLabels(
            { "ID", "ФИО", "Дата рождения", "Дата создания карты" });

    int fontSize{ 14 };
    QFont font{};
    font.setPointSize(fontSize);

    for (std::size_t i{ 0 }; i < data.size(); ++i)
    {
        // why an auto& here.. god knows
        const auto& card = data[i];
        const QStringList rowData{
            QString::number(card.patientId),
            card.patientLastName + " " +
                card.patientFirstName + " " +
                card.patientMiddleName,
            card.patientDateOfBirth.toString("dd-MM-yyyy"),
            card.dateOfCreation.toString("dd-MM-yyyy")
        };

        for (std::size_t j{ 0 }; j < 4; ++j)
        {
            QTableWidgetItem* item{ new QTableWidgetItem(rowData[j]) };
            item->setFlags(item->flags() & ~Qt::ItemIsEditable);
            item->setFont(font);
            m_ui->OutpatientCardsTable->setItem(i, j, item);
        }
    }

    m_ui->OutpatientCardsTable->hideColumn(0);
}

void DoctorButtonsHandler::onOpenOutpatientCardButtonClicked()
{
    int selectedRow{ m_ui->OutpatientCardsTable->currentRow() };
    QString patientData{};
    for (int col{ 1 }; col < 3; ++col)
    {
        QTableWidgetItem* item{ m_ui->OutpatientCardsTable->item(selectedRow, col) };
        patientData.append(item->text());
        patientData.append(" ");
    }

    m_ui->OutpatientCardPagePatientInfo->setText(patientData);

    m_currentPatientId =
            m_ui->OutpatientCardsTable->item(selectedRow, 0)->text().toInt();
    StackedWidgetNavigator::navigateToPage(*m_ui->OutpatientCardsStackedWidget,
            "MedicalRecordTablePage");

    m_client->sendGetMedicalRecordsRequest(m_currentPatientId);
}

void DoctorButtonsHandler::onGetMedicalRecordsResult(const std::vector<MedicalRecordData>& data)
{
    std::cerr << "medical record data size: " << data.size() << '\n';
    fillMedicalRecordsTable(data);
}

void DoctorButtonsHandler::fillMedicalRecordsTable(const std::vector<MedicalRecordData>& data)
{
    m_ui->MedicalRecordsTable->clearContents();
    m_ui->MedicalRecordsTable->setRowCount(data.size());
    m_ui->MedicalRecordsTable->setColumnCount(6);

    m_ui->MedicalRecordsTable->setHorizontalHeaderLabels(
            { "ID", "Жалобы", "Диагноз", "Лечение", "Анализы", "Заметки" });

    int fontSize{ 14 };
    QFont font{};
    font.setPointSize(fontSize);

    for (std::size_t i{ 0 }; i < data.size(); ++i)
    {
        // why an auto& here.. god knows
        const auto& record = data[i];
        const QStringList rowData{
            QString::number(record.patientId),
            record.complaints,
            record.diagnosis,
            record.treatment,
            record.tests,
            record.notes
        };

        for (std::size_t j{ 0 }; j < 4; ++j)
        {
            QTableWidgetItem* item{ new QTableWidgetItem(rowData[j]) };
            item->setFlags(item->flags() & ~Qt::ItemIsEditable);
            item->setFont(font);
            m_ui->MedicalRecordsTable->setItem(i, j, item);
        }
    }

    m_ui->MedicalRecordsTable->hideColumn(0);
}
}
