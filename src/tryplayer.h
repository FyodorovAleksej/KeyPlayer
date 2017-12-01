#ifndef TRYPLAYER_H
#define TRYPLAYER_H

#include <QObject>
#include <QTreeWidgetItem>
#include <QtMultimedia/QMediaPlayer>

/**
 * @brief The TryPlayer class class for checking valid music files, when files was added in tree directory. Deleting itself
 */
class TryPlayer : public QObject
{
    Q_OBJECT
public:
    explicit TryPlayer(QObject *parent = nullptr);

    /**
     * @brief TryPlayer creating selfdestructed object of TryPlayer, with this file.
     * @param item the file for checking
     */
	explicit TryPlayer(QTreeWidgetItem* item);
    ~TryPlayer();
signals:

public slots:

    /**
     * @brief durationChangedSlot slot activated, when duration of music file was loaded
     */
    void DurationChangedSlot();

    /**
     * @brief errorSlot slot activated, when file can't loaded
     */
    void ErrorSlot();
private:
    QTreeWidgetItem *item_;
    QMediaPlayer *player_;
};

#endif // TRYPLAYER_H
