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

    // qFatal kills the program
    // qFatal("This is a fatal error message.");
    
    // Control Statements

    if (age < 18) {
        qInfo() << "You are a minor.";
    } else if (age >= 18 && age < 65) {
        qInfo() << "You are an adult.";
    } else {
        qInfo() << "Damn! Your are old!";
    }
    // Loop Statements
    // Do while loop
    int i = 80;
    do {
        qInfo() << "The value of i is" << i;
        i++;
    } while (i < 100);
    // While loop
    i = 0;
    while (i < 10) {
        qInfo() << "The value of i is" << i;
        i++;
    }

    return a.exec();
}
