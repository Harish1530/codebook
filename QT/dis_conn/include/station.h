#ifndef STATION_H
#define STATION_H

#include <QObject>
#include <QDebug>

class Station : public QObject
{
    Q_OBJECT

public:
    explicit Station(QObject *parent = nullptr, int frequency = 0, QString mode = "unknown");
    ~Station();
    QString mode;
    int frequency;

signals:
    // Add your signals here
    void send(int frequency, QString mode, QString message);

public slots:
    // Add your slots here
    void broadcast(QString message);

private:
    // Add your private members here
};

#endif // STATION_H