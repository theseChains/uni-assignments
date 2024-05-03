#ifndef POLYCLINIC_APP_CONTROLLER_APPLICATIONCONTROLLER_H_
#define POLYCLINIC_APP_CONTROLLER_APPLICATIONCONTROLLER_H_

#include "Model/ApplicationModel.h"

namespace polyclinic
{
class ApplicationController
{
public:
    ApplicationController(ApplicationModel& model);

private:
    ApplicationModel& m_model;
};
}

#endif
