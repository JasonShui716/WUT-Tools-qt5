#include "loginwindow.h"
#include <QApplication>
#include <cstdlib>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginWindow w;
    w.show();

    return a.exec();
}
