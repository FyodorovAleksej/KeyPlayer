#include "propertiesdialog.h"
#include "ui_propertiesdialog.h"

PropertiesDialog::PropertiesDialog(QWidget *parent) :
    QDialog(parent),
    ui_(new Ui::PropertiesDialog)
{
    ui_->setupUi(this);
    Initialize();
}

PropertiesDialog::~PropertiesDialog()
{
    delete ui_;
}
void PropertiesDialog::OnButtonBoxAccepted()
{
    emit changeProperties(new Properties(this->GetTheme(), this->GetRepeat(), this->GetVolume(), this->GetCaps(), this->GetShift()));
}

QString PropertiesDialog::GetTheme() const
{
    return this->ui_->themeComboBox->currentText();
}

bool PropertiesDialog::GetRepeat() const
{
    return this->ui_->repeatCheckBox->isChecked();
}

int PropertiesDialog::GetVolume() const
{
    return this->ui_->volumeSlider->value();
}

bool PropertiesDialog::GetCaps() const
{
    return this->ui_->capsCheckBox->isChecked();
}

bool PropertiesDialog::GetShift() const
{
    return this->ui_->shiftCheckBox->isChecked();
}

void PropertiesDialog::Initialize()
{
    Properties* prop = Properties::LoadProperties();

    ui_->themeComboBox->addItem("Default");
    ui_->themeComboBox->addItem("Calibri");
    ui_->themeComboBox->addItem("Dark");
    ui_->themeComboBox->addItem("Union");
    ui_->themeComboBox->setCurrentText(prop->GetTheme());

    const QColor txt = prop->GetPalette().buttonText().color();
    ui_->themeComboBox->setStyleSheet("QComboBox{color: rgb(" + QString::number(txt.red()) + "," + QString::number(txt.green()) + "," + QString::number(txt.red()) + ")}");

    const QColor but = prop->GetPalette().button().color();
    ui_->volumeSlider->setStyleSheet("QSlider{color: rgb(" + QString::number(but.red()) + "," + QString::number(but.green()) + "," + QString::number(but.red()) + ")}");

    ui_->repeatCheckBox->setChecked(prop->GetRepeat());
    ui_->volumeSlider->setValue(prop->GetVolume());
    ui_->volumeSpinBox->setValue(prop->GetVolume());
    ui_->capsCheckBox->setChecked(prop->GetCaps());
    ui_->shiftCheckBox->setChecked(prop->GetShift());
    ui_->themeComboBox->repaint();

    delete prop;

    InitializeButtonsConnections();
    InitializeSpecificConnections();
}

void PropertiesDialog::InitializeButtonsConnections()
{
    connect(ui_->buttonBox, SIGNAL(accepted()), this, SLOT(OnButtonBoxAccepted()));
}

void PropertiesDialog::InitializeSpecificConnections()
{
    connect(ui_->volumeSlider, SIGNAL(valueChanged(int)), ui_->volumeSpinBox, SLOT(setValue(int)));
    connect(ui_->volumeSpinBox, SIGNAL(valueChanged(int)), ui_->volumeSlider, SLOT(setValue(int)));
}
