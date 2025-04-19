#include <QCoreApplication>
#include <QDebug>
#include <iostream>

int get_size(){
    int val = 0;
    std::cout << "Enter the value or 0 to Exit: " << std::endl;
    std::cin >> val;
    return val;
}

double calc_paint(int w, int h){
    double area = w * h;
    double paint = area * 10;
    return paint;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    double paint = 0;
    qInfo() << "Enter the ceiling height: ";
    int height = get_size();

    if(height <= 0) qFatal("Invalid height");

    do {
        qInfo() << "Enter Wall Width: ";
        int width = get_size();
        if(width <= 0) break;
        double g = calc_paint(width, height);
        paint += g;
    } while (true);

    qInfo() << "Total Paint Required: " << paint << " liters";

    return a.exec();
}
