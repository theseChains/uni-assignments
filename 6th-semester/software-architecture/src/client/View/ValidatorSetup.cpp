#include "ValidatorSetup.h"

#include <QIntValidator>

namespace polyclinic
{
ValidatorSetup::ValidatorSetup(QObject* parent)
    : QObject{ parent }
{
}

void ValidatorSetup::setupValidators(Ui::ApplicationViewUi& ui)
{
    setupPatientRegistrationPageValidators(ui);
}

void ValidatorSetup::setupLineEditValidator(QLineEdit* lineEdit,
                                            const QString& regexPattern)
{
    QRegularExpression regex{ regexPattern };
    QRegularExpressionValidator* validator{
            new QRegularExpressionValidator{ regex, this } };
    lineEdit->setValidator(validator);
}

void ValidatorSetup::setupPatientRegistrationPageValidators(Ui::ApplicationViewUi& ui)
{
    setupLineEditValidator(ui.PatientRegDocumentNumber, "^[0-9]{6}$");
    setupLineEditValidator(ui.PatientRegDocumentSeries, "^[0-9]{4}$");
    setupLineEditValidator(ui.PatientRegMedicalInsurance, "^[0-9]{16}$");
    setupLineEditValidator(ui.PatientRegIndividualInsurance, "^[0-9]{3}-[0-9]{3}-[0-9]{3} [0-9]{2}$");
    setupLineEditValidator(ui.PatientRegPhoneNumber, "^[0-9]{10,15}$");

    QIntValidator* intValidator{ new QIntValidator{ 0, 9999, this } };
    ui.PatientRegHouseNumber->setValidator(intValidator);
    ui.PatientRegApartmentNumber->setValidator(intValidator);
}
}
