#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QString>
#include <QDebug>

class Test : public QObject
{
    Q_OBJECT

public:
    explicit Test(QObject *parent = nullptr);
    ~Test();

    void kill();

signals:
    void close(QString reason);

public slots:

};

#endif // TEST_H