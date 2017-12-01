#ifndef KEYEDITDIALOG_H
#define KEYEDITDIALOG_H

#include <QDialog>
#include <QDebug>
#include "keyelement.h"
#include "properties.h"

namespace Ui {
class KeyEditDialog;
}

/**
 * @brief The key_edit_dialog class of window for binding key for music file, and setup some properties for it's playing
 * such as: Volume - the volume of music file, that will played
 *              Repeating - file will repeated, when it was finished
 *              Key - the key, that will linked with this music file
 */
class KeyEditDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief key_edit_dialog - creating new key_edit_dialog window for build KeyElement
     * @param parent parent object for destroying
     * @param prop object with properties
     */
    explicit KeyEditDialog(QWidget *parent = nullptr, Properties *prop = nullptr);
    ~KeyEditDialog();

    /**
     * @brief setPath setting path of current file for setting propeties of playing this file
     * @param new_path the path for setting
     */
    void SetPath(QTreeWidgetItem* new_path);

signals:
    /**
     * @brief finish the signal of correct ending editing.
     * @param element the result of editing. The key element with setted properties
     */
    void finish(KeyElement* element);
private slots:

    /**
     * @brief on_keySequenceEdit_editingFinished the action, when property key was pressed.
     * unblocked OK Button
     */
    void OnKeySequenceEditEditingFinished() const;

    /**
     * @brief on_okButton_clicked the action, when "OK" button was pressed
     * closed window and send properties to main window
     */
    void OnOkButtonClicked();

    /**
     * @brief on_cancelButton_clicked the action, when "Cancel" button was pressed
     * closed window and don't send signal to main window
     */
    void OnCancelButtonClicked();

private:

    void Initialize();

    void InitializeButtonsConnections();

    void InitializeSpecificConnections();

    Ui::KeyEditDialog *ui_;
    QTreeWidgetItem* path_;
    Properties* prop_;
};

#endif // KEYEDITDIALOG_H
