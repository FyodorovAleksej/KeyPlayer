#ifndef ROOTDIALOG_H
#define ROOTDIALOG_H

#include <QDialog>

namespace Ui {
class RootDialog;
}

class RootDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RootDialog(QWidget *parent = 0);
    ~RootDialog();

signals:
    void okButton(QString str);

private slots:

    void on_cancelButton_clicked();
    void on_okButton_clicked();
    void on_rootEdit_textEdited(const QString &arg1);

private:
    Ui::RootDialog *ui;
};

#endif // ROOTDIALOG_H
