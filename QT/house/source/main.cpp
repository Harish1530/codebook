#include <QCoreApplication>
#include <QDebug>
#include "appliance.h"

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    // Your code here
    Appliance kitchenrobo;
    qInfo() << "Freezing: " << kitchenrobo.freeze();
    qInfo() << "Baking: " << kitchenrobo.bake();
    qInfo() << "Toasting: " << kitchenrobo.toast();
    kitchenrobo.store();

    kitchenrobo.~Appliance();
    return app.exec();
}