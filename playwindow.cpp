#include "playwindow.h"
#include "ui_playwindow.h"

PlayWindow::PlayWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlayWindow)
{
    ui->setupUi(this);

    shift = false;

    ui->keyQButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 10)"));
    ui->keyWButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 10)"));
    ui->keyEButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 10)"));
    ui->keyRButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 10)"));
    ui->keyTButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 10)"));
    ui->keyYButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 10)"));
    ui->keyUButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 10)"));
    ui->keyIButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 10)"));
    ui->keyOButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 10)"));
    ui->keyPButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 10)"));
    ui->keyAButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 10)"));
    ui->keySButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 10)"));
    ui->keyDButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 10)"));
    ui->keyFButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 10)"));
    ui->keyGButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 10)"));
    ui->keyHButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 10)"));
    ui->keyJButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 10)"));
    ui->keyKButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 10)"));
    ui->keyLButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 10)"));
    ui->keyZButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 10)"));
    ui->keyXButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 10)"));
    ui->keyCButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 10)"));
    ui->keyVButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 10)"));
    ui->keyBButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 10)"));
    ui->keyNButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 10)"));
    ui->keyMButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 10)"));
    ui->keyShiftButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 10)"));





    connect(ui->keyQButton,SIGNAL(pressed()),this,SLOT(on_keyQButton_pressed()));
    connect(ui->keyWButton,SIGNAL(pressed()),this,SLOT(on_keyWButton_pressed()));
    connect(ui->keyEButton,SIGNAL(pressed()),this,SLOT(on_keyEButton_pressed()));
    connect(ui->keyRButton,SIGNAL(pressed()),this,SLOT(on_keyRButton_pressed()));
    connect(ui->keyTButton,SIGNAL(pressed()),this,SLOT(on_keyTButton_pressed()));
    connect(ui->keyYButton,SIGNAL(pressed()),this,SLOT(on_keyYButton_pressed()));
    connect(ui->keyUButton,SIGNAL(pressed()),this,SLOT(on_keyUButton_pressed()));
    connect(ui->keyIButton,SIGNAL(pressed()),this,SLOT(on_keyIButton_pressed()));
    connect(ui->keyOButton,SIGNAL(pressed()),this,SLOT(on_keyOButton_pressed()));
    connect(ui->keyPButton,SIGNAL(pressed()),this,SLOT(on_keyPButton_pressed()));
    connect(ui->keyAButton,SIGNAL(pressed()),this,SLOT(on_keyAButton_pressed()));
    connect(ui->keySButton,SIGNAL(pressed()),this,SLOT(on_keySButton_pressed()));
    connect(ui->keyDButton,SIGNAL(pressed()),this,SLOT(on_keyDButton_pressed()));
    connect(ui->keyFButton,SIGNAL(pressed()),this,SLOT(on_keyFButton_pressed()));
    connect(ui->keyGButton,SIGNAL(pressed()),this,SLOT(on_keyGButton_pressed()));
    connect(ui->keyHButton,SIGNAL(pressed()),this,SLOT(on_keyHButton_pressed()));
    connect(ui->keyJButton,SIGNAL(pressed()),this,SLOT(on_keyJButton_pressed()));
    connect(ui->keyKButton,SIGNAL(pressed()),this,SLOT(on_keyKButton_pressed()));
    connect(ui->keyLButton,SIGNAL(pressed()),this,SLOT(on_keyLButton_pressed()));
    connect(ui->keyZButton,SIGNAL(pressed()),this,SLOT(on_keyZButton_pressed()));
    connect(ui->keyXButton,SIGNAL(pressed()),this,SLOT(on_keyXButton_pressed()));
    connect(ui->keyCButton,SIGNAL(pressed()),this,SLOT(on_keyCButton_pressed()));
    connect(ui->keyVButton,SIGNAL(pressed()),this,SLOT(on_keyVButton_pressed()));
    connect(ui->keyBButton,SIGNAL(pressed()),this,SLOT(on_keyBButton_pressed()));
    connect(ui->keyNButton,SIGNAL(pressed()),this,SLOT(on_keyNButton_pressed()));
    connect(ui->keyMButton,SIGNAL(pressed()),this,SLOT(on_keyMButton_pressed()));
    connect(ui->keyShiftButton,SIGNAL(pressed()),this,SLOT(on_keyShiftButton_pressed()));



    connect(ui->keyQButton,SIGNAL(released()),this,SLOT(on_keyQButton_released()));
    connect(ui->keyWButton,SIGNAL(released()),this,SLOT(on_keyWButton_released()));
    connect(ui->keyEButton,SIGNAL(released()),this,SLOT(on_keyEButton_released()));
    connect(ui->keyRButton,SIGNAL(released()),this,SLOT(on_keyRButton_released()));
    connect(ui->keyTButton,SIGNAL(released()),this,SLOT(on_keyTButton_released()));
    connect(ui->keyYButton,SIGNAL(released()),this,SLOT(on_keyYButton_released()));
    connect(ui->keyUButton,SIGNAL(released()),this,SLOT(on_keyUButton_released()));
    connect(ui->keyIButton,SIGNAL(released()),this,SLOT(on_keyIButton_released()));
    connect(ui->keyOButton,SIGNAL(released()),this,SLOT(on_keyOButton_released()));
    connect(ui->keyPButton,SIGNAL(released()),this,SLOT(on_keyPButton_released()));
    connect(ui->keyAButton,SIGNAL(released()),this,SLOT(on_keyAButton_released()));
    connect(ui->keySButton,SIGNAL(released()),this,SLOT(on_keySButton_released()));
    connect(ui->keyDButton,SIGNAL(released()),this,SLOT(on_keyDButton_released()));
    connect(ui->keyFButton,SIGNAL(released()),this,SLOT(on_keyFButton_released()));
    connect(ui->keyGButton,SIGNAL(released()),this,SLOT(on_keyGButton_released()));
    connect(ui->keyHButton,SIGNAL(released()),this,SLOT(on_keyHButton_released()));
    connect(ui->keyJButton,SIGNAL(released()),this,SLOT(on_keyJButton_released()));
    connect(ui->keyKButton,SIGNAL(released()),this,SLOT(on_keyKButton_released()));
    connect(ui->keyLButton,SIGNAL(released()),this,SLOT(on_keyLButton_released()));
    connect(ui->keyZButton,SIGNAL(released()),this,SLOT(on_keyZButton_released()));
    connect(ui->keyXButton,SIGNAL(released()),this,SLOT(on_keyXButton_released()));
    connect(ui->keyCButton,SIGNAL(released()),this,SLOT(on_keyCButton_released()));
    connect(ui->keyVButton,SIGNAL(released()),this,SLOT(on_keyVButton_released()));
    connect(ui->keyBButton,SIGNAL(released()),this,SLOT(on_keyBButton_released()));
    connect(ui->keyNButton,SIGNAL(released()),this,SLOT(on_keyNButton_released()));
    connect(ui->keyMButton,SIGNAL(released()),this,SLOT(on_keyMButton_released()));
    connect(ui->keyShiftButton,SIGNAL(released()),this,SLOT(on_keyShiftButton_released()));
}

PlayWindow::~PlayWindow()
{
    delete ui;
}

void PlayWindow::keyPressEvent(QKeyEvent *event)
{
    if (!event->isAutoRepeat())
    {
        switch(event->key())
        {
        case Qt::Key_Q: {on_keyQButton_pressed(); break;}
        case Qt::Key_W: {on_keyWButton_pressed(); break;}
        case Qt::Key_E: {on_keyEButton_pressed(); break;}
        case Qt::Key_R: {on_keyRButton_pressed(); break;}
        case Qt::Key_T: {on_keyTButton_pressed(); break;}
        case Qt::Key_Y: {on_keyYButton_pressed(); break;}
        case Qt::Key_U: {on_keyUButton_pressed(); break;}
        case Qt::Key_I: {on_keyIButton_pressed(); break;}
        case Qt::Key_O: {on_keyOButton_pressed(); break;}
        case Qt::Key_P: {on_keyPButton_pressed(); break;}
        case Qt::Key_A: {on_keyAButton_pressed(); break;}
        case Qt::Key_S: {on_keySButton_pressed(); break;}
        case Qt::Key_D: {on_keyDButton_pressed(); break;}
        case Qt::Key_F: {on_keyFButton_pressed(); break;}
        case Qt::Key_G: {on_keyGButton_pressed(); break;}
        case Qt::Key_H: {on_keyHButton_pressed(); break;}
        case Qt::Key_J: {on_keyJButton_pressed(); break;}
        case Qt::Key_K: {on_keyKButton_pressed(); break;}
        case Qt::Key_L: {on_keyLButton_pressed(); break;}
        case Qt::Key_Z: {on_keyZButton_pressed(); break;}
        case Qt::Key_X: {on_keyXButton_pressed(); break;}
        case Qt::Key_C: {on_keyCButton_pressed(); break;}
        case Qt::Key_V: {on_keyVButton_pressed(); break;}
        case Qt::Key_B: {on_keyBButton_pressed(); break;}
        case Qt::Key_N: {on_keyNButton_pressed(); break;}
        case Qt::Key_M: {on_keyMButton_pressed(); break;}
        case Qt::Key_Shift: {on_keyShiftButton_pressed(); break;}
        }
    }
}




void PlayWindow::keyReleaseEvent(QKeyEvent* event)
{
    if (!event->isAutoRepeat())
    {
        switch(event->key())
        {
        case Qt::Key_Q: {on_keyQButton_released(); break;}
        case Qt::Key_W: {on_keyWButton_released(); break;}
        case Qt::Key_E: {on_keyEButton_released(); break;}
        case Qt::Key_R: {on_keyRButton_released(); break;}
        case Qt::Key_T: {on_keyTButton_released(); break;}
        case Qt::Key_Y: {on_keyYButton_released(); break;}
        case Qt::Key_U: {on_keyUButton_released(); break;}
        case Qt::Key_I: {on_keyIButton_released(); break;}
        case Qt::Key_O: {on_keyOButton_released(); break;}
        case Qt::Key_P: {on_keyPButton_released(); break;}
        case Qt::Key_A: {on_keyAButton_released(); break;}
        case Qt::Key_S: {on_keySButton_released(); break;}
        case Qt::Key_D: {on_keyDButton_released(); break;}
        case Qt::Key_F: {on_keyFButton_released(); break;}
        case Qt::Key_G: {on_keyGButton_released(); break;}
        case Qt::Key_H: {on_keyHButton_released(); break;}
        case Qt::Key_J: {on_keyJButton_released(); break;}
        case Qt::Key_K: {on_keyKButton_released(); break;}
        case Qt::Key_L: {on_keyLButton_released(); break;}
        case Qt::Key_Z: {on_keyZButton_released(); break;}
        case Qt::Key_X: {on_keyXButton_released(); break;}
        case Qt::Key_C: {on_keyCButton_released(); break;}
        case Qt::Key_V: {on_keyVButton_released(); break;}
        case Qt::Key_B: {on_keyBButton_released(); break;}
        case Qt::Key_N: {on_keyNButton_released(); break;}
        case Qt::Key_M: {on_keyMButton_released(); break;}
        case Qt::Key_Shift: {on_keyShiftButton_released(); break;}
        }
    }
}

//----------PRESSED----------------------------------------


void PlayWindow::on_keyQButton_pressed()
{
    emit buttonPressedSignal('Q');
    ui->keyQButton->setStyleSheet(QString::fromUtf8("background-color: rgb(100, 248, 40);"));
}
void PlayWindow::on_keyWButton_pressed()
{
    emit buttonPressedSignal('W');
    ui->keyWButton->setStyleSheet(QString::fromUtf8("background-color: rgb(100, 248, 40);"));
}
void PlayWindow::on_keyEButton_pressed()
{
    emit buttonPressedSignal('E');
    ui->keyEButton->setStyleSheet(QString::fromUtf8("background-color: rgb(100, 248, 40);"));
}
void PlayWindow::on_keyRButton_pressed()
{
    emit buttonPressedSignal('R');
    ui->keyRButton->setStyleSheet(QString::fromUtf8("background-color: rgb(100, 248, 40);"));
}
void PlayWindow::on_keyTButton_pressed()
{
    emit buttonPressedSignal('T');
    ui->keyTButton->setStyleSheet(QString::fromUtf8("background-color: rgb(100, 248, 40);"));
}
void PlayWindow::on_keyYButton_pressed()
{
    emit buttonPressedSignal('Y');
    ui->keyYButton->setStyleSheet(QString::fromUtf8("background-color: rgb(100, 248, 40);"));
}
void PlayWindow::on_keyUButton_pressed()
{
    emit buttonPressedSignal('U');
    ui->keyUButton->setStyleSheet(QString::fromUtf8("background-color: rgb(100, 248, 40);"));
}
void PlayWindow::on_keyIButton_pressed()
{
    emit buttonPressedSignal('I');
    ui->keyIButton->setStyleSheet(QString::fromUtf8("background-color: rgb(100, 248, 40);"));
}
void PlayWindow::on_keyOButton_pressed()
{
    emit buttonPressedSignal('O');
    ui->keyOButton->setStyleSheet(QString::fromUtf8("background-color: rgb(100, 248, 40);"));
}
void PlayWindow::on_keyPButton_pressed()
{
    emit buttonPressedSignal('P');
    ui->keyPButton->setStyleSheet(QString::fromUtf8("background-color: rgb(100, 248, 40);"));
}
void PlayWindow::on_keyAButton_pressed()
{
    emit buttonPressedSignal('A');
    ui->keyAButton->setStyleSheet(QString::fromUtf8("background-color: rgb(100, 248, 40);"));
}
void PlayWindow::on_keySButton_pressed()
{
    emit buttonPressedSignal('S');
    ui->keySButton->setStyleSheet(QString::fromUtf8("background-color: rgb(100, 248, 40);"));
}
void PlayWindow::on_keyDButton_pressed()
{
    emit buttonPressedSignal('D');
    ui->keyDButton->setStyleSheet(QString::fromUtf8("background-color: rgb(100, 248, 40);"));
}
void PlayWindow::on_keyFButton_pressed()
{
    emit buttonPressedSignal('F');
    ui->keyFButton->setStyleSheet(QString::fromUtf8("background-color: rgb(100, 248, 40);"));
}
void PlayWindow::on_keyGButton_pressed()
{
    emit buttonPressedSignal('G');
    ui->keyGButton->setStyleSheet(QString::fromUtf8("background-color: rgb(100, 248, 40);"));
}
void PlayWindow::on_keyHButton_pressed()
{
    emit buttonPressedSignal('H');
    ui->keyHButton->setStyleSheet(QString::fromUtf8("background-color: rgb(100, 248, 40);"));
}
void PlayWindow::on_keyJButton_pressed()
{
    emit buttonPressedSignal('J');
    ui->keyJButton->setStyleSheet(QString::fromUtf8("background-color: rgb(100, 248, 40);"));
}
void PlayWindow::on_keyKButton_pressed()
{
    emit buttonPressedSignal('K');
    ui->keyKButton->setStyleSheet(QString::fromUtf8("background-color: rgb(100, 248, 40);"));
}
void PlayWindow::on_keyLButton_pressed()
{
    emit buttonPressedSignal('L');
    ui->keyLButton->setStyleSheet(QString::fromUtf8("background-color: rgb(100, 248, 40);"));
}
void PlayWindow::on_keyZButton_pressed()
{
    emit buttonPressedSignal('Z');
    ui->keyZButton->setStyleSheet(QString::fromUtf8("background-color: rgb(100, 248, 40);"));
}
void PlayWindow::on_keyXButton_pressed()
{
    emit buttonPressedSignal('X');
    ui->keyXButton->setStyleSheet(QString::fromUtf8("background-color: rgb(100, 248, 40);"));
}
void PlayWindow::on_keyCButton_pressed()
{
    emit buttonPressedSignal('C');
    ui->keyCButton->setStyleSheet(QString::fromUtf8("background-color: rgb(100, 248, 40);"));
}
void PlayWindow::on_keyVButton_pressed()
{
    emit buttonPressedSignal('V');
    ui->keyVButton->setStyleSheet(QString::fromUtf8("background-color: rgb(100, 248, 40);"));
}
void PlayWindow::on_keyBButton_pressed()
{
    emit buttonPressedSignal('B');
    ui->keyBButton->setStyleSheet(QString::fromUtf8("background-color: rgb(100, 248, 40);"));
}
void PlayWindow::on_keyNButton_pressed()
{
    emit buttonPressedSignal('N');
    ui->keyNButton->setStyleSheet(QString::fromUtf8("background-color: rgb(100, 248, 40);"));
}
void PlayWindow::on_keyMButton_pressed()
{
    emit buttonPressedSignal('M');
    ui->keyMButton->setStyleSheet(QString::fromUtf8("background-color: rgb(100, 248, 40);"));
}
void PlayWindow::on_keyShiftButton_pressed()
{
    emit buttonPressedSignal('.');
    shift = !shift;
    if (shift)
        ui->keyShiftButton->setStyleSheet(QString::fromUtf8("background-color: rgb(100, 248, 40);"));
    else
        ui->keyShiftButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 10);"));
}


//---------RELEASED----------------------------------------


void PlayWindow::on_keyQButton_released()
{
    emit buttonReleasedSignal('Q');
    ui->keyQButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 10);"));
}
void PlayWindow::on_keyWButton_released()
{
    emit buttonReleasedSignal('W');
    ui->keyWButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 10);"));
}
void PlayWindow::on_keyEButton_released()
{
    emit buttonReleasedSignal('E');
    ui->keyEButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 10);"));
}
void PlayWindow::on_keyRButton_released()
{
    emit buttonReleasedSignal('R');
    ui->keyRButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 10);"));
}
void PlayWindow::on_keyTButton_released()
{
    emit buttonReleasedSignal('T');
    ui->keyTButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 10);"));
}
void PlayWindow::on_keyYButton_released()
{
    emit buttonReleasedSignal('Y');
    ui->keyYButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 10);"));
}
void PlayWindow::on_keyUButton_released()
{
    emit buttonReleasedSignal('U');
    ui->keyUButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 10);"));
}
void PlayWindow::on_keyIButton_released()
{
    emit buttonReleasedSignal('I');
    ui->keyIButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 10);"));
}
void PlayWindow::on_keyOButton_released()
{
    emit buttonReleasedSignal('O');
    ui->keyOButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 10);"));
}
void PlayWindow::on_keyPButton_released()
{
    emit buttonReleasedSignal('P');
    ui->keyPButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 10);"));
}
void PlayWindow::on_keyAButton_released()
{
    emit buttonReleasedSignal('A');
    ui->keyAButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 10);"));
}
void PlayWindow::on_keySButton_released()
{
    emit buttonReleasedSignal('S');
    ui->keySButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 10);"));
}
void PlayWindow::on_keyDButton_released()
{
    emit buttonReleasedSignal('D');
    ui->keyDButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 10);"));
}
void PlayWindow::on_keyFButton_released()
{
    emit buttonReleasedSignal('F');
    ui->keyFButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 10);"));
}
void PlayWindow::on_keyGButton_released()
{
    emit buttonReleasedSignal('G');
    ui->keyGButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 10);"));
}
void PlayWindow::on_keyHButton_released()
{
    emit buttonReleasedSignal('H');
    ui->keyHButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 10);"));
}
void PlayWindow::on_keyJButton_released()
{
    emit buttonReleasedSignal('J');
    ui->keyJButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 10);"));
}
void PlayWindow::on_keyKButton_released()
{
    emit buttonReleasedSignal('K');
    ui->keyKButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 10);"));
}
void PlayWindow::on_keyLButton_released()
{
    emit buttonReleasedSignal('L');
    ui->keyLButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 10);"));
}
void PlayWindow::on_keyZButton_released()
{
    emit buttonReleasedSignal('Z');
    ui->keyZButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 10);"));
}
void PlayWindow::on_keyXButton_released()
{
    emit buttonReleasedSignal('X');
    ui->keyXButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 10);"));
}
void PlayWindow::on_keyCButton_released()
{
    emit buttonReleasedSignal('C');
    ui->keyCButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 10);"));
}
void PlayWindow::on_keyVButton_released()
{
    emit buttonReleasedSignal('V');
    ui->keyVButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 10);"));
}
void PlayWindow::on_keyBButton_released()
{
    emit buttonReleasedSignal('B');
    ui->keyBButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 10);"));
}
void PlayWindow::on_keyNButton_released()
{
    emit buttonReleasedSignal('N');
    ui->keyNButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 10);"));
}
void PlayWindow::on_keyMButton_released()
{
    emit buttonReleasedSignal('M');
    ui->keyMButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 10);"));
}
void PlayWindow::on_keyShiftButton_released()
{
    emit buttonReleasedSignal('.');
}
