#ifndef KEYMAINWINDOW_H
#define KEYMAINWINDOW_H
#include "keyelement.h"
#include <QMainWindow>
#include <QFileDialog>
#include <QDebug>
#include <QListWidgetItem>
#include "playwindow.h"
#include "keyeditdialog.h"
#include "propertiesdialog.h"
#include "tryplayer.h"
#include "properties.h"
namespace Ui {
class KeyMainWindow;
}

/**
 * @brief The KeyMainWindow class of the main window with main interface and logic system, that can be used for manipulate all system
 */
class KeyMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit KeyMainWindow(QWidget *parent = 0);
    ~KeyMainWindow();

    /**
     * @brief addInList adding key element in list of keys elements and in GUI ListWidget
     * @param element the key element for adding
     */
    void addInList(KeyElement* element);

public slots:
    /**
     * @brief on_editButton_clicked the action, when "Edit" button was clicked
     * create edit window and link it with slot editOK.
     */
    void on_editButton_clicked();
    /**
     * @brief on_addButton_clicked the action, when "Add" button was clicked
     * create window of choosing dirivtory for adding folder with music files.
     */
    void on_addButton_clicked();

    /**
     * @brief on_deleteButton_clicked the action, when "Delete" button was clicked
     * delete choosed keyElement from QListWidget
     */
    void on_deleteButton_clicked();

    /**
     * @brief on_deleteAllButton_clicked the action, when "Delete all" button was clicked
     * delete all keyElements from all tabs
     */
    void on_deleteAllButton_clicked();

    /**
     * @brief on_playButton_clicked the action, when "Play" button was clicked
     * open PlayWindow and connect it with logiv system of processing pressed keys
     */
    void on_playButton_clicked();

    /**
     * @brief on_fileTreeWidget_doubleClicked the action, when item on TreeWidget was doubleClicked (Edit)
     * @param index index of current item
     * open editWindow for creating keyElement with current music file in QTreeWidget
     */
    void on_fileTreeWidget_doubleClicked(const QModelIndex &index);

    /**
     * @brief on_keyListWidget_doubleClicked the action, when item on ListWidget was doubleClicked (Listening)
     * @param index index of current item
     * play this file in keyList or stoping
     */
    void on_keyListWidget_doubleClicked(const QModelIndex &index);

    /**
     * @brief start - the slot, that starts playing music file with this key
     * @param key - the key of music file for playing
     * @param page - the current page of keypad
     */
    void start(QChar key, int page);

    /**
     * @brief stop - the slot, that stop playing music file with this key
     * @param key - the key of music file for stoping
     * @param page - the current page of keypad
     */
    void stop(QChar key, int page);

    /**
     * @brief stopAllPlay stopped all key elements
     * stopping all music files from all tabs, that can be used
     */
    void stopAllPlay();

    /**
     * @brief editOk when Key Element was created (after edit window)
     * @param element the element, that was created
     * adding new element with all propertyes into KeyList and QListWidget
     */
    void editOk(KeyElement* element);
private slots:

    /**
     * @brief on_actionSaveFile_triggered saving current key list in file
     * file extension - "*.kpl"
     */
    void on_actionSaveFile_triggered();

    /**
     * @brief on_actionOpenFile_triggered opening saved key list from file
     * file extension - "*.kpl"
     */
    void on_actionOpenFile_triggered();

    /**
     * @brief on_actionSaveFileMenu_triggered saving current key list in file
     * file extension - "*.kpl"
     */
    void on_actionSaveFileMenu_triggered();

    /**
     * @brief on_actionOpenFileMenu_triggered opening saved key list from file
     * file extension - "*.kpl"
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
     * output file name and duration of current file
     */
    void fileInfo(QString info);

    /**
     * @brief on_autoButton_clicked auto filling music files
     * filling in next rules:
     * for all valid files in treeWidget:
     * tabs: 0 -> 9
     *      keys 'a' -> 'z'
     */
    void on_autoButton_clicked();

    /**
     * @brief on_keyListWidget_itemClicked when item in Key List was clicked. Out info about file
     * @param item clicked item
     * getting information about file and writing it into special label
     */
    void on_keyListWidget_itemClicked(QListWidgetItem *item);

    /**
     * @brief on_actionProperties_triggered action for opening window with settings of all application
     */
    void on_actionProperties_triggered();

    /**
     * @brief changeMainProp slot for changing properties for all application
     * @param prop object with all settings needed for changing default params
     */
    void changeMainProp(Properties* prop);

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

    /**
     * @brief getCurrentPage getting current active tab
     * @return the number of current active tab (0 - 9)
     */
    int getCurrentPage();

    Ui::KeyMainWindow *ui;

    QList<QList<KeyElement*>*> keys;

    QList<QTreeWidgetItem*> treeItems;

    bool shift;
    bool prelistening;

    QList<QListWidget*> keyPagesList;
    int currentPage;
    char sum;

    Properties* prop;
};

#endif // KEYMAINWINDOW_H
