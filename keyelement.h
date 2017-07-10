#ifndef KEYELEMENT_H
#define KEYELEMENT_H

#include <QObject>
#include <QString>
#include <QtMultimedia/QMediaPlayer>
#include <QTreeWidgetItem>
#include <QtMultimedia/QMediaContent>

/**
 * @brief The KeyElement class of element with all propetyies of played file. Such as path/key/volume/repeating
 */
class KeyElement : public QObject
{
    Q_OBJECT
public:
    explicit KeyElement(QObject* parent = 0);
    KeyElement(QString name);
    ~KeyElement();

    /**
     * @brief getKey getting the binded key
     * @return the binded key
     */
    QChar getKey();

    /**
     * @brief setKey setting the binded key
     * @param key for binding
     */
    void setKey(QChar key);

    /**
     * @brief getName getting name of music file
     * @return name of file
     */
    QString getName();

    /**
     * @brief getPath getting full path of music file
     * @return path of file
     */
    QString getPath();

    /**
     * @brief getFormat getting status of played/nonPlayed file
     * @return int code of status
     * 0 - is nonPlayed by SHIFT
     * 1 - is Played by SHIFT
     */
    int getFormat();

    /**
     * @brief setFormat setting current status of file
     * @param format the value of current status
     * 0 - is nonPlayed by SHIFT
     * 1 - is Played by SHIFT
     */
    void setFormat(int format);

    /**
     * @brief getItem getting linked tree item from main window
     * @return linked tree item
     */
    QTreeWidgetItem* getItem();

    /**
     * @brief setItem setting link with tree item from main window
     * @param item item for linking
     */
    void setItem(QTreeWidgetItem* item);

    /**
     * @brief setVolume setting value of volume
     * @param volume int value of volume (0-100)
     */
    void setVolume(int volume);

    /**
     * @brief getVolume getting current value of volume
     * @return int value of volume (0-100)
     */
    int getVolume();

    /**
     * @brief getPlayer getting player of this file
     * @return player of file
     */
    QMediaPlayer* getPlayer();

    /**
     * @brief duration getting duration of music file
     * @return long int (ms)
     */
    qint64 duration();

    /**
     * @brief isValid getting status of player
     * @return status of player
     */
    bool isValid();

    /**
     * @brief isRepeated property of repeting, when was started by SHIFT
     * @return bool - is Repeated
     */
    bool isRepeated();

    /**
     * @brief setRepeated setting repeating, when was starting by SHIFT
     * @param repeat - is Repeated
     */
    void setRepeated(bool repeat);

public slots:
    /**
     * @brief play start playing music file
     */
    void play();

    /**
     * @brief stop stop playing music file
     */
    void stop();
private:
    QChar key;
    QMediaPlayer *player;
    int format;
    bool valid;
    QTreeWidgetItem *item;
    bool repeating;
};

#endif // KEYELEMENT_H
