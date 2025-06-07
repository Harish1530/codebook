#include <QCoreApplication>
#include <QDebug>
#include <QTextStream>
#include <iostream>
#include "radio.h"
#include "station.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    qDebug() << "QCoreApplication started.";

    Radio saregama;
    Station* freq[3];

    //Create stations with different frequencies and modes
    freq[0] = new Station(&saregama, 100, "AM");
    freq[1] = new Station(&saregama, 200, "FM");
    freq[2] = new Station(&saregama, 300, "EM");

    //Connect the stations to the radio
    saregama.connect(&saregama, &Radio::stop, &app, &QCoreApplication::quit, Qt::QueuedConnection);

    // //Connect the stations to the radio's listen slot
    // for(int i = 0; i < 3; i++) {
    //     Station* frequency = freq[i];
    //     saregama.connect(frequency, &Station::send, &saregama, &Radio::listen);
    // }

    do
    {
        qInfo() << "Enter on, off, test or quit";
        QTextStream qtin(stdin);
        QString line = qtin.readLine().trimmed().toUpper();

        if (line == "ON"){
            qInfo() << "Radio is ON. Listening to stations...";
            for(int i =0; i<3; i++) {
                Station* frequency = freq[i];
                saregama.connect(frequency, &Station::send, &saregama, &Radio::listen);
            }
            
        }
        else if (line == "OFF"){
            qInfo() << "Radio is OFF. Stopping all stations...";
            for(int i = 0; i< 3; i++) {
                Station* frequency = freq[i];
                saregama.disconnect(frequency, &Station::send, &saregama, &Radio::listen);
            }
            qInfo() << "All stations stopped.";

        }
        else if (line == "TEST") {
            qInfo() << "Testing radio stations...";
            for(int i=0; i<3; i++) {
                Station* frequency = freq[i];
                frequency->broadcast("Broadcasting live message!");
            }
            qInfo() << "Test completed.";
        }
        else if (line == "QUIT") {
            qInfo() << "Quiting application...";
            emit saregama.stop();
            break;
        }
    } while(true);

    return app.exec();
}