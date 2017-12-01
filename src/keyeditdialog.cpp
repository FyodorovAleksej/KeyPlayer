#include "keyeditdialog.h"
#include "ui_keyeditdialog.h"

KeyEditDialog::KeyEditDialog(QWidget *parent, Properties* prop) :
    QDialog(parent),
    ui_(new Ui::KeyEditDialog)
{
    ui_->setupUi(this);
    prop_ = prop;

    Initialize();
}

KeyEditDialog::~KeyEditDialog()
{
    delete ui_;
}

void KeyEditDialog::OnKeySequenceEditEditingFinished() const
{
    ui_->okButton->setEnabled(true);
}

void KeyEditDialog::OnOkButtonClicked()
{
    qDebug() << ui_->keySequenceEdit->keySequence().toString();
    qDebug() << path_->text(0);
    KeyElement* element = new KeyElement(path_->text(0));
    element->SetItem(path_);
    element->SetKey(ui_->keySequenceEdit->keySequence().toString().at(0));
    element->set_volume(ui_->volumeSpin->value());
    element->SetRepeated(ui_->repeatBox->isChecked());
    emit finish(element);
    this->close();
}

void KeyEditDialog::OnCancelButtonClicked()
{
    close();
}

void KeyEditDialog::Initialize()
{
    ui_->okButton->setEnabled(false);
    ui_->volumeSlider->setValue(prop_->GetVolume());
    ui_->volumeSpin->setValue(prop_->GetVolume());
    ui_->repeatBox->setChecked(prop_->GetRepeat());

    InitializeButtonsConnections();
    InitializeSpecificConnections();
}




void KeyEditDialog::InitializeButtonsConnections()
{
    connect(ui_->okButton, SIGNAL(clicked(bool)), this, SLOT(accept()));
    connect(ui_->cancelButton, SIGNAL(clicked(bool)), this, SLOT(OnCancelButtonClicked()));
}



void KeyEditDialog::InitializeSpecificConnections()
{
    connect(ui_->volumeSlider, SIGNAL(valueChanged(int)), ui_->volumeSpin, SLOT(setValue(int)));
    connect(ui_->volumeSpin, SIGNAL(valueChanged(int)), ui_->volumeSlider, SLOT(setValue(int)));
    connect(ui_->keySequenceEdit,SIGNAL(editingFinished()), this, SLOT(OnKeySequenceEditEditingFinished()));
}

void KeyEditDialog::SetPath(QTreeWidgetItem *new_path)
{
    path_ = new_path;
    ui_->pathLabel->setText("path: " + path_->text(0));
}
