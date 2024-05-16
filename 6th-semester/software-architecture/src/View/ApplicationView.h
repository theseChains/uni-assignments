#ifndef POLYCLINIC_APP_VIEW_APPLICATIONVIEW_H_
#define POLYCLINIC_APP_VIEW_APPLICATIONVIEW_H_

#include <array>
#include <vector>

#include <QMainWindow>
#include <QStackedWidget>

#include "Controller/ApplicationController.h"
#include "View/ButtonHandlers/RegistratorButtonsHandler.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ApplicationViewUi; }
QT_END_NAMESPACE

namespace polyclinic
{
class ApplicationView : public QMainWindow
{
    Q_OBJECT

public:
    ApplicationView(ApplicationController& controller, QWidget *parent = nullptr);
    ~ApplicationView();

private slots:
    void onLoginButtonClicked();
    void onOpenOutpatientCardButtonClicked();
    void onAuthenticationSuccess(UserType userType);
    void onAuthenticationFailed();

private:
    bool foundClients();

private:
    ApplicationController& m_controller;
    int m_lastClientStackedWidgetIndex{};
    Ui::ApplicationViewUi* m_ui;
    RegistratorButtonsHandler m_registratorButtonsHandler{};
};
}

#endif
