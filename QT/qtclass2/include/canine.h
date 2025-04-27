#ifndef CANINE_H
#define CANINE_H

#include <QObject>
#include <QDebug>
#include "mammal.h"

class Canine : public Mammal
{
    Q_OBJECT

public:
    explicit Canine(QObject *parent = nullptr);
    ~Canine();

    void bark()
    {
        qInfo() << this << "bark";
    }

signals:
//    void soundMade(const QString &sound);

// public slots:
//     void makeSound(const QString &sound);
};

#endif // FELINE_H