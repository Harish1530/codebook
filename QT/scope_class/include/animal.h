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
    static int count;

    void makeSound(QString name);
    static void getCount();
};

#endif // ANIMAL_H