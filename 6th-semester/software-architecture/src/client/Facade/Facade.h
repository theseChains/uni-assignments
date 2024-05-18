#ifndef POLYCLINIC_APP_CLIENT_FACADE_H_
#define POLYCLINIC_APP_CLIENT_FACADE_H_

#include <QObject>

// todo: change later please!
#include "../../common/data/LoginInputData.h"
#include "../../common/UserType.h"
#include "../Client.h"

namespace polyclinic
{
class Facade : public QObject
{
    Q_OBJECT

public:
    explicit Facade(QObject* parent = nullptr);

    void login(const LoginInputData& inputData);

signals:
    void loginResult(UserType userType);

private slots:
    void onClientLoginResult(UserType userType);

private:
    // should this be a pointer?
    Client* m_client{};
};
}

#endif
