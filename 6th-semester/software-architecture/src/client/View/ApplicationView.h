#ifndef POLYCLINIC_APP_VIEW_APPLICATIONVIEW_H_
#define POLYCLINIC_APP_VIEW_APPLICATIONVIEW_H_

#include <array>
#include <vector>

#include <QMainWindow>
#include <QStackedWidget>

#include "client/View/ButtonHandlers/RegistratorButtonsHandler.h"
#include "client/View/ButtonHandlers/AdministratorButtonsHandler.h"
#include "client/View/ValidatorSetup.h"
#include "common/UserType.h"
#include "client/Client.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ApplicationViewUi; }
QT_END_NAMESPACE

namespace polyclinic
{
// change the name of the class maybe?
class ApplicationView : public QMainWindow
{
    Q_OBJECT

public:
    explicit ApplicationView(QWidget *parent = nullptr);
    ~ApplicationView();

private slots:
    void onLoginButtonClicked();
    void onOpenOutpatientCardButtonClicked();
    void onAuthentication(std::pair<UserType, int> data);

    void displayErrorMessage(const QString& message);

private:
    Ui::ApplicationViewUi* m_ui{};
    Client* m_client{};

    RegistratorButtonsHandler m_registratorButtonsHandler;
    AdministratorButtonsHandler m_adminButtonsHandler;

    ValidatorSetup m_validatorSetup;
};
}

#endif
