#include "keymainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    KeyMainWindow w;
    w.show();

    return a.exec();
}
