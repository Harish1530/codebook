#ifndef SOURCE_H
#define SOURCE_H

#include <QObject>
#include <QDebug>


class Source : public QObject
{
    Q_OBJECT

public:
    explicit Source(QObject *parent = nullptr);
    ~Source();

    void test();

signals:
    void mySignal(QString message);
    // Define your signals here

public slots:
    // Define your slots here

private:
    // Private members
};

#endif // SOURCE_H