#ifndef KEYMAINWINDOW_H
#define KEYMAINWINDOW_H
#include "keyelement.h"
#include <QMainWindow>
#include <QFileDialog>
#include <QDebug>
#include <QListWidgetItem>
#include "playwindow.h"
#include "keyeditdialog.h"
namespace Ui {
class KeyMainWindow;
}

/**
 * @brief The KeyMainWindow class the main window with main interface
 */
class KeyMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit KeyMainWindow(QWidget *parent = 0);
    ~KeyMainWindow();

    /**
     * @brief addInList adding key element in list of keys elements and in GUI ListWidget
     * @param element the key elment for ading
     */
    void addInList(KeyElement* element);

public slots:
    /**
     * @brief on_editButton_clicked the action, when "Edit" button was clicked
     */
    void on_editButton_clicked();
    /**
     * @brief on_addButton_clicked the action, when "Add" button was clicked
     */
    void on_addButton_clicked();

    /**
     * @brief on_deleteButton_clicked the action, when "Delete" button was clicked
     */
    void on_deleteButton_clicked();

    /**
     * @brief on_deleteAllButton_clicked the action, when "Delete all" button was clicked
     */
    void on_deleteAllButton_clicked();

    /**
     * @brief on_playButton_clicked the action, when "Play" button was clicked
     */
    void on_playButton_clicked();

    /**
     * @brief on_fileTreeWidget_doubleClicked the action, when item on TreeWidget was doubleClicked (Edit)
     * @param index
     */
    void on_fileTreeWidget_doubleClicked(const QModelIndex &index);

    /**
     * @brief on_keyListWidget_doubleClicked the action, when item on ListWidget was doubleClicked (Listening)
     * @param index
     */
    void on_keyListWidget_doubleClicked(const QModelIndex &index);

    /**
     * @brief startPlay start playing key element with KEY
     * @param key the key of element for playing
     */
    void startPlay(QChar key);
    /**
     * @brief stopPlay stop playing key element with KEY
     * @param key the key of element for stopping
     */
    void stopPlay(QChar key);
    /**
     * @brief stopAllPlay stopped all key elements
     */
    void stopAllPlay();

    /**
     * @brief editOk shen Key Element was created (after edit window)
     * @param element the element, that was created
     */
    void editOk(KeyElement* element);
private slots:

    /**
     * @brief on_actionSaveFile_triggered saving current key list in file
     */
    void on_actionSaveFile_triggered();

    /**
     * @brief on_actionOpenFile_triggered opening saved key list from file
     */
    void on_actionOpenFile_triggered();

    /**
     * @brief on_actionSaveFileMenu_triggered saving current key list in file
     */
    void on_actionSaveFileMenu_triggered();

    /**
     * @brief on_actionOpenFileMenu_triggered opening saved key list from file
     */
    void on_actionOpenFileMenu_triggered();

    /**
     * @brief logging added message for logging (Info: ...)
     * @param message message for logging
     */
    void logging(QString message);

    /**
     * @brief fileInfo output file info into File Info Label
     * @param info the message for output
     */
    void fileInfo(QString info);

    /**
     * @brief on_autoButton_clicked auto filling music files
     */
    void on_autoButton_clicked();

    /**
     * @brief on_keyListWidget_itemClicked when item in Key List was clicked. Out info about file
     * @param item clicked item
     */
    void on_keyListWidget_itemClicked(QListWidgetItem *item);

private:

    /**
     * @brief getDir adding dirictory (folder) for it's Tree view. Added only files (.mp3 / .wav) and folders
     * @param path the path of folder/file
     * @param parent the parent folder
     * @return the path of the last added file
     */
    QTreeWidgetItem* getDir(QString path, QTreeWidgetItem* parent);

    /**
     * @brief autoFill recursive autofilling. Using for iterate childs in tree
     * @param current current root of tree
     * @return is full filling keyboard?
     */
    bool autoFill(QTreeWidgetItem* current);

    Ui::KeyMainWindow *ui;

    QList<KeyElement*> keys;

    QList<QTreeWidgetItem*> treeItems;

    bool shift;
    bool prelistening;

    char sum;
};

#endif // KEYMAINWINDOW_H
