#include <QCoreApplication>
#include "animal.h"

void test(Animal &cat){
    cat.test();
}

void cutAnimals()
{
    // On the stack
    Animal mine(nullptr, "Mine");
    Animal yours(nullptr, "Yours");
    mine.weight = 10;
    yours.weight = 20;

    test(mine);
    test(yours);
    // Deleted from stack
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Your application logic here
    Animal cat;
    Animal dog;

    cat.setObjectName("Pussy");
    dog.setObjectName("Motty");

    cat.makeSound("Meow");
    cat.~Animal();
    dog.makeSound("Woof");
    
    Animal malecat;
    malecat.setObjectName("Tom");
    malecat.makeSound("Another Meow");

    cutAnimals();
    

    return a.exec();
}