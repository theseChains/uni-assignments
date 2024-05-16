#include "ApplicationController.h"

namespace polyclinic
{
ApplicationController::ApplicationController(ApplicationModel& model)
    : m_model{ model }
{
}

void ApplicationController::authenticateUser(const QString& login, const QString& password)
{
    UserType userType{ m_model.authenticateUser(login, password) };
    if (userType != UserType::kNone)
    {
        emit authenticationSuccess(userType);
    }
    else
    {
        emit authenticationFailed();
    }
}
}
