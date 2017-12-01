#include "keyelement.h"

KeyElement::KeyElement(QObject *parent) : QObject(parent)
{
    this->key_ = ' ';
    this->player_ = nullptr;
    this->format_ = 0;
    this->valid_ = false;
    this->item_ = nullptr;
    this->repeating_ = false;
}

KeyElement::~KeyElement()
{
    disconnect(player_, SIGNAL(error(QMediaPlayer::Error)), this, SLOT(ErrorSlot()));
}

KeyElement::KeyElement(const QString name)
{
    this->key_ = ' ';
    this->valid_ = true;
    this->player_ = new QMediaPlayer();
    connect(player_, SIGNAL(error(QMediaPlayer::Error)), this, SLOT(ErrorSlot()));
    player_->setMedia(QMediaContent(QUrl::fromLocalFile(name)));
    this->format_ = 0;
    this->valid_ = player_->isAvailable();
    this->item_ = new QTreeWidgetItem();
    this->repeating_ = false;
}


QChar KeyElement::GetKey() const
{
    return this->key_;
}

void KeyElement::SetKey(const QChar key)
{
    this->key_ = key;
}

QString KeyElement::GetName() const
{
    return this->item_->text(1);
}

QString KeyElement::GetPath() const
{
    return this->item_->text(0);
}

int KeyElement::GetFormat() const
{
    return this->format_;
}

void KeyElement::SetFormat(const int format)
{
    this->format_ = format;
}

QTreeWidgetItem* KeyElement::GetItem() const
{
    return this->item_;
}

void KeyElement::SetItem(QTreeWidgetItem *item)
{
	const QColor color = this->item_->backgroundColor(1);
    this->item_ = item;
    this->item_->setBackgroundColor(1,color);
}

void KeyElement::set_volume(const int volume) const
{
    if (this->player_ != nullptr)
    {
        this->player_->setVolume(volume);
    }
}

int KeyElement::GetVolume() const
{
    if (this->player_ != nullptr)
    {
        return this->player_->volume();
    }
    else
    {
        return 0;
    }
}

QMediaPlayer* KeyElement::GetPlayer() const
{
    return this->player_;
}

qint64 KeyElement::Duration() const
{
    return this->player_->duration();
}

bool KeyElement::IsValid() const
{
    return valid_;
}

void KeyElement::SetRepeated(const bool repeat)
{
    this->repeating_ = repeat;
}

bool KeyElement::IsRepeated() const
{
    return this->repeating_;
}


void KeyElement::Play() const
{
    if (this->player_ != nullptr)
    {
        this->player_->play();
    }
}

void KeyElement::Stop() const
{
    if (this->player_ != nullptr)
    {
        this->player_->stop();
    }
}
void KeyElement::ErrorSlot()
{
    this->valid_ = false;
    this->item_->setBackgroundColor(1, QColor(250, 80, 80, 235));
}
