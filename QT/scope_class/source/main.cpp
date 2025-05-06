#include <QCoreApplication>
#include <QDebug>
#include "animal.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "Hello, World!";

    QString name = "Dog";
    qInfo() << "Animal name:" << &name;

    Animal cat(&a, "Tom");
    Animal dog(&a, "Jerry");

    qInfo() << cat.name;
    qInfo() << dog.name;

    cat.~Animal();

    return a.exec();
}