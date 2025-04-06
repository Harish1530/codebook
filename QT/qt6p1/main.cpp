#include <QCoreApplication>
#include <QDebug>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::string name;
    int age;

    // Prompt the user for their name and age
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
    std::cout << "Enter your age: ";
    std::cin >> age;

    // Output the user's name and age
    qInfo() << name.c_str() << "is" << age << "years old.";

    return a.exec();
}
