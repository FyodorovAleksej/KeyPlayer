#ifndef KEYEDITDIALOG_H
#define KEYEDITDIALOG_H

#include <QDialog>
#include <QDebug>
#include "keyelement.h"

namespace Ui {
class KeyEditDialog;
}

class KeyEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit KeyEditDialog(QWidget *parent = 0);
    ~KeyEditDialog();

    QTreeWidgetItem* getPath();
    void setPath(QTreeWidgetItem* newPath);

signals:
    finish(KeyElement* element);
private slots:

    void on_keySequenceEdit_editingFinished();

    void on_okButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::KeyEditDialog *ui;
    QTreeWidgetItem* path;
};

#endif // KEYEDITDIALOG_H
