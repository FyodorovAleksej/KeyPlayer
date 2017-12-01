#ifndef PLAYWINDOW_H
#define PLAYWINDOW_H

#include <QKeyEvent>
#include <QDialog>
#include "playbutton.h"
#include "properties.h"
#include "nullproperties.h"

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
    explicit PlayWindow(QWidget *parent = nullptr, Properties *prop = new NullProperties());
    ~PlayWindow();

signals:

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
    void keyPressEvent(QKeyEvent *event) override;
    /**
     * @brief keyReleaseEvent method of processing released keys
     * @param event the releases event
     * sending key to main window and displaying it on this window
     */
    void keyReleaseEvent(QKeyEvent *event) override;
private slots:

    //----------pressed----------------

    /**
     *  @brief on_playButton_pressed - the slot, that performed, when some button was pressed
     * @param key - the pressed key
     */
    void OnPlayButtonPressed(QChar key);



    /**
     * @brief on_keyShiftButton_pressed when SHIFTButton was pressed
     */
    void OnKeyShiftButtonPressed();

    //-----------Released-----------------


    /**
     * @brief on_playButton_released - the slot, that was performed, when some button was released
     * @param key - the released key
     */
    void OnPlayButtonReleased(QChar key);



    /**
     * @brief on_keyShiftButton_released when SHIFTButton was released
     */
    void OnKeyShiftButtonReleased();


    // ------------ LAYERS--PRESSED-----------------------

    /**
     * @brief on_push1Button_pressed when 1 tab was selected
     */
    void OnPush1ButtonPressed();

    /**
     * @brief on_push2Button_pressed when 2 tab was selected
     */
    void OnPush2ButtonPressed();

    /**
     * @brief on_push3Button_pressed when 3 tab was selected
     */
    void OnPush3ButtonPressed();

    /**
     * @brief on_push4Button_pressed when 4 tab was selected
     */
    void OnPush4ButtonPressed();

    /**
     * @brief on_push5Button_pressed when 5 tab was selected
     */
    void OnPush5ButtonPressed();

    /**
     * @brief on_push6Button_pressed when 6 tab was selected
     */
    void OnPush6ButtonPressed();

    /**
     * @brief on_push7Button_pressed when 7 tab was selected
     */
    void OnPush7ButtonPressed();

    /**
     * @brief on_push8Button_pressed when 8 tab was selected
     */
    void OnPush8ButtonPressed();

    /**
     * @brief on_push9Button_pressed when 9 tab was selected
     */
    void OnPush9ButtonPressed();

    /**
     * @brief on_push0Button_pressed when 0 tab was selected
     */
    void OnPush0ButtonPressed();


    //-------------LAYERS--RELEASED--------------------------

    /**
     * @brief on_push1Button_released when 1 tab was selected
     */
    void OnPush1ButtonReleased() const;

    /**
     * @brief on_push2Button_released when 2 tab was selected
     */
    void OnPush2ButtonReleased() const;

    /**
     * @brief on_push3Button_released when 3 tab was selected
     */
    void OnPush3ButtonReleased() const;

    /**
     * @brief on_push4Button_released when 4 tab was selected
     */
    void OnPush4ButtonReleased() const;

    /**
     * @brief on_push5Button_released when 5 tab was selected
     */
    void OnPush5ButtonReleased() const;

    /**
     * @brief on_push6Button_released when 6 tab was selected
     */
    void OnPush6ButtonReleased() const;

    /**
     * @brief on_push7Button_released when 7 tab was selected
     */
    void OnPush7ButtonReleased() const;

    /**
     * @brief on_push8Button_released when 8 tab was selected
     */
    void OnPush8ButtonReleased() const;

    /**
     * @brief on_push9Button_released when 9 tab was selected
     */
    void OnPush9ButtonReleased() const;

    /**
     * @brief on_push0Button_released when 0 tab was selected
     */
    void OnPush0ButtonReleased() const;

    /**
     * @brief setCurrentLay - setting new lay. Refresh status of all buttons
     * @param lay - new lay
     */
    void SetCurrentLay(int lay);

    /**
     * @brief on_capsLockButton_pressed - slot, that was performed, when CapsLock was pressed
     */
    void OnCapsLockButtonPressed();

    /**
     * @brief on_capsLockButton_released - slot, that was performed, when CapsLock was released
     */
    void OnCapsLockButtonReleased() const;

private:
    Ui::PlayWindow *ui_;
    QList<PlayButton*> buttons_;
    bool shift_;
    bool caps_;
    int current_lay_;

    Properties* prop_;
};

#endif // PLAYWINDOW_H
