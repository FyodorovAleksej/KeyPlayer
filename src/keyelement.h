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
    explicit KeyElement(QObject* parent = nullptr);

    /**
     * @brief KeyElement the constructor with path of the music file
     * @param name the path of music file to create link
     */
	explicit KeyElement(QString name);
    ~KeyElement();

    /**
     * @brief getKey getting the binded key
     * @return the binded key
     */
    QChar GetKey() const;

    /**
     * @brief setKey setting the binded key
     * @param key for binding
     */
    void SetKey(QChar key);

    /**
     * @brief getName getting name of music file
     * @return name of file
     */
    QString GetName() const;

    /**
     * @brief getPath getting full path of music file
     * @return path of file
     */
    QString GetPath() const;

    /**
     * @brief getFormat getting status of played/nonPlayed file
     * @return int code of status
     * 0 - is nonPlayed by SHIFT
     * 1 - is Played by SHIFT
     */
    int GetFormat() const;

    /**
     * @brief setFormat setting current status of file
     * @param format the value of current status
     * 0 - is nonPlayed by SHIFT
     * 1 - is Played by SHIFT
     */
    void SetFormat(int format);

    /**
     * @brief getItem getting linked tree item from main window
     * @return linked tree item
     */
    QTreeWidgetItem* GetItem() const;

    /**
     * @brief setItem setting link with tree item from main window
     * @param item item for linking
     */
    void SetItem(QTreeWidgetItem* item);

    /**
     * @brief setVolume setting value of volume
     * @param volume int value of volume (0-100)
     */
    void set_volume(int volume) const;

    /**
     * @brief getVolume getting current value of volume
     * @return int value of volume (0-100)
     */
    int GetVolume() const;

    /**
     * @brief getPlayer getting player of this file
     * @return player of file
     */
    QMediaPlayer* GetPlayer() const;

    /**
     * @brief duration getting duration of music file
     * @return long int (ms)
     */
    qint64 Duration() const;

    /**
     * @brief isValid getting status of player
     * @return status of player
     */
    bool IsValid() const;

    /**
     * @brief isRepeated property of repeting, when was started by SHIFT
     * @return bool - is Repeated
     */
    bool IsRepeated() const;

    /**
     * @brief setRepeated setting repeating, when was starting by SHIFT
     * @param repeat - is Repeated
     */
    void SetRepeated(bool repeat);

public slots:
    /**
     * @brief play start playing music file
     */
    void Play() const;

    /**
     * @brief stop stop playing music file
     */
    void Stop() const;

    /**
     * @brief errorSlot slot of error, when file was loading
     * used for check validation of music file for QMediaPlayer
     */
    void ErrorSlot();

private:
    QChar key_;
    QMediaPlayer *player_;
    int format_;
    bool valid_;
    QTreeWidgetItem *item_;
    bool repeating_;
};

#endif // KEYELEMENT_H
