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
    player->setMedia(QMediaContent(QUrl::fromLocalFile(item->text(0))));
    qDebug() << "add new try" << item->text(0);
}

TryPlayer::~TryPlayer()
{
    disconnect(player, SIGNAL(error(QMediaPlayer::Error)), this, SLOT(errorSlot()));
    disconnect(player, SIGNAL(durationChanged(qint64)), this, SLOT(durationChangedSlot()));
    delete this->player;
}

void TryPlayer::errorSlot()
{
    qDebug() << "error" << item->text(0);
    item->setBackgroundColor(1,QColor(250,80,80,235));
    this->deleteLater();
}

void TryPlayer::durationChangedSlot()
{
    qDebug() << "correct" << item->text(0);
    this->deleteLater();
}
