#ifndef PLAYWINDOW_H
#define PLAYWINDOW_H

#include <QKeyEvent>
#include <QDialog>

namespace Ui {
class PlayWindow;
}

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
    void buttonPressedSignal(QChar key);
    void buttonReleasedSignal(QChar key);
    // QWidget interface
protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
private slots:

    //----------pressed----------------

    void on_keyQButton_pressed();
    void on_keyWButton_pressed();
    void on_keyEButton_pressed();
    void on_keyRButton_pressed();
    void on_keyTButton_pressed();
    void on_keyYButton_pressed();
    void on_keyUButton_pressed();
    void on_keyIButton_pressed();
    void on_keyOButton_pressed();
    void on_keyPButton_pressed();
    void on_keyAButton_pressed();
    void on_keySButton_pressed();
    void on_keyDButton_pressed();
    void on_keyFButton_pressed();
    void on_keyGButton_pressed();
    void on_keyHButton_pressed();
    void on_keyJButton_pressed();
    void on_keyKButton_pressed();
    void on_keyLButton_pressed();
    void on_keyZButton_pressed();
    void on_keyXButton_pressed();
    void on_keyCButton_pressed();
    void on_keyVButton_pressed();
    void on_keyBButton_pressed();
    void on_keyNButton_pressed();
    void on_keyMButton_pressed();
    void on_keyShiftButton_pressed();

    //-----------Released-----------------

    void on_keyQButton_released();
    void on_keyWButton_released();
    void on_keyEButton_released();
    void on_keyRButton_released();
    void on_keyTButton_released();
    void on_keyYButton_released();
    void on_keyUButton_released();
    void on_keyIButton_released();
    void on_keyOButton_released();
    void on_keyPButton_released();
    void on_keyAButton_released();
    void on_keySButton_released();
    void on_keyDButton_released();
    void on_keyFButton_released();
    void on_keyGButton_released();
    void on_keyHButton_released();
    void on_keyJButton_released();
    void on_keyKButton_released();
    void on_keyLButton_released();
    void on_keyZButton_released();
    void on_keyXButton_released();
    void on_keyCButton_released();
    void on_keyVButton_released();
    void on_keyBButton_released();
    void on_keyNButton_released();
    void on_keyMButton_released();
    void on_keyShiftButton_released();
};

#endif // PLAYWINDOW_H
