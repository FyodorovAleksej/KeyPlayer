#include "tryplayer.h"


TryPlayer::TryPlayer(QObject *parent) : QObject(parent)
{
    this->item = NULL;
    this->player = NULL;
}

TryPlayer::TryPlayer(QTreeWidgetItem *item)
{
    this->item = item;
    this->player = new QMediaPlayer();
    connect(player, SIGNAL(error(QMediaPlayer::Error)), this, SLOT(errorSlot()));
    connect(player, SIGNAL(durationChanged(qint64)), this, SLOT(durationChangedSlot()));
    player->setMedia(QMediaContent(item->text(0)));
}

TryPlayer::~TryPlayer()
{
    disconnect(player, SIGNAL(error(QMediaPlayer::Error)), this, SLOT(errorSlot()));
    disconnect(player, SIGNAL(durationChanged(qint64)), this, SLOT(durationChangedSlot()));
    delete this->player;
}

void TryPlayer::errorSlot()
{
    item->setBackgroundColor(1,QColor(250,80,80,235));
    delete this;
}

void TryPlayer::durationChangedSlot()
{
    delete this;
}
