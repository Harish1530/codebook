#ifndef MOCKCAN_H
#define MOCKCAN_H

#include <QObject>
#include <QTimer>

class MockCAN : public QObject {
    Q_OBJECT
public:
    explicit MockCAN(QObject *parent = nullptr);
    Q_INVOKABLE void startMock();
    Q_INVOKABLE void stopMock();

signals:
    void speedChanged(float speed);
    void rpmChanged(float rpm);
    void fuelLevelChanged(float fuelLevel);

private slots:
    void generateMockData();

private:
    QTimer *timer;
};

#endif // MOCKCAN_H