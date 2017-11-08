#ifndef TRYPLAYER_H
#define TRYPLAYER_H

#include <QObject>
#include <QMediaPlayer>
#include <QTreeWidgetItem>

/**
 * @brief The TryPlayer class class for checking valid music files, when files was added in tree directory. Deleting itself
 */
class TryPlayer : public QObject
{
    Q_OBJECT
public:
    explicit TryPlayer(QObject *parent = 0);

    /**
     * @brief TryPlayer creating selfdestructed object of TryPlayer, with this file.
     * @param item the file for checking
     */
    TryPlayer(QTreeWidgetItem* item);
    ~TryPlayer();
signals:

public slots:

    /**
     * @brief durationChangedSlot slot activated, when duration of music file was loaded
     */
    void durationChangedSlot();

    /**
     * @brief errorSlot slot activated, when file can't loaded
     */
    void errorSlot();
private:
    QTreeWidgetItem *item;
    QMediaPlayer *player;
};

#endif // TRYPLAYER_H
