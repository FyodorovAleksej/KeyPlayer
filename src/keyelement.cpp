#include "keyelement.h"

KeyElement::KeyElement(QObject *parent) : QObject(parent)
{
    this->key = ' ';
    this->player = NULL;
    this->format = 0;
    this->valid = false;
    this->item = NULL;
    this->repeating = false;
}

KeyElement::~KeyElement()
{
    disconnect(player, SIGNAL(error(QMediaPlayer::Error)), this, SLOT(errorSlot()));
}

KeyElement::KeyElement(QString name)
{
    this->key = ' ';
    this->valid = true;
    this->player = new QMediaPlayer();
    connect(player, SIGNAL(error(QMediaPlayer::Error)), this, SLOT(errorSlot()));
    player->setMedia(QMediaContent(QUrl::fromLocalFile(name)));
    this->format = 0;
    this->valid = player->isAvailable();
    this->item = new QTreeWidgetItem();
    this->repeating = false;
}


QChar KeyElement::getKey()
{
    return this->key;
}

void KeyElement::setKey(QChar key)
{
    this->key = key;
}

QString KeyElement::getName()
{
    return this->item->text(1);
}

QString KeyElement::getPath()
{
    return this->item->text(0);
}

int KeyElement::getFormat()
{
    return this->format;
}

void KeyElement::setFormat(int format)
{
    this->format = format;
}

QTreeWidgetItem* KeyElement::getItem()
{
    return this->item;
}

void KeyElement::setItem(QTreeWidgetItem *item)
{
    QColor color = this->item->backgroundColor(1);
    this->item = item;
    this->item->setBackgroundColor(1,color);
}

void KeyElement::setVolume(int volume)
{
    if (this->player != NULL)
    {
        this->player->setVolume(volume);
    }
}

int KeyElement::getVolume()
{
    if (this->player != NULL)
    {
        return this->player->volume();
    }
    else
    {
        return 0;
    }
}

QMediaPlayer* KeyElement::getPlayer()
{
    return this->player;
}

qint64 KeyElement::duration()
{
    return this->player->duration();
}

bool KeyElement::isValid()
{
    return valid;
}

void KeyElement::setRepeated(bool repeat)
{
    this->repeating = repeat;
}

bool KeyElement::isRepeated()
{
    return this->repeating;
}


void KeyElement::play()
{
    if (this->player != NULL)
    {
        this->player->play();
    }
}

void KeyElement::stop()
{
    if (this->player != NULL)
    {
        this->player->stop();
    }
}
void KeyElement::errorSlot()
{
    this->valid = false;
    this->item->setBackgroundColor(1,QColor(250,80,80,235));
}
