#include "playwindow.h"
#include "ui_playwindow.h"
#include "nullproperties.h"
#define POWER 10
#define PASSIVE_BUTTON_COLOR QString::fromUtf8("background-color: rgb(248, 248, 10);")
#define ACTIVE_BUTTON_COLOR QString::fromUtf8("background-color: rgb(100, 248, 40);")
#define START_BUTTON_COLOR QString::fromUtf8("background-color: rgb(50, 50, 248);")
#define activePageColor QString::fromUtf8("background-color: rgb(235, 80, 235);")
#define passivePageColor NULL


PlayWindow::PlayWindow(QWidget *parent, Properties* prop) :
    QDialog(parent),
    ui_(new Ui::PlayWindow)
{
    ui_->setupUi(this);
    this->prop_ = prop;

    shift_ = false;
    caps_ = this->prop_->GetCaps();

    buttons_.append(new PlayButton(ui_->keyAButton, 'A'));
    buttons_.append(new PlayButton(ui_->keyBButton, 'B'));
    buttons_.append(new PlayButton(ui_->keyCButton, 'C'));
    buttons_.append(new PlayButton(ui_->keyDButton, 'D'));
    buttons_.append(new PlayButton(ui_->keyEButton, 'E'));
    buttons_.append(new PlayButton(ui_->keyFButton, 'F'));
    buttons_.append(new PlayButton(ui_->keyGButton, 'G'));
    buttons_.append(new PlayButton(ui_->keyHButton, 'H'));
    buttons_.append(new PlayButton(ui_->keyIButton, 'I'));
    buttons_.append(new PlayButton(ui_->keyJButton, 'J'));
    buttons_.append(new PlayButton(ui_->keyKButton, 'K'));
    buttons_.append(new PlayButton(ui_->keyLButton, 'L'));
    buttons_.append(new PlayButton(ui_->keyMButton, 'M'));
    buttons_.append(new PlayButton(ui_->keyNButton, 'N'));
    buttons_.append(new PlayButton(ui_->keyOButton, 'O'));
    buttons_.append(new PlayButton(ui_->keyPButton, 'P'));
    buttons_.append(new PlayButton(ui_->keyQButton, 'Q'));
    buttons_.append(new PlayButton(ui_->keyRButton, 'R'));
    buttons_.append(new PlayButton(ui_->keySButton, 'S'));
    buttons_.append(new PlayButton(ui_->keyTButton, 'T'));
    buttons_.append(new PlayButton(ui_->keyUButton, 'U'));
    buttons_.append(new PlayButton(ui_->keyVButton, 'V'));
    buttons_.append(new PlayButton(ui_->keyWButton, 'W'));
    buttons_.append(new PlayButton(ui_->keyXButton, 'X'));
    buttons_.append(new PlayButton(ui_->keyYButton, 'Y'));
    buttons_.append(new PlayButton(ui_->keyZButton, 'Z'));

    if (shift_)
    {
        ui_->keyShiftButton->setStyleSheet(ACTIVE_BUTTON_COLOR);
    }
    else
    {
        ui_->keyShiftButton->setStyleSheet(PASSIVE_BUTTON_COLOR);
    }

    if (caps_)
    {
        ui_->capsLockButton->setStyleSheet(ACTIVE_BUTTON_COLOR);
    }
    else
    {
        ui_->capsLockButton->setStyleSheet(PASSIVE_BUTTON_COLOR);
    }



    for (PlayButton* i : buttons_)
    {
        connect(i, SIGNAL(pressed(QChar)), this, SLOT(OnPlayButtonPressed(QChar)));
        connect(i,SIGNAL(released(QChar)), this, SLOT(OnPlayButtonReleased(QChar)));
    }

    connect(ui_->keyShiftButton, SIGNAL(pressed()), this, SLOT(OnKeyShiftButtonPressed()));
    connect(ui_->keyShiftButton, SIGNAL(released()), this, SLOT(OnKeyShiftButtonReleased()));

    SetCurrentLay(0);
}

PlayWindow::~PlayWindow()
{
    for (PlayButton* i : buttons_)
    {
        delete i;
    }
    delete ui_;
}

void PlayWindow::keyPressEvent(QKeyEvent *event)
{
    if (!event->isAutoRepeat())
    {
        switch(event->key())
        {
        case Qt::Key_Q: {OnPlayButtonPressed('Q'); break;}
        case Qt::Key_W: {OnPlayButtonPressed('W'); break;}
        case Qt::Key_E: {OnPlayButtonPressed('E'); break;}
        case Qt::Key_R: {OnPlayButtonPressed('R'); break;}
        case Qt::Key_T: {OnPlayButtonPressed('T'); break;}
        case Qt::Key_Y: {OnPlayButtonPressed('Y'); break;}
        case Qt::Key_U: {OnPlayButtonPressed('U'); break;}
        case Qt::Key_I: {OnPlayButtonPressed('I'); break;}
        case Qt::Key_O: {OnPlayButtonPressed('O'); break;}
        case Qt::Key_P: {OnPlayButtonPressed('P'); break;}
        case Qt::Key_A: {OnPlayButtonPressed('A'); break;}
        case Qt::Key_S: {OnPlayButtonPressed('S'); break;}
        case Qt::Key_D: {OnPlayButtonPressed('D'); break;}
        case Qt::Key_F: {OnPlayButtonPressed('F'); break;}
        case Qt::Key_G: {OnPlayButtonPressed('G'); break;}
        case Qt::Key_H: {OnPlayButtonPressed('H'); break;}
        case Qt::Key_J: {OnPlayButtonPressed('J'); break;}
        case Qt::Key_K: {OnPlayButtonPressed('K'); break;}
        case Qt::Key_L: {OnPlayButtonPressed('L'); break;}
        case Qt::Key_Z: {OnPlayButtonPressed('Z'); break;}
        case Qt::Key_X: {OnPlayButtonPressed('X'); break;}
        case Qt::Key_C: {OnPlayButtonPressed('C'); break;}
        case Qt::Key_V: {OnPlayButtonPressed('V'); break;}
        case Qt::Key_B: {OnPlayButtonPressed('B'); break;}
        case Qt::Key_N: {OnPlayButtonPressed('N'); break;}
        case Qt::Key_M: {OnPlayButtonPressed('M'); break;}
        case Qt::Key_Shift: {OnKeyShiftButtonPressed(); break;}
        case Qt::Key_0: {OnPush0ButtonPressed(); break;}
        case Qt::Key_1: {OnPush1ButtonPressed(); break;}
        case Qt::Key_2: {OnPush2ButtonPressed(); break;}
        case Qt::Key_3: {OnPush3ButtonPressed(); break;}
        case Qt::Key_4: {OnPush4ButtonPressed(); break;}
        case Qt::Key_5: {OnPush5ButtonPressed(); break;}
        case Qt::Key_6: {OnPush6ButtonPressed(); break;}
        case Qt::Key_7: {OnPush7ButtonPressed(); break;}
        case Qt::Key_8: {OnPush8ButtonPressed(); break;}
        case Qt::Key_9: {OnPush9ButtonPressed(); break;}
        case Qt::Key_CapsLock: {OnCapsLockButtonPressed(); break;}
		default: break;
        }
    }
}




void PlayWindow::keyReleaseEvent(QKeyEvent* event)
{
    if (!event->isAutoRepeat())
    {
        switch(event->key())
        {
        case Qt::Key_Q: {OnPlayButtonReleased('Q'); break;}
        case Qt::Key_W: {OnPlayButtonReleased('W'); break;}
        case Qt::Key_E: {OnPlayButtonReleased('E'); break;}
        case Qt::Key_R: {OnPlayButtonReleased('R'); break;}
        case Qt::Key_T: {OnPlayButtonReleased('T'); break;}
        case Qt::Key_Y: {OnPlayButtonReleased('Y'); break;}
        case Qt::Key_U: {OnPlayButtonReleased('U'); break;}
        case Qt::Key_I: {OnPlayButtonReleased('I'); break;}
        case Qt::Key_O: {OnPlayButtonReleased('O'); break;}
        case Qt::Key_P: {OnPlayButtonReleased('P'); break;}
        case Qt::Key_A: {OnPlayButtonReleased('A'); break;}
        case Qt::Key_S: {OnPlayButtonReleased('S'); break;}
        case Qt::Key_D: {OnPlayButtonReleased('D'); break;}
        case Qt::Key_F: {OnPlayButtonReleased('F'); break;}
        case Qt::Key_G: {OnPlayButtonReleased('G'); break;}
        case Qt::Key_H: {OnPlayButtonReleased('H'); break;}
        case Qt::Key_J: {OnPlayButtonReleased('J'); break;}
        case Qt::Key_K: {OnPlayButtonReleased('K'); break;}
        case Qt::Key_L: {OnPlayButtonReleased('L'); break;}
        case Qt::Key_Z: {OnPlayButtonReleased('Z'); break;}
        case Qt::Key_X: {OnPlayButtonReleased('X'); break;}
        case Qt::Key_C: {OnPlayButtonReleased('C'); break;}
        case Qt::Key_V: {OnPlayButtonReleased('V'); break;}
        case Qt::Key_B: {OnPlayButtonReleased('B'); break;}
        case Qt::Key_N: {OnPlayButtonReleased('N'); break;}
        case Qt::Key_M: {OnPlayButtonReleased('M'); break;}
        case Qt::Key_Shift: {OnKeyShiftButtonReleased(); break;}
        case Qt::Key_0: {OnPush0ButtonReleased(); break;}
        case Qt::Key_1: {OnPush1ButtonReleased(); break;}
        case Qt::Key_2: {OnPush2ButtonReleased(); break;}
        case Qt::Key_3: {OnPush3ButtonReleased(); break;}
        case Qt::Key_4: {OnPush4ButtonReleased(); break;}
        case Qt::Key_5: {OnPush5ButtonReleased(); break;}
        case Qt::Key_6: {OnPush6ButtonReleased(); break;}
        case Qt::Key_7: {OnPush7ButtonReleased(); break;}
        case Qt::Key_8: {OnPush8ButtonReleased(); break;}
        case Qt::Key_9: {OnPush9ButtonReleased(); break;}
        case Qt::Key_CapsLock: {OnCapsLockButtonReleased(); break;}
		default: break;
        }
    }
}

//----------PRESSED----------------------------------------


void PlayWindow::OnPlayButtonPressed(QChar key)
{
    if (buttons_.length() > key.toLatin1() - 'A')
    {
        emit startSignal(buttons_.at(key.toLatin1() - 'A')->GetKey(), current_lay_);
        buttons_.at(key.toLatin1() - 'A')->WasPressed(current_lay_, shift_);
    }
}



void PlayWindow::OnKeyShiftButtonPressed()
{
    shift_ = (!prop_->GetShift() || !caps_);
    if (shift_)
    {
        ui_->keyShiftButton->setStyleSheet(ACTIVE_BUTTON_COLOR);
    }
    else
    {
        ui_->keyShiftButton->setStyleSheet(PASSIVE_BUTTON_COLOR);
    }
}


//---------RELEASED----------------------------------------

void PlayWindow::OnPlayButtonReleased(QChar key)
{
    if (buttons_.length() > key.toLatin1() - 'A')
    {
        if (buttons_.at(key.toLatin1() - 'A')->WasReleased(current_lay_, shift_))
        {
            emit stopSignal(buttons_.at(key.toLatin1() - 'A')->GetKey(), current_lay_);
        }
    }
}

void PlayWindow::OnKeyShiftButtonReleased()
{
        shift_ = caps_;
        if (shift_)
        {
            ui_->keyShiftButton->setStyleSheet(ACTIVE_BUTTON_COLOR);
        }
        else
        {
            ui_->keyShiftButton->setStyleSheet(PASSIVE_BUTTON_COLOR);
        }
}



// -------------PAGES---------------------------------------



void PlayWindow::SetCurrentLay(int lay)
{
    switch(current_lay_)
    {
    case 0:{this->ui_->push0Button->setStyleSheet(passivePageColor); break;}
    case 1:{this->ui_->push1Button->setStyleSheet(passivePageColor); break;}
    case 2:{this->ui_->push2Button->setStyleSheet(passivePageColor); break;}
    case 3:{this->ui_->push3Button->setStyleSheet(passivePageColor); break;}
    case 4:{this->ui_->push4Button->setStyleSheet(passivePageColor); break;}
    case 5:{this->ui_->push5Button->setStyleSheet(passivePageColor); break;}
    case 6:{this->ui_->push6Button->setStyleSheet(passivePageColor); break;}
    case 7:{this->ui_->push7Button->setStyleSheet(passivePageColor); break;}
    case 8:{this->ui_->push8Button->setStyleSheet(passivePageColor); break;}
    case 9:{this->ui_->push9Button->setStyleSheet(passivePageColor); break;}
    default: break;
    }

    this->current_lay_ = lay;

    switch(lay)
    {
    case 0:{this->ui_->push0Button->setStyleSheet(activePageColor); break;}
    case 1:{this->ui_->push1Button->setStyleSheet(activePageColor); break;}
    case 2:{this->ui_->push2Button->setStyleSheet(activePageColor); break;}
    case 3:{this->ui_->push3Button->setStyleSheet(activePageColor); break;}
    case 4:{this->ui_->push4Button->setStyleSheet(activePageColor); break;}
    case 5:{this->ui_->push5Button->setStyleSheet(activePageColor); break;}
    case 6:{this->ui_->push6Button->setStyleSheet(activePageColor); break;}
    case 7:{this->ui_->push7Button->setStyleSheet(activePageColor); break;}
    case 8:{this->ui_->push8Button->setStyleSheet(activePageColor); break;}
    case 9:{this->ui_->push9Button->setStyleSheet(activePageColor); break;}
    default: break;
    }

    for (PlayButton* i: buttons_)
    {
        i->ChangeLay(lay);
    }

    if (!shift_)
    {
        ui_->keyShiftButton->setStyleSheet(PASSIVE_BUTTON_COLOR);
    }
    else
    {
        ui_->keyShiftButton->setStyleSheet(ACTIVE_BUTTON_COLOR);
    }

}


// -----------LAYERS--------------------------


void PlayWindow::OnPush1ButtonPressed()
{
    SetCurrentLay(1);
}
void PlayWindow::OnPush2ButtonPressed()
{
    SetCurrentLay(2);
}
void PlayWindow::OnPush3ButtonPressed()
{
    SetCurrentLay(3);
}
void PlayWindow::OnPush4ButtonPressed()
{
    SetCurrentLay(4);
}
void PlayWindow::OnPush5ButtonPressed()
{
    SetCurrentLay(5);
}
void PlayWindow::OnPush6ButtonPressed()
{
    SetCurrentLay(6);
}
void PlayWindow::OnPush7ButtonPressed()
{
    SetCurrentLay(7);
}
void PlayWindow::OnPush8ButtonPressed()
{
    SetCurrentLay(8);
}
void PlayWindow::OnPush9ButtonPressed()
{
    SetCurrentLay(9);
}
void PlayWindow::OnPush0ButtonPressed()
{
    SetCurrentLay(0);
}



//-------------RELEASES--------

void PlayWindow::OnPush1ButtonReleased() const
{

}
void PlayWindow::OnPush2ButtonReleased() const
{

}
void PlayWindow::OnPush3ButtonReleased() const
{

}
void PlayWindow::OnPush4ButtonReleased() const
{

}
void PlayWindow::OnPush5ButtonReleased() const
{

}
void PlayWindow::OnPush6ButtonReleased() const
{

}
void PlayWindow::OnPush7ButtonReleased() const
{

}
void PlayWindow::OnPush8ButtonReleased() const
{

}
void PlayWindow::OnPush9ButtonReleased() const
{

}
void PlayWindow::OnPush0ButtonReleased() const
{

}

void PlayWindow::OnCapsLockButtonPressed()
{
    caps_ = !caps_;
    shift_ = !shift_;
    if (caps_)
    {
       ui_->capsLockButton->setStyleSheet(ACTIVE_BUTTON_COLOR);
       if (shift_)
       {
           ui_->keyShiftButton->setStyleSheet(ACTIVE_BUTTON_COLOR);
        }
       else
       {
           ui_->keyShiftButton->setStyleSheet(PASSIVE_BUTTON_COLOR);
       }
    }
    else
    {
        ui_->capsLockButton->setStyleSheet(PASSIVE_BUTTON_COLOR);
        if (shift_)
        {
            ui_->keyShiftButton->setStyleSheet(ACTIVE_BUTTON_COLOR);
         }
        else
        {
            ui_->keyShiftButton->setStyleSheet(PASSIVE_BUTTON_COLOR);
        }
    }
}

void PlayWindow::OnCapsLockButtonReleased() const
{

}
