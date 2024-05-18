#include "StackedWidgetNavigator.h"

namespace polyclinic
{
void StackedWidgetNavigator::navigateToPage(QStackedWidget& widget, const QString& pageName)
{
    for (int i{ 0 }; i < widget.count(); ++i)
    {
        QWidget* foundWidget{ widget.widget(i) };
        if (foundWidget && foundWidget->objectName() == pageName)
        {
            widget.setCurrentIndex(i);
            // maybe do some error handling?
            return;
        }
    }
}
}
