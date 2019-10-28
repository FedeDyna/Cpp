#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // declare the splashs

    QSplashScreen *splash1=new QSplashScreen;
    splash1->setPixmap(QPixmap("/home/fede/Qt5.7.0/Examples/C++_examples/example_C++_3_my_code/figure1.png"));
    splash1->show();

    // I need the timer to start my application after some time
    MainWindow w;

    QTimer::singleShot(2500,splash1,SLOT(close())); // time in millisenconds after 2.5 sec close the splash
    QTimer::singleShot(2500,&w,SLOT(show()) ); //after the splash show() the application

   // w.show(); // I do not need it anylonger since I put inside SLOT

    return a.exec();
}
