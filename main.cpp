#include "keymainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QtMultimedia/QMediaPlayer>

/*void getDir(QString path, int level)
{
    int check = 1;
    QDir folder(path);
    for (QFileInfo temp : folder.entryInfoList())
    {
        if (check > 2)
        {
            //QTreeWidgetItem* item = new QTreeWidgetItem(parent);
            //item->setText(0, temp.absoluteFilePath());
            //ui->fileTreeWidget->addTopLevelItem(item);
            qDebug() << temp.absoluteFilePath();
            if (temp.isDir())
                getDir(temp.absoluteFilePath(), ++level);
        }
        check++;
    }
}*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    KeyMainWindow w;
    w.show();

    //getDir("E:\\Music",0);

     return a.exec();
}
