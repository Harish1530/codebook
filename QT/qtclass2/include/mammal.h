#ifndef MAMMAL_H
#define MAMMAL_H

#include <QObject>
#include <QDebug>
#include "animal.h"

class Mammal : public Animal
{
    Q_OBJECT

public:
    explicit Mammal(QObject *parent = nullptr);
    ~Mammal();

    bool hasBackBone()
    {
        return true;
    }

signals:
//    void soundMade(const QString &sound);

// public slots:
//     void makeSound(const QString &sound);
};

#endif // MAMMAL_H