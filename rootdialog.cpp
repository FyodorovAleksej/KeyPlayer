#include "rootdialog.h"
#include "ui_rootdialog.h"

RootDialog::RootDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RootDialog)
{
    ui->setupUi(this);
}

RootDialog::~RootDialog()
{
    delete ui;
}

void RootDialog::on_cancelButton_clicked()
{

}

void RootDialog::on_okButton_clicked()
{

}

void RootDialog::on_rootEdit_textEdited(const QString &arg1)
{

}
