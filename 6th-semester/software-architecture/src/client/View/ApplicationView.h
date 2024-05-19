#ifndef POLYCLINIC_APP_VIEW_APPLICATIONVIEW_H_
#define POLYCLINIC_APP_VIEW_APPLICATIONVIEW_H_

#include <array>
#include <vector>

#include <QMainWindow>
#include <QStackedWidget>

#include "client/View/ButtonHandlers/RegistratorButtonsHandler.h"
#include "common/UserType.h"
#include "client/Facade/Facade.h"

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
    void onAuthenticationSuccess(UserType userType);
    void onAuthenticationFailed();

private:
    bool foundClients();

private:
    Ui::ApplicationViewUi* m_ui{};
    Facade* m_facade{};

    RegistratorButtonsHandler m_registratorButtonsHandler{};
};
}

#endif
