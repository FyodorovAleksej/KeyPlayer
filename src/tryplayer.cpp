#include "tryplayer.h"


TryPlayer::TryPlayer(QObject *parent) : QObject(parent)
{
    this->item_ = nullptr;
    this->player_ = nullptr;
}

TryPlayer::TryPlayer(QTreeWidgetItem *item)
{
    this->item_ = item;
    this->player_ = new QMediaPlayer();
    connect(player_, SIGNAL(error(QMediaPlayer::Error)), this, SLOT(errorSlot()));
    connect(player_, SIGNAL(durationChanged(qint64)), this, SLOT(durationChangedSlot()));
    player_->setMedia(QMediaContent(QUrl::fromLocalFile(item->text(0))));
    qDebug() << "add new try" << item->text(0);
}

TryPlayer::~TryPlayer()
{
    disconnect(player_, SIGNAL(error(QMediaPlayer::Error)), this, SLOT(errorSlot()));
    disconnect(player_, SIGNAL(durationChanged(qint64)), this, SLOT(durationChangedSlot()));
    delete this->player_;
}

void TryPlayer::ErrorSlot()
{
    qDebug() << "error" << item_->text(0);
    item_->setBackgroundColor(1,QColor(250,80,80,235));
    this->deleteLater();
}

void TryPlayer::DurationChangedSlot()
{
    qDebug() << "correct" << item_->text(0);
    this->deleteLater();
}
