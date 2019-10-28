#include "website.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    website w;
    w.show();

    return a.exec();
}
