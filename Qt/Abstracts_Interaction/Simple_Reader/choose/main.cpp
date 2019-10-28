#include "abstracts.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    abstracts w;
    w.show();

    return a.exec();
}
