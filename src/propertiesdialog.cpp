#include "propertiesdialog.h"
#include "ui_propertiesdialog.h"

PropertiesDialog::PropertiesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PropertiesDialog)
{
    ui->setupUi(this);
    Properties* prop = Properties::loadProperties();
    ui->themeComboBox->addItem("Default");
    ui->themeComboBox->addItem("Calibri");
    ui->themeComboBox->addItem("Dark");
    ui->themeComboBox->addItem("Union");
    ui->themeComboBox->setCurrentText(prop->getTheme());
    const QColor txt = prop->getPalette().buttonText().color();
    ui->themeComboBox->setStyleSheet("QComboBox{color: rgb(" + QString::number(txt.red()) + "," + QString::number(txt.green()) + "," + QString::number(txt.red()) + ")}");
    const QColor but = prop->getPalette().button().color();
    ui->volumeSlider->setStyleSheet("QSlider{color: rgb(" + QString::number(but.red()) + "," + QString::number(but.green()) + "," + QString::number(but.red()) + ")}");
    ui->repeatCheckBox->setChecked(prop->getRepeat());
    ui->volumeSlider->setValue(prop->getVolume());
    ui->volumeSpinBox->setValue(prop->getVolume());
    ui->capsCheckBox->setChecked(prop->getCaps());
    ui->shiftCheckBox->setChecked(prop->getShift());
    ui->themeComboBox->repaint();
    delete prop;
}

PropertiesDialog::~PropertiesDialog()
{
    delete ui;
}
void PropertiesDialog::on_buttonBox_accepted()
{
    emit changeProperties(new Properties(this->getTheme(), this->getRepeat(), this->getVolume(), this->getCaps(), this->getShift()));
}

QString PropertiesDialog::getTheme()
{
    return this->ui->themeComboBox->currentText();
}

bool PropertiesDialog::getRepeat()
{
    return this->ui->repeatCheckBox->isChecked();
}

int PropertiesDialog::getVolume()
{
    return this->ui->volumeSlider->value();
}

bool PropertiesDialog::getCaps()
{
    return this->ui->capsCheckBox->isChecked();
}

bool PropertiesDialog::getShift()
{
    return this->ui->shiftCheckBox->isChecked();
}

void PropertiesDialog::on_volumeSpinBox_valueChanged(int arg1)
{
    this->ui->volumeSlider->setValue(arg1);
}

void PropertiesDialog::on_volumeSlider_valueChanged(int value)
{
    this->ui->volumeSpinBox->setValue(value);
}
