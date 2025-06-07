#ifndef MONITOR_H
#define MONITOR_H

#include <QObject>
#include <QString>
#include <QDebug>

class Monitor : public QObject
{
    Q_OBJECT

public:
    explicit Monitor(QObject *parent = nullptr);
    ~Monitor();

    

signals:
    

public slots:
    void closing(QString reason);

};

#endif // MONITOR_H