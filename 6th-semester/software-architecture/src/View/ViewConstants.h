#ifndef POLYCLINIC_APP_VIEW_VIEWCONSTANTS_H_
#define POLYCLINIC_APP_VIEW_VIEWCONSTANTS_H_

#include <QString>
#include <QStringView>

namespace polyclinic::constants
{
inline const QString kLoginPage{ "LoginPage" };
inline const QString kRegistratorPage{ "RegistratorPage" };
inline const QString kAdministratorPage{ "AdministratorPage" };
inline const QString kSeachClientsPage{ "SearchClientsPage" };
inline const QString kFoundClientsPage{ "FoundClientsPage" };
inline const QString kClientInfoPage{ "ClientInfoPage" };
inline const QString kTalonPage{ "TalonPage" };

inline constexpr int kNumberOfClientsTableColumns{ 4 };
}

#endif
