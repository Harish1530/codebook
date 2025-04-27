#ifndef FELINE_H
#define FELINE_H

#include <QObject>
#include <QDebug>
#include "mammal.h"

class Feline : public Mammal
{
    Q_OBJECT

public:
    explicit Feline(QObject *parent = nullptr);
    ~Feline();

    void meow(){
        qInfo() << this << "meow";
    }


signals:
//    void soundMade(const QString &sound);

// public slots:
//     void makeSound(const QString &sound);
};

#endif // FELINE_H