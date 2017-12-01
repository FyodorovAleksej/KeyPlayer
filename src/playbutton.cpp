#include "playbutton.h"

PlayButton::PlayButton(QObject *parent) : QObject(parent)
{
	current_status_ = 0;
	widget_button_ = nullptr;
}

PlayButton::PlayButton(QPushButton *button, const QChar key)
{
    this->widget_button_ = button;
    this->key_ = key;
    this->current_status_ = 0;
    for (int i = 0; i < LEN; i++)
    {
        this->all_status_[i] = 0;
    }
    this->widget_button_->setStyleSheet(PASSIVE_BUTTON_COLOR);
    connect(button, SIGNAL(pressed()), this, SLOT(Press()));
    connect(button, SIGNAL(released()), this, SLOT(Release()));
}

PlayButton::~PlayButton()
{
    disconnect(widget_button_, SIGNAL(pressed()), this, SLOT(Press()));
    disconnect(widget_button_, SIGNAL(released()), this, SLOT(Release()));
}

bool PlayButton::WasPressed(const int lay, const bool shift)
{
    this->widget_button_->setStyleSheet(ACTIVE_BUTTON_COLOR);
    this->all_status_[lay] = 1;
    if (shift)
    {
        current_status_ = !current_status_;
    }
    return current_status_;
}

bool PlayButton::WasReleased(const int lay, const bool shift)
{
    if (!current_status_ || !shift)
    {
        this->current_status_ = false;
        this->widget_button_->setStyleSheet(PASSIVE_BUTTON_COLOR);
        this->all_status_[lay] = 0;
        return true;
    }
    else
    {
        this->widget_button_->setStyleSheet(START_BUTTON_COLOR);
        this->all_status_[lay] = 2;
    }
    return false;
}

void PlayButton::ChangeLay(const int lay)
{
    switch(this->all_status_[lay])
    {
    case 0: {this->widget_button_->setStyleSheet(PASSIVE_BUTTON_COLOR); break;}
    case 1: {this->widget_button_->setStyleSheet(ACTIVE_BUTTON_COLOR); break;}
    case 2: {this->widget_button_->setStyleSheet(START_BUTTON_COLOR); break;}
    default: {this->widget_button_->setStyleSheet(PASSIVE_BUTTON_COLOR); break;}
    }
    this->current_status_ = all_status_[lay];
}

QChar PlayButton::GetKey() const
{
    return this->key_;
}

QPushButton* PlayButton::GetButton() const
{
    return this->widget_button_;
}

void PlayButton::Press()
{
    emit pressed(this->key_);
}
void PlayButton::Release()
{
    emit released(this->key_);
}
