#ifndef CALC_H
#define CALC_H

#include <QObject>

class Calc : public QObject
{
    Q_OBJECT

public:
    explicit Calc(QObject *parent = nullptr);
    ~Calc();
    int dogYears(int age) const;
    int catYears(int age) const;

signals:
    // Add your signals here

public slots:
    // Add your slots here

private:
    // Add your private members here
};

#endif // CALC_H
