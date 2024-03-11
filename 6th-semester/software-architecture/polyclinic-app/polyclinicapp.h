#ifndef POLYCLINICAPP_H
#define POLYCLINICAPP_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class PolyclinicApp; }
QT_END_NAMESPACE

class PolyclinicApp : public QMainWindow
{
    Q_OBJECT

public:
    PolyclinicApp(QWidget *parent = nullptr);
    ~PolyclinicApp();

private:
    Ui::PolyclinicApp *ui;
};
#endif // POLYCLINICAPP_H
