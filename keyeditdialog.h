#ifndef KEYEDITDIALOG_H
#define KEYEDITDIALOG_H

#include <QDialog>

namespace Ui {
class KeyEditDialog;
}

class KeyEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit KeyEditDialog(QWidget *parent = 0);
    ~KeyEditDialog();

private:
    Ui::KeyEditDialog *ui;
};

#endif // KEYEDITDIALOG_H
