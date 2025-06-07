#include <QCoreApplication>
#include <QDebug>
#include "monitor.h"
#include "test.h"

int main(int argc, char *argv[]){
    QCoreApplication a(argc, argv);

    qDebug() << "Application started";

    Monitor monitor;
    Test test;

    test.connect(&test, &Test::close, &monitor, &Monitor::closing);
    QObject::connect(&test, &Test::close,&a, &QCoreApplication::quit, Qt::QueuedConnection);
    
    test.kill();

    int l = a.exec();
    qInfo() << "Exit code:" << l;
    return l;
}