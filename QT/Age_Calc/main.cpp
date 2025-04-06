#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>
#include <QDebug>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Enter Your Age: ");

    QLineEdit *ageInput = new QLineEdit(&window);
    ageInput->setPlaceholderText("Enter your age here");
    ageInput->setGeometry(50, 50, 200, 30);

    QPushButton *submitButton = new QPushButton("Submit", &window);
    submitButton->setGeometry(100, 100, 100, 30);

    QLabel *infoLabel = new QLabel(&window);
    infoLabel->setGeometry(50, 140, 200, 30);
    infoLabel->setStyleSheet("font-weight: bold;");

    window.resize(300, 200);
    window.setStyleSheet("background-color: lightblue;");
    window.show();

    QObject::connect(submitButton, &QPushButton::clicked, [&]() {
        QString ageStr = ageInput->text();
        bool ok;
        int age = ageStr.toInt(&ok);

        if (ok && age >= 1 && age <= 120) {
            int dogYears = age * 7;
            QString message = "Your age in dog years is: " + QString::number(dogYears);
            qDebug() << message;

            QMessageBox::information(&window, "Age in Dog Years", message, QMessageBox::Ok);
            infoLabel->setText(message);
        } else {
            QString error = "Invalid age entered!";
            qWarning() << error;
            QMessageBox::warning(&window, "Invalid Input", error, QMessageBox::Ok);
            infoLabel->setText(error);
        }
    });

    return app.exec();
}
