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
    connect(m_client, &Client::getMedicalRecordDataResult,
            this, &DoctorButtonsHandler::onGetMedicalRecordDataResult);
    connect(m_client, &Client::updateMedicalRecordResult,
            this, &DoctorButtonsHandler::onUpdateMedicalRecordResult);
    connect(m_client, &Client::addRecipeResult,
            this, &DoctorButtonsHandler::onAddRecipeResult);
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
    connect(m_ui->BackToOutpatientCardsListButton, &QPushButton::clicked,
            this, &DoctorButtonsHandler::onBackToOutpatientCardsListButtonClicked);
    connect(m_ui->EditMedRecordButton, &QPushButton::clicked,
            this, &DoctorButtonsHandler::onEditMedRecordButtonClicked);
    connect(m_ui->OpenMedicalRecordButton, &QPushButton::clicked,
            this, &DoctorButtonsHandler::onOpenMedicalRecordButtonClicked);
    connect(m_ui->BackToListOfMedRecordsButton, &QPushButton::clicked,
            this, &DoctorButtonsHandler::onBackToListOfMedRecordsButtonClicked);
    connect(m_ui->NewRecipeButton, &QPushButton::clicked,
            this, &DoctorButtonsHandler::onNewRecipeButtonClicked);
    connect(m_ui->SaveRecipeButton, &QPushButton::clicked,
            this, &DoctorButtonsHandler::onSaveRecipeButtonClicked);
    connect(m_ui->BackFromRecipeButton, &QPushButton::clicked,
            this, &DoctorButtonsHandler::onBackFromRecipeButtonClicked);
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
    m_ui->AppointedPatientsTable->setColumnCount(6);

    m_ui->AppointedPatientsTable->setHorizontalHeaderLabels(
            { "PatID", "AppId", "Время", "ФИО", "Дата рождения", "Направил" });

    int fontSize{ 14 };
    QFont font{};
    font.setPointSize(fontSize);

    for (std::size_t i{ 0 }; i < data.size(); ++i)
    {
        // why an auto& here.. god knows
        const auto& appointment = data[i];
        const QStringList rowData{
            QString::number(appointment.patientId),
            QString::number(appointment.appointmentId),
            appointment.startTime.toString("hh:mm") + " " +
                appointment.endTime.toString("hh:mm"),
            appointment.patientLastName + " " +
                appointment.patientFirstName + " " +
                appointment.patientMiddleName,
            appointment.dateOfBirth.toString("dd-MM-yyyy"),
            appointment.registratorLastName
        };

        for (std::size_t j{ 0 }; j < 6; ++j)
        {
            QTableWidgetItem* item{ new QTableWidgetItem(rowData[j]) };
            item->setFlags(item->flags() & ~Qt::ItemIsEditable);
            item->setFont(font);
            m_ui->AppointedPatientsTable->setItem(i, j, item);
        }
    }

    m_ui->AppointedPatientsTable->hideColumn(0);
    m_ui->AppointedPatientsTable->hideColumn(1);
}

void DoctorButtonsHandler::onOpenNewMedicalRecordButtonClicked()
{
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
    m_currentAppointmentId =
            m_ui->AppointedPatientsTable->item(selectedRow, 1)->text().toInt();

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
    data.appointmentId = m_currentAppointmentId;
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

    /* m_currentPatientId = */
    /*         m_ui->OutpatientCardsTable->item(selectedRow, 0)->text().toInt(); */
    int patientId =
            m_ui->OutpatientCardsTable->item(selectedRow, 0)->text().toInt();
    StackedWidgetNavigator::navigateToPage(*m_ui->OutpatientCardsStackedWidget,
            "MedicalRecordTablePage");

    m_client->sendGetMedicalRecordsRequest(patientId);
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
    m_ui->MedicalRecordsTable->setColumnCount(4);

    m_ui->MedicalRecordsTable->setHorizontalHeaderLabels(
            { "ID", "Дата обращения", "Жалобы", "Диагноз" });

    int fontSize{ 14 };
    QFont font{};
    font.setPointSize(fontSize);

    for (std::size_t i{ 0 }; i < data.size(); ++i)
    {
        const auto& record = data[i];
        const QStringList rowData{
            QString::number(record.recordId),
            record.dateOfEntry.toString("dd-MM-yyyy"),
            record.complaints,
            record.diagnosis
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

void DoctorButtonsHandler::onOpenMedicalRecordButtonClicked()
{
    int selectedRow{ m_ui->MedicalRecordsTable->currentRow() };
    int recordId =
            m_ui->MedicalRecordsTable->item(selectedRow, 0)->text().toInt();

    StackedWidgetNavigator::navigateToPage(*m_ui->OutpatientCardsStackedWidget,
            "MedicalRecordEditPage");

    m_client->sendGetMedicalRecordDataRequest(recordId);
}

void DoctorButtonsHandler::onGetMedicalRecordDataResult(const MedicalRecordData& data)
{
    m_ui->MedRecordEditPatientInfo->setText(m_ui->OutpatientCardPagePatientInfo->text());

    m_ui->MedRecordEditComplaints->setText(data.complaints);
    m_ui->MedRecordEditDiagnosis->setText(data.diagnosis);
    m_ui->MedRecordEditTreatment->setText(data.treatment);
    m_ui->MedRecordEditTests->setText(data.tests);
    m_ui->MedRecordEditDoctorNotes->setText(data.notes);
    m_ui->MedRecordEditRecipes->setText(data.recipe);

    m_currentMedRecordId = data.recordId;
}

void DoctorButtonsHandler::onEditMedRecordButtonClicked()
{
    MedicalRecordData data{};
    data.recordId = m_currentMedRecordId;
    data.complaints = m_ui->MedRecordEditComplaints->text();
    data.diagnosis = m_ui->MedRecordEditDiagnosis->text();
    data.treatment = m_ui->MedRecordEditTreatment->text();
    data.tests = m_ui->MedRecordEditTests->text();
    data.notes = m_ui->MedRecordEditDoctorNotes->text();
    data.recipe = m_ui->MedRecordEditRecipes->text();

    m_client->sendUpdateMedicalRecordRequest(data);
}

void DoctorButtonsHandler::onUpdateMedicalRecordResult(bool success)
{
    if (success)
    {
        QMessageBox::information(nullptr, "Success", "Запись обновлена");
    }
    else
    {
        QMessageBox::critical(nullptr, "Error", "Ошибка при обновлении записи");
    }
}

void DoctorButtonsHandler::onNewRecipeButtonClicked()
{
    int selectedRow{ m_ui->MedicalRecordsTable->currentRow() };
    int recordId =
            m_ui->MedicalRecordsTable->item(selectedRow, 0)->text().toInt();
    std::cerr << "chosen med record id: " << recordId << '\n';
    m_currentMedRecordId = recordId;

    m_ui->RecipeEditPatientInfo->setText(m_ui->OutpatientCardPagePatientInfo->text());

    StackedWidgetNavigator::navigateToPage(*m_ui->OutpatientCardsStackedWidget, "NewRecipePage");
}

void DoctorButtonsHandler::onSaveRecipeButtonClicked()
{
    QString recipeInfo{"Средство: "};
    recipeInfo += m_ui->RecipeEditMedicine->text();
    recipeInfo += " Дозировка: ";
    recipeInfo += m_ui->RecipeEditDosage->text();
    recipeInfo += " Количество: ";
    recipeInfo += m_ui->RecipeEditAmount->text();

    m_client->sendAddRecipeRequest(m_currentMedRecordId, recipeInfo);
}

void DoctorButtonsHandler::onAddRecipeResult(bool success)
{
    if (success)
    {
        QMessageBox::information(nullptr, "Success", "Рецепт добавлен");
    }
    else
    {
        QMessageBox::critical(nullptr, "Error", "Ошибка при добавлении рецепта");
    }
}

void DoctorButtonsHandler::onBackToOutpatientCardsListButtonClicked()
{
    StackedWidgetNavigator::navigateToPage(*m_ui->OutpatientCardsStackedWidget,
            "OutpatientCardsListPage");
}

void DoctorButtonsHandler::onBackToListOfMedRecordsButtonClicked()
{
    StackedWidgetNavigator::navigateToPage(*m_ui->OutpatientCardsStackedWidget,
            "MedicalRecordTablePage");
}

void DoctorButtonsHandler::onBackFromRecipeButtonClicked()
{
    StackedWidgetNavigator::navigateToPage(*m_ui->OutpatientCardsStackedWidget,
            "MedicalRecordTablePage");
}
}
