#ifndef KEYMAINWINDOW_H
#define KEYMAINWINDOW_H
#include "keyelement.h"
#include <QMainWindow>
#include "playwindow.h"
namespace Ui {
class KeyMainWindow;
}

class KeyMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit KeyMainWindow(QWidget *parent = 0);
    ~KeyMainWindow();

    void addInList(KeyElement* element);
    QString createDir(QString path, int level, QTreeWidgetItem* item);

public slots:
    void on_editButton_clicked();
    void on_addButton_clicked();
    void on_deleteButton_clicked();
    void on_deleteAllButton_clicked();
    void on_playButton_clicked();
    void on_fileTreeWidget_doubleClicked(const QModelIndex &index);
    void on_keyListWidget_doubleClicked(const QModelIndex &index);
    void startPlay(QChar key);
    void stopPlay(QChar key);
    void stopAllPlay();
private:
    Ui::KeyMainWindow *ui;

    QList<KeyElement*> keys;
    int shift;
    int stop;
};

#endif // KEYMAINWINDOW_H
