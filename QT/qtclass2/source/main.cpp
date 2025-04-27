#include <QCoreApplication>
#include "canine.h"
#include "feline.h"

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    // Your application logic here
    Canine dog;
    qInfo() << dog.hasBackBone();
    qInfo() << dog.isAlive();
    Feline cat;
    cat.meow();
    qInfo() << cat.hasBackBone();
    qInfo() << cat.isAlive();

    return app.exec();
}