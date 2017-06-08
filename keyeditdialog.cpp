#include "keyeditdialog.h"
#include "ui_keyeditdialog.h"

KeyEditDialog::KeyEditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KeyEditDialog)
{
    ui->setupUi(this);
}

KeyEditDialog::~KeyEditDialog()
{
    delete ui;
}
