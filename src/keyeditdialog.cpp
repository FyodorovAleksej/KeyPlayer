#include "keyeditdialog.h"
#include "ui_keyeditdialog.h"

KeyEditDialog::KeyEditDialog(QWidget *parent, Properties* prop) :
    QDialog(parent),
    ui(new Ui::KeyEditDialog)
{
    this->prop = prop;
    ui->setupUi(this);
    ui->okButton->setEnabled(false);
    ui->volumeSlider->setValue(prop->getVolume());
    ui->volumeSpin->setValue(prop->getVolume());
    ui->repeatBox->setChecked(prop->getRepeat());
}

KeyEditDialog::~KeyEditDialog()
{
    delete ui;
}

void KeyEditDialog::on_keySequenceEdit_editingFinished()
{
    ui->okButton->setEnabled(true);
}

void KeyEditDialog::on_okButton_clicked()
{
    qDebug() << ui->keySequenceEdit->keySequence().toString();
    qDebug() << path->text(0);
    KeyElement* element = new KeyElement(path->text(0));
    element->setItem(path);
    element->setKey(ui->keySequenceEdit->keySequence().toString().at(0));
    element->setVolume(ui->volumeSpin->value());
    element->setRepeated(ui->repeatBox->isChecked());
    emit finish(element);
    this->close();
}

void KeyEditDialog::on_cancelButton_clicked()
{
    this->close();
}

void KeyEditDialog::setPath(QTreeWidgetItem *newPath)
{
    this->path = newPath;
    ui->pathLabel->setText("path: " + path->text(0));
}
