#include "Facade.h"

namespace polyclinic
{
Facade::Facade(QObject* parent)
    : QObject{ parent }, m_client{ new Client{ this } }
{
    connect(m_client, &Client::loginResult, this, &Facade::onClientLoginResult);
    m_client->connectToServer();
}

void Facade::login(const LoginInputData& inputData)
{
    m_client->sendLoginRequest(inputData);
}

void Facade::onClientLoginResult(UserType userType)
{
    emit loginResult(userType);
}
}
