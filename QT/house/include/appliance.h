#ifndef APPLIANCE_H
#define APPLIANCE_H

#include <QObject>
#include <QDebug>
#include "freezer.h"
#include "oven.h"
#include "toaster.h"

class Appliance : public QObject, Freezer, Oven, Toaster
{
    Q_OBJECT

public:
    explicit Appliance(QObject *parent = nullptr);
    ~Appliance();

    // Freezer interface 
    bool freeze();

    //Oven Interface
    bool bake();

    // Toaster interface
    bool toast();

    void store();

signals:
//     void turnedOn();
//     void turnedOff();

// public slots:
//     void turnOn();
//     void turnOff();

};

#endif // APPLIANCE_H