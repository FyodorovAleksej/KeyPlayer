#ifndef KEYELEMENT_H
#define KEYELEMENT_H

#include <QObject>
#include <QString>
#include <QtMultimedia/QMediaPlayer>
#include <QTreeWidgetItem>
#include <QtMultimedia/QMediaContent>

class KeyElement : public QObject
{
    Q_OBJECT
public:
    explicit KeyElement(QObject* parent = 0);
    KeyElement(QString name);
    ~KeyElement();

    QChar getKey();
    void setKey(QChar key);

    QString getName();

    int getFormat();
    void setFormat(int format);


    QTreeWidgetItem* getItem();
    void setItem(QTreeWidgetItem* item);

    void setVolume(int volume);

    QMediaPlayer* getPlayer();
    qint64 duration();

    bool isValid();

    bool isRepeated();
    void setRepeated(bool repeat);

public slots:
    void play();
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
