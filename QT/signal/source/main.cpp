#include <QCoreApplication>
#include "source.h"
#include "destination.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Your application logic here
    Source source;
    Destination destination;
    QObject::connect(&source,&Source::mySignal, &destination, &Destination::mySlot);

    source.test();
    // Start the event loop
    destination.mySlot("Hello from main!");
    return a.exec();
}