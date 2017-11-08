#include "playbutton.h"

PlayButton::PlayButton(QObject *parent) : QObject(parent)
{

}

PlayButton::PlayButton(QPushButton *button, QChar key)
{
    this->widgetButton = button;
    this->key = key;
    this->currentStatus = 0;
    for (int i = 0; i < LEN; i++)
    {
        this->allStatus[i] = 0;
    }
    this->widgetButton->setStyleSheet(passiveButtonColor);
    connect(button, SIGNAL(pressed()), this, SLOT(press()));
    connect(button, SIGNAL(released()), this, SLOT(release()));
}

PlayButton::~PlayButton()
{
    disconnect(widgetButton, SIGNAL(pressed()), this, SLOT(press()));
    disconnect(widgetButton, SIGNAL(released()), this, SLOT(release()));
    //delete this->widgetButton;
}

bool PlayButton::wasPressed(int lay, bool shift)
{
    this->widgetButton->setStyleSheet(activeButtonColor);
    this->allStatus[lay] = 1;
    if (shift)
    {
        currentStatus = !currentStatus;
    }
    return currentStatus;
}

bool PlayButton::wasReleased(int lay, bool shift)
{
    if (!currentStatus || !shift)
    {
        this->currentStatus = false;
        this->widgetButton->setStyleSheet(passiveButtonColor);
        this->allStatus[lay] = 0;
        return true;
    }
    else
    {
        this->widgetButton->setStyleSheet(startButtonColor);
        this->allStatus[lay] = 2;
    }
    return false;
}

void PlayButton::changeLay(int lay)
{
    switch(this->allStatus[lay])
    {
    case 0: {this->widgetButton->setStyleSheet(passiveButtonColor); break;}
    case 1: {this->widgetButton->setStyleSheet(activeButtonColor); break;}
    case 2: {this->widgetButton->setStyleSheet(startButtonColor); break;}
    default: {this->widgetButton->setStyleSheet(passiveButtonColor); break;}
    }
    this->currentStatus = allStatus[lay];
}

QChar PlayButton::getKey()
{
    return this->key;
}

QPushButton* PlayButton::getButton()
{
    return this->widgetButton;
}

void PlayButton::press()
{
    emit pressed(this->key);
}
void PlayButton::release()
{
    emit released(this->key);
}
