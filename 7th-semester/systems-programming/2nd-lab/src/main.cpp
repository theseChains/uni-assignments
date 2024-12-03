#include <QApplication>

#include "ApplicationWindow.h"

int main(int argc, char** argv)
{
    QApplication app{ argc, argv };

    systems_programming::ApplicationWindow window{};
    window.show();
    window.setWindowTitle("Двухпросмотровый ассемблер для программы в абсолютном формате");

    return app.exec();
}
