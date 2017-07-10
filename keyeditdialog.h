#ifndef KEYEDITDIALOG_H
#define KEYEDITDIALOG_H

#include <QDialog>
#include <QDebug>
#include "keyelement.h"

namespace Ui {
class KeyEditDialog;
}

/**
 * @brief The KeyEditDialog class of window for binding key for music file, and setup some properties for it's playing
 */
class KeyEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit KeyEditDialog(QWidget *parent = 0);
    ~KeyEditDialog();

    /**
     * @brief setPath setting path of current file for setting propeties of playing this file
     * @param newPath the path for setting
     */
    void setPath(QTreeWidgetItem* newPath);

signals:
    /**
     * @brief finish the signal of correct ending editing.
     * @param element the result of editing. The key element with setted properties
     */
    finish(KeyElement* element);
private slots:

    /**
     * @brief on_keySequenceEdit_editingFinished the action, when property key was pressed
     */
    void on_keySequenceEdit_editingFinished();

    /**
     * @brief on_okButton_clicked the action, when "OK" button was pressed
     */
    void on_okButton_clicked();

    /**
     * @brief on_cancelButton_clicked the action, when "Cancel" button was pressed
     */
    void on_cancelButton_clicked();

private:
    Ui::KeyEditDialog *ui;
    QTreeWidgetItem* path;
};

#endif // KEYEDITDIALOG_H
