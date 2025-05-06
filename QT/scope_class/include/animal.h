#ifndef ANIMAL_H
#define ANIMAL_H

#include <QObject>
#include <QDebug>

class Animal : public QObject
{
    Q_OBJECT
public:
    explicit Animal(QObject *parent = nullptr, QString name = "");
    virtual ~Animal();
    QString name;

    void makeSound(QString name);
};

#endif // ANIMAL_H