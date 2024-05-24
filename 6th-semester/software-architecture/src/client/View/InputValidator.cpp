#include "InputValidator.h"

namespace polyclinic
{
QString InputValidator::patientRegistrationInputIsValid(const Ui::ApplicationViewUi& ui)
{
    QString errorMessage{};
    if (ui.PatientRegLastName->text().isEmpty()) {
        errorMessage += "Please enter the patient's last name.\n";
    }

    if (ui.PatientRegFirstName->text().isEmpty()) {
        errorMessage += "Please enter the patient's first name.\n";
    }

    if (ui.PatientRegDateOfBirth->date() > QDate::currentDate()) {
        errorMessage += "Please enter a valid date of birth.\n";
    }

    if (ui.PatientRegCity->text().isEmpty()) {
        errorMessage += "Please enter the patient's city.\n";
    }

    if (ui.PatientRegHouseNumber->text().isEmpty()) {
        errorMessage += "Please enter the patient's house number.\n";
    }

    QRegularExpression documentNumberRegex{ "^[0-9]{6}$" };
    if (!documentNumberRegex.match(ui.PatientRegDocumentNumber->text()).hasMatch()) {
        errorMessage += "Please enter a valid document number (6 digits).\n";
    }

    QRegularExpression documentSeriesRegex{ "^[0-9]{4}$" };
    if (!documentSeriesRegex.match(ui.PatientRegDocumentSeries->text()).hasMatch()) {
        errorMessage += "Please enter a valid document series (4 digits).\n";
    }

    QRegularExpression medicalInsuranceRegex{ "^[0-9]{16}$" };
    if (!medicalInsuranceRegex.match(ui.PatientRegMedicalInsurance->text()).hasMatch()) {
        errorMessage += "Please enter a valid medical insurance number (16 digits).\n";
    }

    QRegularExpression individualInsuranceRegex{ "^[0-9]{3}-[0-9]{3}-[0-9]{3} [0-9]{2}$" };
    if (!individualInsuranceRegex.match(ui.PatientRegIndividualInsurance->text()).hasMatch()) {
        errorMessage += "Please enter a valid individual insurance number.\n";
    }

    QRegularExpression phoneNumberRegex{ "^[0-9]{10,15}$" };
    if (!phoneNumberRegex.match(ui.PatientRegPhoneNumber->text()).hasMatch()) {
        errorMessage += "Please enter a phone number.\n";
    }

    return errorMessage;
}
}
