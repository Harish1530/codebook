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

    // Control Statements

    if (age < 18) {
        qInfo() << "You are a minor.";
    } else if (age >= 18 && age < 65) {
        qInfo() << "You are an adult.";
    } else {
        qInfo() << "Damn! Your are old!";
    }

    return a.exec();
}
