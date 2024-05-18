#include <QCoreApplication>

#include "Server.h"

int main(int argc, char* argv[])
{
    QCoreApplication app{ argc, argv };

    polyclinic::Server server;
    if (!server.isListening()) {
        qCritical() << "Failed to start server!";
        return -1;
    }

    return app.exec();
}
