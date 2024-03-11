#include "polyclinicapp.h"
#include "ui_polyclinicapp.h"

PolyclinicApp::PolyclinicApp(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PolyclinicApp)
{
    ui->setupUi(this);
}

PolyclinicApp::~PolyclinicApp()
{
    delete ui;
}

