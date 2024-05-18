#ifndef POLYCLINIC_APP_VIEW_STACKEDWIDGETNAVIGATOR_H_
#define POLYCLINIC_APP_VIEW_STACKEDWIDGETNAVIGATOR_H_

#include <QStackedWidget>
#include <QString>

namespace polyclinic
{
class StackedWidgetNavigator
{
public:
    static void navigateToPage(QStackedWidget& widget, const QString& pageName);
};
}

#endif
