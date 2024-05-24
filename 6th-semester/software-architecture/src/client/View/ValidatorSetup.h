#ifndef POLYCLINIC_APP_CLIENT_VIEW_VALIDATORSETUP_H_
#define POLYCLINIC_APP_CLIENT_VIEW_VALIDATORSETUP_H_

#include <QObject>

#include "../ui_ApplicationViewUi.h"

namespace polyclinic
{
class ValidatorSetup : public QObject
{
    Q_OBJECT

public:
    ValidatorSetup(QObject* parent = nullptr);

    void setupValidators(Ui::ApplicationViewUi& ui);

private:
    void setupLineEditValidator(QLineEdit* lineEdit, const QString& regexPattern);
    void setupPatientRegistrationPageValidators(Ui::ApplicationViewUi& ui);
};
}

#endif
