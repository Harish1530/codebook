#ifndef RADIO_H
#define RADIO_H

#include <QObject>
#include <QDebug>
class Radio : public QObject
{
    Q_OBJECT

public:
    explicit Radio(QObject *parent = nullptr);
    ~Radio();


signals:
    void stop();

public slots:
    void listen(int frequency, QString mode, QString message);

};

#endif // RADIO_H