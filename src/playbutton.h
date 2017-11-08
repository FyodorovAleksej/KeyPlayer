#ifndef PLAYBUTTON_H
#define PLAYBUTTON_H
#define LEN 10
#define passiveButtonColor QString::fromUtf8("background-color: rgb(248, 248, 10);")
#define activeButtonColor QString::fromUtf8("background-color: rgb(100, 248, 40);")
#define startButtonColor QString::fromUtf8("background-color: rgb(50, 50, 248);")

#include <QObject>
#include <QPushButton>

/**
 * @brief The PlayButton class - the class of all buttons on PlayWindow. Consist of key, status of button on all pages and graphical object
 */
class PlayButton : public QObject
{
    Q_OBJECT
public:
    explicit PlayButton(QObject *parent = 0);

    /**
     * @brief PlayButton - create PlayButton with this graphical button and this key
     * @param button - the graphical button on PlayWindow
     * @param key - the key, that was linked with this button
     */
    PlayButton(QPushButton* button, QChar key);

    ~PlayButton();

    /**
     * @brief getKey - getting key, that was linked with this object
     * @return - the key, that was linked with this object
     */
    QChar getKey();

    /**
     * @brief getButton - getting graphical button from PlayWindow, that was linked with this object
     * @return - the graphical button, that was linked with this object
     */
    QPushButton* getButton();

    /**
     * @brief wasPressed - the method, that called, when this button was activate. Called from PlayWindow
     * @param lay - the current lay of PlayWindow.
     * @param shift - the current status of shift on PlayWindow
     * @return - always true
     */
    bool wasPressed(int lay, bool shift);

    /**
     * @brief wasReleased - the method, that called, when this button was released. Called from PlayWindow
     * @param lay - the current lay of PlayWindow
     * @param shift - the current status of shift on PlayWindow
     * @return  - true - if the status was changed by shift
     *              - false - if the status wasn't changed by shift
     */
    bool wasReleased(int lay, bool shift);

    /**
     * @brief changeLay - the method for refresh status and graphical button, when lay of PlayWindow was changed.
     * @param lay - the new lay of PlayWindow
     */
    void changeLay(int lay);

signals:

    /**
     * @brief pressed - signal, when the button was pressed. Send the linked key
     */
    void pressed(QChar);

    /**
     * @brief released - signal, when the button was released. Send the linked key
     */
    void released(QChar);
public slots:

    /**
     * @brief press - the slot, that resending signal of pressing with linked key. Perform, when button was pressed
     */
    void press();

    /**
     * @brief release - the slot, that resending signal of releasing with linked key. Perform, when button was released
     */
    void release();

private:
    char currentStatus;
    char allStatus[LEN];
    QPushButton* widgetButton;
    QChar key;
};

#endif // PLAYBUTTON_H
