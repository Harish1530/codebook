#include "appliance.h"

Appliance::Appliance(QObject *parent) : QObject(parent) {
    // Constructor implementation
    qInfo() << "Appliance created";
}

Appliance::~Appliance() {
    // Destructor implementation
    qInfo() << "Appliance destroyed";
}

bool Appliance::freeze() {
    
    return true;
}

bool Appliance::bake() {
    
    return true;
}

bool Appliance::toast() {
    return true;
}
void Appliance::store() {
    qInfo() << "Storing food in the freezer";

    Freezer::store();
}
