#ifndef PLAYWINDOW_H
#define PLAYWINDOW_H

#include <QKeyEvent>
#include <QDialog>
#include "playbutton.h"

namespace Ui {
class PlayWindow;
}

/**
 * @brief The PlayWindow class the window with virtual keyboard and logic system. Sending signals with pressed/released keys to main window
 */
class PlayWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PlayWindow(QWidget *parent = 0);
    ~PlayWindow();

signals:
        /**
     * @brief buttonReleasedSignal Signal when some key was released
     * @param key the key, that was released
     */
    //void buttonReleasedSignal(QChar key);

    /**
     * @brief startSignal - signal for starting playing file with this key on this page
     * @param key - the activated key
     * @param page - the currnet page
     */
    void startSignal(QChar key, int page);

    /**
     * @brief stopSignal - signal for stoping playing file with this key on this page
     * @param key - the deactivated key
     * @param page - the current page
     */
    void stopSignal(QChar key, int page);

    // QWidget interface
protected:

    /**
     * @brief keyPressEvent method of processing pressed keys
     * @param event the press event
     * sending key to main window and displaying it on this window
     */
    void keyPressEvent(QKeyEvent *event);
    /**
     * @brief keyReleaseEvent method of processing released keys
     * @param event the releases event
     * sending key to main window and displaying it on this window
     */
    void keyReleaseEvent(QKeyEvent *event);
private slots:

    //----------pressed----------------

    /**
     *  @brief on_playButton_pressed - the slot, that performed, when some button was pressed
     * @param key - the pressed key
     */
    void on_playButton_pressed(QChar key);



    /**
     * @brief on_keyShiftButton_pressed when SHIFTButton was pressed
     */
    void on_keyShiftButton_pressed();

    //-----------Released-----------------


    /**
     * @brief on_playButton_released - the slot, that was performed, when some button was released
     * @param key - the released key
     */
    void on_playButton_released(QChar key);



    /**
     * @brief on_keyShiftButton_released when SHIFTButton was released
     */
    void on_keyShiftButton_released();


    // ------------ LAYERS--PRESSED-----------------------

    /**
     * @brief on_push1Button_pressed when 1 tab was selected
     */
    void on_push1Button_pressed();

    /**
     * @brief on_push2Button_pressed when 2 tab was selected
     */
    void on_push2Button_pressed();

    /**
     * @brief on_push3Button_pressed when 3 tab was selected
     */
    void on_push3Button_pressed();

    /**
     * @brief on_push4Button_pressed when 4 tab was selected
     */
    void on_push4Button_pressed();

    /**
     * @brief on_push5Button_pressed when 5 tab was selected
     */
    void on_push5Button_pressed();

    /**
     * @brief on_push6Button_pressed when 6 tab was selected
     */
    void on_push6Button_pressed();

    /**
     * @brief on_push7Button_pressed when 7 tab was selected
     */
    void on_push7Button_pressed();

    /**
     * @brief on_push8Button_pressed when 8 tab was selected
     */
    void on_push8Button_pressed();

    /**
     * @brief on_push9Button_pressed when 9 tab was selected
     */
    void on_push9Button_pressed();

    /**
     * @brief on_push0Button_pressed when 0 tab was selected
     */
    void on_push0Button_pressed();


    //-------------LAYERS--RELEASED--------------------------

    /**
     * @brief on_push1Button_released when 1 tab was selected
     */
    void on_push1Button_released();

    /**
     * @brief on_push2Button_released when 2 tab was selected
     */
    void on_push2Button_released();

    /**
     * @brief on_push3Button_released when 3 tab was selected
     */
    void on_push3Button_released();

    /**
     * @brief on_push4Button_released when 4 tab was selected
     */
    void on_push4Button_released();

    /**
     * @brief on_push5Button_released when 5 tab was selected
     */
    void on_push5Button_released();

    /**
     * @brief on_push6Button_released when 6 tab was selected
     */
    void on_push6Button_released();

    /**
     * @brief on_push7Button_released when 7 tab was selected
     */
    void on_push7Button_released();

    /**
     * @brief on_push8Button_released when 8 tab was selected
     */
    void on_push8Button_released();

    /**
     * @brief on_push9Button_released when 9 tab was selected
     */
    void on_push9Button_released();

    /**
     * @brief on_push0Button_released when 0 tab was selected
     */
    void on_push0Button_released();

    /**
     * @brief setCurrentLay - setting new lay. Refresh status of all buttons
     * @param lay - new lay
     */
    void setCurrentLay(int lay);

    /**
     * @brief on_capsLockButton_pressed - slot, that was performed, when CapsLock was pressed
     */
    void on_capsLockButton_pressed();

    /**
     * @brief on_capsLockButton_released - slot, that was performed, when CapsLock was released
     */
    void on_capsLockButton_released();

private:
    Ui::PlayWindow *ui;
    QList<PlayButton*> buttons;
    bool shift;
    bool caps;
    int currentLay;
};

#endif // PLAYWINDOW_H
