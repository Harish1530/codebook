#include "test.h"

Test::Test(QObject *parent) : QObject(parent)
{
    qDebug() << "Test object created";
}
Test::~Test()
{
    qDebug() << "Test object destroyed";
}
void Test::kill()
{
    qDebug() << "Test object killed";
    emit close("Test object killed");
}