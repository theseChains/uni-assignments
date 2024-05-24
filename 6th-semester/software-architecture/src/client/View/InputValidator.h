#ifndef POLYCLINIC_APP_VIEW_INPUTVALIDATOR_H_
#define POLYCLINIC_APP_VIEW_INPUTVALIDATOR_H_

#include "ui_ApplicationViewUi.h"

namespace polyclinic
{
class InputValidator
{
public:
    static QString patientRegistrationInputIsValid(const Ui::ApplicationViewUi& ui);
};
}

#endif
