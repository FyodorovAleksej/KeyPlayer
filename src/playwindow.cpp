#include "playwindow.h"
#include "ui_playwindow.h"
#include "nullproperties.h"
#define POWER 10
#define passiveButtonColor QString::fromUtf8("background-color: rgb(248, 248, 10);")
#define activeButtonColor QString::fromUtf8("background-color: rgb(100, 248, 40);")
#define startButtonColor QString::fromUtf8("background-color: rgb(50, 50, 248);")
#define activePageColor QString::fromUtf8("background-color: rgb(235, 80, 235);")
#define passivePageColor NULL


PlayWindow::PlayWindow(QWidget *parent, Properties* prop) :
    QDialog(parent),
    ui(new Ui::PlayWindow)
{
    ui->setupUi(this);
    this->prop = prop;

    shift = false;
    caps = this->prop->getCaps();

    buttons.append(new PlayButton(ui->keyAButton, 'A'));
    buttons.append(new PlayButton(ui->keyBButton, 'B'));
    buttons.append(new PlayButton(ui->keyCButton, 'C'));
    buttons.append(new PlayButton(ui->keyDButton, 'D'));
    buttons.append(new PlayButton(ui->keyEButton, 'E'));
    buttons.append(new PlayButton(ui->keyFButton, 'F'));
    buttons.append(new PlayButton(ui->keyGButton, 'G'));
    buttons.append(new PlayButton(ui->keyHButton, 'H'));
    buttons.append(new PlayButton(ui->keyIButton, 'I'));
    buttons.append(new PlayButton(ui->keyJButton, 'J'));
    buttons.append(new PlayButton(ui->keyKButton, 'K'));
    buttons.append(new PlayButton(ui->keyLButton, 'L'));
    buttons.append(new PlayButton(ui->keyMButton, 'M'));
    buttons.append(new PlayButton(ui->keyNButton, 'N'));
    buttons.append(new PlayButton(ui->keyOButton, 'O'));
    buttons.append(new PlayButton(ui->keyPButton, 'P'));
    buttons.append(new PlayButton(ui->keyQButton, 'Q'));
    buttons.append(new PlayButton(ui->keyRButton, 'R'));
    buttons.append(new PlayButton(ui->keySButton, 'S'));
    buttons.append(new PlayButton(ui->keyTButton, 'T'));
    buttons.append(new PlayButton(ui->keyUButton, 'U'));
    buttons.append(new PlayButton(ui->keyVButton, 'V'));
    buttons.append(new PlayButton(ui->keyWButton, 'W'));
    buttons.append(new PlayButton(ui->keyXButton, 'X'));
    buttons.append(new PlayButton(ui->keyYButton, 'Y'));
    buttons.append(new PlayButton(ui->keyZButton, 'Z'));

    if (shift)
    {
        ui->keyShiftButton->setStyleSheet(activeButtonColor);
    }
    else
    {
        ui->keyShiftButton->setStyleSheet(passiveButtonColor);
    }

    if (caps)
    {
        ui->capsLockButton->setStyleSheet(activeButtonColor);
    }
    else
    {
        ui->capsLockButton->setStyleSheet(passiveButtonColor);
    }



    for (PlayButton* i : buttons)
    {
        connect(i, SIGNAL(pressed(QChar)), this, SLOT(on_playButton_pressed(QChar)));
        connect(i,SIGNAL(released(QChar)), this, SLOT(on_playButton_released(QChar)));
    }

    connect(ui->keyShiftButton,SIGNAL(pressed()),this,SLOT(on_keyShiftButton_pressed()));

    connect(ui->keyShiftButton,SIGNAL(released()),this,SLOT(on_keyShiftButton_released()));

    setCurrentLay(0);
}

PlayWindow::~PlayWindow()
{
    for (PlayButton* i : buttons)
    {
        delete i;
    }
    delete ui;
}

void PlayWindow::keyPressEvent(QKeyEvent *event)
{
    if (!event->isAutoRepeat())
    {
        switch(event->key())
        {
        case Qt::Key_Q: {on_playButton_pressed('Q'); break;}
        case Qt::Key_W: {on_playButton_pressed('W'); break;}
        case Qt::Key_E: {on_playButton_pressed('E'); break;}
        case Qt::Key_R: {on_playButton_pressed('R'); break;}
        case Qt::Key_T: {on_playButton_pressed('T'); break;}
        case Qt::Key_Y: {on_playButton_pressed('Y'); break;}
        case Qt::Key_U: {on_playButton_pressed('U'); break;}
        case Qt::Key_I: {on_playButton_pressed('I'); break;}
        case Qt::Key_O: {on_playButton_pressed('O'); break;}
        case Qt::Key_P: {on_playButton_pressed('P'); break;}
        case Qt::Key_A: {on_playButton_pressed('A'); break;}
        case Qt::Key_S: {on_playButton_pressed('S'); break;}
        case Qt::Key_D: {on_playButton_pressed('D'); break;}
        case Qt::Key_F: {on_playButton_pressed('F'); break;}
        case Qt::Key_G: {on_playButton_pressed('G'); break;}
        case Qt::Key_H: {on_playButton_pressed('H'); break;}
        case Qt::Key_J: {on_playButton_pressed('J'); break;}
        case Qt::Key_K: {on_playButton_pressed('K'); break;}
        case Qt::Key_L: {on_playButton_pressed('L'); break;}
        case Qt::Key_Z: {on_playButton_pressed('Z'); break;}
        case Qt::Key_X: {on_playButton_pressed('X'); break;}
        case Qt::Key_C: {on_playButton_pressed('C'); break;}
        case Qt::Key_V: {on_playButton_pressed('V'); break;}
        case Qt::Key_B: {on_playButton_pressed('B'); break;}
        case Qt::Key_N: {on_playButton_pressed('N'); break;}
        case Qt::Key_M: {on_playButton_pressed('M'); break;}
        case Qt::Key_Shift: {on_keyShiftButton_pressed(); break;}
        case Qt::Key_0: {on_push0Button_pressed(); break;}
        case Qt::Key_1: {on_push1Button_pressed(); break;}
        case Qt::Key_2: {on_push2Button_pressed(); break;}
        case Qt::Key_3: {on_push3Button_pressed(); break;}
        case Qt::Key_4: {on_push4Button_pressed(); break;}
        case Qt::Key_5: {on_push5Button_pressed(); break;}
        case Qt::Key_6: {on_push6Button_pressed(); break;}
        case Qt::Key_7: {on_push7Button_pressed(); break;}
        case Qt::Key_8: {on_push8Button_pressed(); break;}
        case Qt::Key_9: {on_push9Button_pressed(); break;}
        case Qt::Key_CapsLock: {on_capsLockButton_pressed(); break;}
        }
    }
}




void PlayWindow::keyReleaseEvent(QKeyEvent* event)
{
    if (!event->isAutoRepeat())
    {
        switch(event->key())
        {
        case Qt::Key_Q: {on_playButton_released('Q'); break;}
        case Qt::Key_W: {on_playButton_released('W'); break;}
        case Qt::Key_E: {on_playButton_released('E'); break;}
        case Qt::Key_R: {on_playButton_released('R'); break;}
        case Qt::Key_T: {on_playButton_released('T'); break;}
        case Qt::Key_Y: {on_playButton_released('Y'); break;}
        case Qt::Key_U: {on_playButton_released('U'); break;}
        case Qt::Key_I: {on_playButton_released('I'); break;}
        case Qt::Key_O: {on_playButton_released('O'); break;}
        case Qt::Key_P: {on_playButton_released('P'); break;}
        case Qt::Key_A: {on_playButton_released('A'); break;}
        case Qt::Key_S: {on_playButton_released('S'); break;}
        case Qt::Key_D: {on_playButton_released('D'); break;}
        case Qt::Key_F: {on_playButton_released('F'); break;}
        case Qt::Key_G: {on_playButton_released('G'); break;}
        case Qt::Key_H: {on_playButton_released('H'); break;}
        case Qt::Key_J: {on_playButton_released('J'); break;}
        case Qt::Key_K: {on_playButton_released('K'); break;}
        case Qt::Key_L: {on_playButton_released('L'); break;}
        case Qt::Key_Z: {on_playButton_released('Z'); break;}
        case Qt::Key_X: {on_playButton_released('X'); break;}
        case Qt::Key_C: {on_playButton_released('C'); break;}
        case Qt::Key_V: {on_playButton_released('V'); break;}
        case Qt::Key_B: {on_playButton_released('B'); break;}
        case Qt::Key_N: {on_playButton_released('N'); break;}
        case Qt::Key_M: {on_playButton_released('M'); break;}
        case Qt::Key_Shift: {on_keyShiftButton_released(); break;}
        case Qt::Key_0: {on_push0Button_released(); break;}
        case Qt::Key_1: {on_push1Button_released(); break;}
        case Qt::Key_2: {on_push2Button_released(); break;}
        case Qt::Key_3: {on_push3Button_released(); break;}
        case Qt::Key_4: {on_push4Button_released(); break;}
        case Qt::Key_5: {on_push5Button_released(); break;}
        case Qt::Key_6: {on_push6Button_released(); break;}
        case Qt::Key_7: {on_push7Button_released(); break;}
        case Qt::Key_8: {on_push8Button_released(); break;}
        case Qt::Key_9: {on_push9Button_released(); break;}
        case Qt::Key_CapsLock: {on_capsLockButton_released(); break;}
        }
    }
}

//----------PRESSED----------------------------------------


void PlayWindow::on_playButton_pressed(QChar key)
{
    if (buttons.length() > key.toLatin1() - 'A')
    {
        emit startSignal(buttons.at(key.toLatin1() - 'A')->getKey(), currentLay);
        buttons.at(key.toLatin1() - 'A')->wasPressed(currentLay, shift);
    }
}



void PlayWindow::on_keyShiftButton_pressed()
{
    shift = (!prop->getShift() || !caps);
    if (shift)
    {
        ui->keyShiftButton->setStyleSheet(activeButtonColor);
    }
    else
    {
        ui->keyShiftButton->setStyleSheet(passiveButtonColor);
    }
}


//---------RELEASED----------------------------------------

void PlayWindow::on_playButton_released(QChar key)
{
    if (buttons.length() > key.toLatin1() - 'A')
    {
        if (buttons.at(key.toLatin1() - 'A')->wasReleased(currentLay, shift))
        {
            emit stopSignal(buttons.at(key.toLatin1() - 'A')->getKey(), currentLay);
        }
    }
}

void PlayWindow::on_keyShiftButton_released()
{
        //emit buttonReleasedSignal('.');
        shift = caps;
        if (shift)
        {
            ui->keyShiftButton->setStyleSheet(activeButtonColor);
        }
        else
        {
            ui->keyShiftButton->setStyleSheet(passiveButtonColor);
        }
}



// -------------PAGES---------------------------------------



void PlayWindow::setCurrentLay(int lay)
{
    //emit buttonPressedSignal((char)lay + '0');
    switch(currentLay)
    {
    case 0:{this->ui->push0Button->setStyleSheet(passivePageColor); break;}
    case 1:{this->ui->push1Button->setStyleSheet(passivePageColor); break;}
    case 2:{this->ui->push2Button->setStyleSheet(passivePageColor); break;}
    case 3:{this->ui->push3Button->setStyleSheet(passivePageColor); break;}
    case 4:{this->ui->push4Button->setStyleSheet(passivePageColor); break;}
    case 5:{this->ui->push5Button->setStyleSheet(passivePageColor); break;}
    case 6:{this->ui->push6Button->setStyleSheet(passivePageColor); break;}
    case 7:{this->ui->push7Button->setStyleSheet(passivePageColor); break;}
    case 8:{this->ui->push8Button->setStyleSheet(passivePageColor); break;}
    case 9:{this->ui->push9Button->setStyleSheet(passivePageColor); break;}
    }

    this->currentLay = lay;

    switch(lay)
    {
    case 0:{this->ui->push0Button->setStyleSheet(activePageColor); break;}
    case 1:{this->ui->push1Button->setStyleSheet(activePageColor); break;}
    case 2:{this->ui->push2Button->setStyleSheet(activePageColor); break;}
    case 3:{this->ui->push3Button->setStyleSheet(activePageColor); break;}
    case 4:{this->ui->push4Button->setStyleSheet(activePageColor); break;}
    case 5:{this->ui->push5Button->setStyleSheet(activePageColor); break;}
    case 6:{this->ui->push6Button->setStyleSheet(activePageColor); break;}
    case 7:{this->ui->push7Button->setStyleSheet(activePageColor); break;}
    case 8:{this->ui->push8Button->setStyleSheet(activePageColor); break;}
    case 9:{this->ui->push9Button->setStyleSheet(activePageColor); break;}
    }

    for (PlayButton* i: buttons)
    {
        i->changeLay(lay);
    }

    if (!shift)
    {
        ui->keyShiftButton->setStyleSheet(passiveButtonColor);
    }
    else
    {
        ui->keyShiftButton->setStyleSheet(activeButtonColor);
    }

}


// -----------LAYERS--------------------------


void PlayWindow::on_push1Button_pressed()
{
    setCurrentLay(1);
}
void PlayWindow::on_push2Button_pressed()
{
    setCurrentLay(2);
}
void PlayWindow::on_push3Button_pressed()
{
    setCurrentLay(3);
}
void PlayWindow::on_push4Button_pressed()
{
    setCurrentLay(4);
}
void PlayWindow::on_push5Button_pressed()
{
    setCurrentLay(5);
}
void PlayWindow::on_push6Button_pressed()
{
    setCurrentLay(6);
}
void PlayWindow::on_push7Button_pressed()
{
    setCurrentLay(7);
}
void PlayWindow::on_push8Button_pressed()
{
    setCurrentLay(8);
}
void PlayWindow::on_push9Button_pressed()
{
    setCurrentLay(9);
}
void PlayWindow::on_push0Button_pressed()
{
    setCurrentLay(0);
}



//-------------RELEASES--------

void PlayWindow::on_push1Button_released()
{

}
void PlayWindow::on_push2Button_released()
{

}
void PlayWindow::on_push3Button_released()
{

}
void PlayWindow::on_push4Button_released()
{

}
void PlayWindow::on_push5Button_released()
{

}
void PlayWindow::on_push6Button_released()
{

}
void PlayWindow::on_push7Button_released()
{

}
void PlayWindow::on_push8Button_released()
{

}
void PlayWindow::on_push9Button_released()
{

}
void PlayWindow::on_push0Button_released()
{

}

void PlayWindow::on_capsLockButton_pressed()
{
    caps = !caps;
    shift = !shift;
    if (caps)
    {
       ui->capsLockButton->setStyleSheet(activeButtonColor);
       if (shift)
       {
           ui->keyShiftButton->setStyleSheet(activeButtonColor);
        }
       else
       {
           ui->keyShiftButton->setStyleSheet(passiveButtonColor);
       }
    }
    else
    {
        ui->capsLockButton->setStyleSheet(passiveButtonColor);
        if (shift)
        {
            ui->keyShiftButton->setStyleSheet(activeButtonColor);
         }
        else
        {
            ui->keyShiftButton->setStyleSheet(passiveButtonColor);
        }
    }
}

void PlayWindow::on_capsLockButton_released()
{

}
