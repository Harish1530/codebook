#include <QCoreApplication>
#include <QDebug>
#include "agecalc.h"

void print(AgeCalc *ageCalc) {
    qInfo() << ageCalc->name() << "Human Years:" << ageCalc->manYears();
    qInfo() << ageCalc->name() << "Dog Years:" << ageCalc->dogYears();
    qInfo() << ageCalc->name() << "Cat Years:" << ageCalc->catYears();
    ageCalc->meow();
}

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    qDebug() << "Qt Core Application is running.";

    AgeCalc harish;

    harish.setName("Harish");
    harish.setAge(25);

    print(&harish);

    

    return app.exec();
}