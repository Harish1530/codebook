#ifndef FREEZER_H
#define FREEZER_H

class Freezer
{
    public:
        virtual bool freeze() = 0;
        void store(){
            qInfo() << "Storing food in the freezer";
        }
};
#endif //FREEZER_H