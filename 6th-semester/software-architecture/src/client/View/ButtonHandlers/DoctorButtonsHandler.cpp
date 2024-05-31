#include "DoctorButtonsHandler.h"
#include "../ui_ApplicationViewUi.h"
#include "client/View/StackedWidgetNavigator/StackedWidgetNavigator.h"
#include "client/View/ViewConstants.h"

#include <QMessageBox>

namespace polyclinic
{
DoctorButtonsHandler::DoctorButtonsHandler(Client* client, QObject* parent)
    : QObject{ parent }, m_client{ client }
{
    connect(m_client, &Client::getDoctorAppointmentsResult,
            this, &DoctorButtonsHandler::onGetDoctorAppointmentsResult);
    connect(m_client, &Client::addMedicalRecordResult,
            this, &DoctorButtonsHandler::onAddMedicalRecordResult);
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
    int selectedRow{ m_ui->AppointedPatientsTable->currentRow() };
    QString patientData{};
    for (int col{ 1 }; col < m_ui->AppointedPatientsTable->colorCount(); ++col)
    {
        QTableWidgetItem* item{ m_ui->AppointedPatientsTable->item(selectedRow, col) };
        patientData.append(item->text());
        patientData.append(" ");
    }

    m_ui->MedRecordPatientInfo->setText(patientData);

    m_currentPatientId =
            m_ui->AppointedPatientsTable->item(selectedRow, 0)->text().toInt();

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
}
