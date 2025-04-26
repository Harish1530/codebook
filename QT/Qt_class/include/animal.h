#ifndef ANIMAL_H
#define ANIMAL_H

#include <QObject>
#include <QDebug>
#include <QString>

class Animal : public QObject
{
    Q_OBJECT
public:
    //Constructor
    explicit Animal(QObject *parent = nullptr, QString name = "Animal");
    //Destructor
    virtual ~Animal();

    void makeSound(QString message);
    int weight;
    QString name;
    double askingPrice();
    void test();

signals:


};

#endif // ANIMAL_H