#ifndef POLYCLINIC_APP_CONTROLLER_APPLICATIONCONTROLLER_H_
#define POLYCLINIC_APP_CONTROLLER_APPLICATIONCONTROLLER_H_

#include <QObject>

#include "Model/ApplicationModel.h"
#include "Common/UserType.h"

namespace polyclinic
{
class ApplicationController : public QObject
{
    Q_OBJECT

public:
    ApplicationController(ApplicationModel& model);

    void authenticateUser(const QString& login, const QString& password);

signals:
    void authenticationSuccess(UserType userType);
    void authenticationFailed();

private:
    ApplicationModel& m_model;
};
}

#endif
