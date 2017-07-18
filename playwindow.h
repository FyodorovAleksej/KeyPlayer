#ifndef PLAYWINDOW_H
#define PLAYWINDOW_H

#include <QKeyEvent>
#include <QDialog>

namespace Ui {
class PlayWindow;
}

/**
 * @brief The PlayWindow class the window with virtual keyboard. Sending signals with pressed/released keys to main window
 */
class PlayWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PlayWindow(QWidget *parent = 0);
    ~PlayWindow();

private:
    Ui::PlayWindow *ui;
    bool shift;
signals:
    /**
     * @brief buttonPressedSignal Signal when some key was pressed
     * @param key the key, that was pressed
     */
    void buttonPressedSignal(QChar key);

    /**
     * @brief buttonReleasedSignal Signal when some key was released
     * @param key the key, that was released
     */
    void buttonReleasedSignal(QChar key);

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
     * @brief on_keyQButton_pressed when QButton was pressed
     */
    void on_keyQButton_pressed();

    /**
     * @brief on_keyWButton_pressed when WButton was pressed
     */
    void on_keyWButton_pressed();

    /**
     * @brief on_keyEButton_pressed when EButton was pressed
     */
    void on_keyEButton_pressed();

    /**
     * @brief on_keyRButton_pressed when RButton was pressed
     */
    void on_keyRButton_pressed();

    /**
     * @brief on_keyTButton_pressed when TButton was pressed
     */
    void on_keyTButton_pressed();

    /**
     * @brief on_keyYButton_pressed when YButton was pressed
     */
    void on_keyYButton_pressed();

    /**
     * @brief on_keyUButton_pressed when UButton was pressed
     */
    void on_keyUButton_pressed();

    /**
     * @brief on_keyIButton_pressed when IButton was pressed
     */
    void on_keyIButton_pressed();

    /**
     * @brief on_keyOButton_pressed when OButton was pressed
     */
    void on_keyOButton_pressed();

    /**
     * @brief on_keyPButton_pressed when PButton was pressed
     */
    void on_keyPButton_pressed();

    /**
     * @brief on_keyAButton_pressed when AButton was pressed
     */
    void on_keyAButton_pressed();

    /**
     * @brief on_keySButton_pressed when SButton was pressed
     */
    void on_keySButton_pressed();

    /**
     * @brief on_keyDButton_pressed when DButton was pressed
     */
    void on_keyDButton_pressed();

    /**
     * @brief on_keyFButton_pressed when FButton was pressed
     */
    void on_keyFButton_pressed();

    /**
     * @brief on_keyGButton_pressed when GButton was pressed
     */
    void on_keyGButton_pressed();

    /**
     * @brief on_keyHButton_pressed when HButton was pressed
     */
    void on_keyHButton_pressed();

    /**
     * @brief on_keyJButton_pressed when JButton was pressed
     */
    void on_keyJButton_pressed();

    /**
     * @brief on_keyKButton_pressed when KButton was pressed
     */
    void on_keyKButton_pressed();

    /**
     * @brief on_keyLButton_pressed when LButton was pressed
     */
    void on_keyLButton_pressed();

    /**
     * @brief on_keyZButton_pressed when ZButton was pressed
     */
    void on_keyZButton_pressed();

    /**
     * @brief on_keyXButton_pressed when XButton was pressed
     */
    void on_keyXButton_pressed();

    /**
     * @brief on_keyCButton_pressed when CButton was pressed
     */
    void on_keyCButton_pressed();

    /**
     * @brief on_keyVButton_pressed when VButton was pressed
     */
    void on_keyVButton_pressed();

    /**
     * @brief on_keyBButton_pressed when BButton was pressed
     */
    void on_keyBButton_pressed();

    /**
     * @brief on_keyNButton_pressed when NButton was pressed
     */
    void on_keyNButton_pressed();

    /**
     * @brief on_keyMButton_pressed when MButton was pressed
     */
    void on_keyMButton_pressed();

    /**
     * @brief on_keyShiftButton_pressed when SHIFTButton was pressed
     */
    void on_keyShiftButton_pressed();

    //-----------Released-----------------

    /**
     * @brief on_keyQButton_released when QButton was released
     */
    void on_keyQButton_released();
    /**
     * @brief on_keyWButton_released when WButton was released
     */
    void on_keyWButton_released();
    /**
     * @brief on_keyEButton_released when EButton was released
     */
    void on_keyEButton_released();
    /**
     * @brief on_keyRButton_released when RButton was released
     */
    void on_keyRButton_released();
    /**
     * @brief on_keyTButton_released when TButton was released
     */
    void on_keyTButton_released();
    /**
     * @brief on_keyYButton_released when YButton was released
     */
    void on_keyYButton_released();
    /**
     * @brief on_keyUButton_released when UButton was released
     */
    void on_keyUButton_released();
    /**
     * @brief on_keyIButton_released when IButton was released
     */
    void on_keyIButton_released();
    /**
     * @brief on_keyOButton_released when OButton was released
     */
    void on_keyOButton_released();
    /**
     * @brief on_keyPButton_released when PButton was released
     */
    void on_keyPButton_released();
    /**
     * @brief on_keyAButton_released when AButton was released
     */
    void on_keyAButton_released();
    /**
     * @brief on_keySButton_released when SButton was released
     */
    void on_keySButton_released();
    /**
     * @brief on_keyDButton_released when DButton was released
     */
    void on_keyDButton_released();
    /**
     * @brief on_keyFButton_released when FButton was released
     */
    void on_keyFButton_released();
    /**
     * @brief on_keyGButton_released when GButton was released
     */
    void on_keyGButton_released();
    /**
     * @brief on_keyHButton_released when HButton was released
     */
    void on_keyHButton_released();
    /**
     * @brief on_keyJButton_released when JButton was released
     */
    void on_keyJButton_released();
    /**
     * @brief on_keyKButton_released when KButton was released
     */
    void on_keyKButton_released();
    /**
     * @brief on_keyLButton_released when LButton was released
     */
    void on_keyLButton_released();
    /**
     * @brief on_keyZButton_released when ZButton was released
     */
    void on_keyZButton_released();
    /**
     * @brief on_keyXButton_released when XButton was released
     */
    void on_keyXButton_released();
    /**
     * @brief on_keyCButton_released when CButton was released
     */
    void on_keyCButton_released();
    /**
     * @brief on_keyVButton_released when VButton was released
     */
    void on_keyVButton_released();
    /**
     * @brief on_keyBButton_released when BButton was released
     */
    void on_keyBButton_released();
    /**
     * @brief on_keyNButton_released when NButton was released
     */
    void on_keyNButton_released();
    /**
     * @brief on_keyMButton_released when MButton was released
     */
    void on_keyMButton_released();
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




    void setCurrentLay(int lay);


private:
bool qShift;
bool wShift;
bool eShift;
bool rShift;
bool tShift;
bool yShift;
bool uShift;
bool iShift;
bool oShift;
bool pShift;
bool aShift;
bool sShift;
bool dShift;
bool fShift;
bool gShift;
bool hShift;
bool jShift;
bool kShift;
bool lShift;
bool zShift;
bool xShift;
bool cShift;
bool vShift;
bool bShift;
bool nShift;
bool mShift;

int currentLay;

char qStatus[10];
char wStatus[10];
char eStatus[10];
char rStatus[10];
char tStatus[10];
char yStatus[10];
char uStatus[10];
char iStatus[10];
char oStatus[10];
char pStatus[10];
char aStatus[10];
char sStatus[10];
char dStatus[10];
char fStatus[10];
char gStatus[10];
char hStatus[10];
char jStatus[10];
char kStatus[10];
char lStatus[10];
char zStatus[10];
char xStatus[10];
char cStatus[10];
char vStatus[10];
char bStatus[10];
char nStatus[10];
char mStatus[10];
};

#endif // PLAYWINDOW_H
