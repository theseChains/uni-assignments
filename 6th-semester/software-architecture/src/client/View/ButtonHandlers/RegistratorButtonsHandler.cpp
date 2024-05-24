#include "RegistratorButtonsHandler.h"
#include "../ui_ApplicationViewUi.h"
#include "client/View/ViewConstants.h"
#include "client/View/StackedWidgetNavigator/StackedWidgetNavigator.h"
#include "client/View/InputValidator.h"
#include "common/data/PatientRegistrationData.h"

#include <QPushButton>
#include <QMessageBox>
#include <iostream>

namespace polyclinic
{
RegistratorButtonsHandler::RegistratorButtonsHandler(Facade* facade)
    : m_facade{ facade }
{
    connect(m_facade, &Facade::patientRegistrationResult,
            this, &RegistratorButtonsHandler::onPatientRegistration);
    connect(m_facade, &Facade::getAllPatientBriefDataResult,
            this, &RegistratorButtonsHandler::onGetAllPatientBriefDataResult);
}

void RegistratorButtonsHandler::setUi(Ui::ApplicationViewUi* ui)
{
    m_ui = ui;
}

void RegistratorButtonsHandler::connectButtonsToSlots()
{
    QObject::connect(m_ui->RegisterClientButton, &QPushButton::clicked,
            this, &RegistratorButtonsHandler::onRegisterPatientButtonClicked);
    connect(m_ui->FindAllPatients, &QPushButton::clicked,
            this, &RegistratorButtonsHandler::onFindAllPatientsButtonClicked);

    QObject::connect(m_ui->OpenClientInfoButton, &QPushButton::clicked,
            this, &RegistratorButtonsHandler::onOpenClientInfoButtonClicked);
    /* QObject::connect(m_ui->FindClientsButton, &QPushButton::clicked, */
    /*         this, &RegistratorButtonsHandler::onFindClientsButtonClicked); */
    QObject::connect(m_ui->BackToSearchButton, &QPushButton::clicked,
            this, &RegistratorButtonsHandler::onBackToSearchButtonClicked);
    QObject::connect(m_ui->BackToClientTableButton, &QPushButton::clicked,
            this, &RegistratorButtonsHandler::onBackToClientTableButtonClicked);
    QObject::connect(m_ui->ClientPageTalonButton, &QPushButton::clicked,
            this, &RegistratorButtonsHandler::onClientPageTalonButtonClicked);
    QObject::connect(m_ui->ClientTableTalonButton, &QPushButton::clicked,
            this, &RegistratorButtonsHandler::onClientTableTalonButtonClicked);
    QObject::connect(m_ui->BackFromTalonButton, &QPushButton::clicked,
            this, &RegistratorButtonsHandler::onBackFromTalonButtonClicked);
    QObject::connect(m_ui->TalonPageEditScheduleButton, &QPushButton::clicked,
            this, &RegistratorButtonsHandler::onTalonPageEditScheduleButtonClicked);
}

void RegistratorButtonsHandler::onRegisterPatientButtonClicked()
{
    QString errorMessage{ InputValidator::patientRegistrationInputIsValid(*m_ui) };
    if (!errorMessage.isEmpty())
    {
        emit errorOccurred(errorMessage);
        return;
    }

    PatientRegistrationData data{};
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

    m_facade->registerPatient(data);
}

void RegistratorButtonsHandler::onPatientRegistration(bool success)
{
    if (success) {
        // kinda sucks for nullptr stuff here but alright
        // fix if you have time
        QMessageBox::information(nullptr, "Success", "Пациент успешно зарегистрирован.");
    } else {
        QMessageBox::critical(nullptr, "Error", "Не удалось добавить пациента в базу данных.");
    }
}

void RegistratorButtonsHandler::onFindAllPatientsButtonClicked()
{
    m_facade->getAllPatientBriefData();
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

void RegistratorButtonsHandler::onOpenClientInfoButtonClicked()
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

        StackedWidgetNavigator::navigateToPage(*m_ui->ClientSearchStackedWidget, constants::kClientInfoPage);
    }
}

void RegistratorButtonsHandler::onBackToSearchButtonClicked()
{
    StackedWidgetNavigator::navigateToPage(*m_ui->ClientSearchStackedWidget, constants::kSeachClientsPage);
}

void RegistratorButtonsHandler::onBackToClientTableButtonClicked()
{
    StackedWidgetNavigator::navigateToPage(*m_ui->ClientSearchStackedWidget, constants::kFoundClientsPage);
}

void RegistratorButtonsHandler::onClientPageTalonButtonClicked()
{
    QString clientData{};

    clientData.append(m_ui->ClientPageLastName->text() + " ");
    clientData.append(m_ui->ClientPageFirstName->text() + " ");
    clientData.append(m_ui->ClientPageMiddleName->text() + " ");
    QDate date{ m_ui->ClientPageDateOfBirth->date() };
    clientData.append(date.toString("dd.MM.yyyy"));

    m_ui->TalonPageClientInfo->setText(clientData);

    m_lastClientStackedWidgetIndex = m_ui->ClientSearchStackedWidget->currentIndex();

    StackedWidgetNavigator::navigateToPage(*m_ui->ClientSearchStackedWidget, constants::kTalonPage);
}

void RegistratorButtonsHandler::onClientTableTalonButtonClicked()
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

    StackedWidgetNavigator::navigateToPage(*m_ui->ClientSearchStackedWidget, constants::kTalonPage);
}

void RegistratorButtonsHandler::fillTableWithData(const std::vector<PatientBriefData>& data)
{
    m_ui->FoundClientsTable->setRowCount(data.size());
    m_ui->FoundClientsTable->setColumnCount(constants::kNumberOfClientsTableColumns);

    m_ui->FoundClientsTable->setHorizontalHeaderLabels({"ID", "First Name", "Last Name", "Middle Name", "Date of Birth"});

    // move this somewhere else?
    int fontSize{ 14 };
    QFont font;
    font.setPointSize(fontSize);

    for (std::size_t i{ 0 }; i < data.size(); ++i)
    {
        // why an auto& here.. god knows
        const auto& patient = data[i];
        const QStringList rowData = {
            QString::number(patient.id),
            patient.firstName,
            patient.lastName,
            patient.middleName,
            patient.dateOfBirth.toString("dd-MM-yyyy")
        };

        for (std::size_t j = 0; j < constants::kNumberOfClientsTableColumns; ++j)
        {
            QTableWidgetItem* item = new QTableWidgetItem(rowData[j]);
            item->setFlags(item->flags() & ~Qt::ItemIsEditable);
            item->setFont(font);
            m_ui->FoundClientsTable->setItem(i, j, item);
        }
    }

    // Hide the ID column
    m_ui->FoundClientsTable->hideColumn(0);
}

void RegistratorButtonsHandler::onBackFromTalonButtonClicked()
{
    m_ui->ClientSearchStackedWidget->setCurrentIndex(m_lastClientStackedWidgetIndex);
}

void RegistratorButtonsHandler::onTalonPageEditScheduleButtonClicked()
{
    // hmm
    m_ui->RegistratorTabs->setCurrentIndex(2);
}
}
