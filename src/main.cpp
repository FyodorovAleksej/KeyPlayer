#include "keymainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QtMultimedia/QMediaPlayer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    KeyMainWindow w;
    w.show();
     return a.exec();
}
