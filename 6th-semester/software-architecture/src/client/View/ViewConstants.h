#ifndef POLYCLINIC_APP_VIEW_VIEWCONSTANTS_H_
#define POLYCLINIC_APP_VIEW_VIEWCONSTANTS_H_

#include <QString>
#include <QStringView>

#include <unordered_map>

namespace polyclinic::constants
{
inline const QString kLoginPage{ "LoginPage" };
inline const QString kRegistratorPage{ "RegistratorPage" };
inline const QString kAdministratorPage{ "AdministratorPage" };
inline const QString kDoctorPage{ "DoctorPage" };
inline const QString kSeachClientsPage{ "SearchClientsPage" };
inline const QString kFoundClientsPage{ "FoundClientsPage" };
inline const QString kClientInfoPage{ "ClientInfoPage" };
inline const QString kTalonPage{ "TalonPage" };
inline const QString kListOfAppointedClientsPage{ "ListOfAppointedClientsPage" };
inline const QString kOutpatientCardPage{ "OutpatientCardPage" };

inline constexpr int kNumberOfClientsTableColumns{ 5 };
}

#endif
