#include "playwindow.h"
#include "ui_playwindow.h"
#define POWER 10
#define passiveButtonColor QString::fromUtf8("background-color: rgb(248, 248, 10);")
#define activeButtonColor QString::fromUtf8("background-color: rgb(100, 248, 40);")
#define startButtonColor QString::fromUtf8("background-color: rgb(50, 50, 248);")
#define activePageColor QString::fromUtf8("background-color: rgb(235, 80, 235);")
#define passivePageColor NULL


PlayWindow::PlayWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlayWindow)
{
    ui->setupUi(this);

    shift = false;

    ui->keyQButton->setStyleSheet(passiveButtonColor);
    ui->keyWButton->setStyleSheet(passiveButtonColor);
    ui->keyEButton->setStyleSheet(passiveButtonColor);
    ui->keyRButton->setStyleSheet(passiveButtonColor);
    ui->keyTButton->setStyleSheet(passiveButtonColor);
    ui->keyYButton->setStyleSheet(passiveButtonColor);
    ui->keyUButton->setStyleSheet(passiveButtonColor);
    ui->keyIButton->setStyleSheet(passiveButtonColor);
    ui->keyOButton->setStyleSheet(passiveButtonColor);
    ui->keyPButton->setStyleSheet(passiveButtonColor);
    ui->keyAButton->setStyleSheet(passiveButtonColor);
    ui->keySButton->setStyleSheet(passiveButtonColor);
    ui->keyDButton->setStyleSheet(passiveButtonColor);
    ui->keyFButton->setStyleSheet(passiveButtonColor);
    ui->keyGButton->setStyleSheet(passiveButtonColor);
    ui->keyHButton->setStyleSheet(passiveButtonColor);
    ui->keyJButton->setStyleSheet(passiveButtonColor);
    ui->keyKButton->setStyleSheet(passiveButtonColor);
    ui->keyLButton->setStyleSheet(passiveButtonColor);
    ui->keyZButton->setStyleSheet(passiveButtonColor);
    ui->keyXButton->setStyleSheet(passiveButtonColor);
    ui->keyCButton->setStyleSheet(passiveButtonColor);
    ui->keyVButton->setStyleSheet(passiveButtonColor);
    ui->keyBButton->setStyleSheet(passiveButtonColor);
    ui->keyNButton->setStyleSheet(passiveButtonColor);
    ui->keyMButton->setStyleSheet(passiveButtonColor);
    ui->keyShiftButton->setStyleSheet(passiveButtonColor);





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

    qShift = false;
    wShift = false;
    eShift = false;
    rShift = false;
    tShift = false;
    yShift = false;
    uShift = false;
    iShift = false;
    oShift = false;
    pShift = false;
    aShift = false;
    sShift = false;
    dShift = false;
    fShift = false;
    gShift = false;
    hShift = false;
    jShift = false;
    kShift = false;
    lShift = false;
    zShift = false;
    xShift = false;
    cShift = false;
    vShift = false;
    bShift = false;
    nShift = false;
    mShift = false;


    int i;
    for (i = 0; i< POWER; i++) qStatus[i] = (char)0;
    for (i = 0; i< POWER; i++) wStatus[i] = (char)0;
    for (i = 0; i< POWER; i++) eStatus[i] = (char)0;
    for (i = 0; i< POWER; i++) rStatus[i] = (char)0;
    for (i = 0; i< POWER; i++) tStatus[i] = (char)0;
    for (i = 0; i< POWER; i++) yStatus[i] = (char)0;
    for (i = 0; i< POWER; i++) uStatus[i] = (char)0;
    for (i = 0; i< POWER; i++) iStatus[i] = (char)0;
    for (i = 0; i< POWER; i++) oStatus[i] = (char)0;
    for (i = 0; i< POWER; i++) pStatus[i] = (char)0;
    for (i = 0; i< POWER; i++) aStatus[i] = (char)0;
    for (i = 0; i< POWER; i++) sStatus[i] = (char)0;
    for (i = 0; i< POWER; i++) dStatus[i] = (char)0;
    for (i = 0; i< POWER; i++) fStatus[i] = (char)0;
    for (i = 0; i< POWER; i++) gStatus[i] = (char)0;
    for (i = 0; i< POWER; i++) hStatus[i] = (char)0;
    for (i = 0; i< POWER; i++) jStatus[i] = (char)0;
    for (i = 0; i< POWER; i++) kStatus[i] = (char)0;
    for (i = 0; i< POWER; i++) lStatus[i] = (char)0;
    for (i = 0; i< POWER; i++) zStatus[i] = (char)0;
    for (i = 0; i< POWER; i++) xStatus[i] = (char)0;
    for (i = 0; i< POWER; i++) cStatus[i] = (char)0;
    for (i = 0; i< POWER; i++) vStatus[i] = (char)0;
    for (i = 0; i< POWER; i++) bStatus[i] = (char)0;
    for (i = 0; i< POWER; i++) nStatus[i] = (char)0;
    for (i = 0; i< POWER; i++) mStatus[i] = (char)0;

    setCurrentLay(0);
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
        }
    }
}

//----------PRESSED----------------------------------------


void PlayWindow::on_keyQButton_pressed()
{
    emit buttonPressedSignal('Q');
    ui->keyQButton->setStyleSheet(activeButtonColor);
    qStatus[currentLay] = 1;
    if (shift)
    {
        qShift = !qShift;
    }
}
void PlayWindow::on_keyWButton_pressed()
{
    emit buttonPressedSignal('W');
    ui->keyWButton->setStyleSheet(activeButtonColor);
    wStatus[currentLay] = 1;
    if (shift)
    {
        wShift = !wShift;
    }
}
void PlayWindow::on_keyEButton_pressed()
{
    emit buttonPressedSignal('E');
    ui->keyEButton->setStyleSheet(activeButtonColor);
    eStatus[currentLay] = 1;
    if (shift)
    {
        eShift = !eShift;
    }
}
void PlayWindow::on_keyRButton_pressed()
{
    emit buttonPressedSignal('R');
    ui->keyRButton->setStyleSheet(activeButtonColor);
    rStatus[currentLay] = 1;
    if (shift)
    {
        rShift = !rShift;
    }
}
void PlayWindow::on_keyTButton_pressed()
{
    emit buttonPressedSignal('T');
    ui->keyTButton->setStyleSheet(activeButtonColor);
    tStatus[currentLay] = 1;
    if (shift)
    {
        tShift = !tShift;
    }
}
void PlayWindow::on_keyYButton_pressed()
{
    emit buttonPressedSignal('Y');
    ui->keyYButton->setStyleSheet(activeButtonColor);
    yStatus[currentLay] = 1;
    if (shift)
    {
        yShift = !yShift;
    }
}
void PlayWindow::on_keyUButton_pressed()
{
    emit buttonPressedSignal('U');
    ui->keyUButton->setStyleSheet(activeButtonColor);
    uStatus[currentLay] = 1;
    if (shift)
    {
        uShift = !uShift;
    }
}
void PlayWindow::on_keyIButton_pressed()
{
    emit buttonPressedSignal('I');
    ui->keyIButton->setStyleSheet(activeButtonColor);
    iStatus[currentLay] = 1;
    if (shift)
    {
        iShift = !iShift;
    }
}
void PlayWindow::on_keyOButton_pressed()
{
    emit buttonPressedSignal('O');
    ui->keyOButton->setStyleSheet(activeButtonColor);
    oStatus[currentLay] = 1;
    if (shift)
    {
        oShift = !oShift;
    }
}
void PlayWindow::on_keyPButton_pressed()
{
    emit buttonPressedSignal('P');
    ui->keyPButton->setStyleSheet(activeButtonColor);
    pStatus[currentLay] = 1;
    if (shift)
    {
        pShift = !pShift;
    }
}
void PlayWindow::on_keyAButton_pressed()
{
    emit buttonPressedSignal('A');
    ui->keyAButton->setStyleSheet(activeButtonColor);
    aStatus[currentLay] = 1;
    if (shift)
    {
        aShift = !aShift;
    }
}
void PlayWindow::on_keySButton_pressed()
{
    emit buttonPressedSignal('S');
    ui->keySButton->setStyleSheet(activeButtonColor);
    sStatus[currentLay] = 1;
    if (shift)
    {
        sShift = !sShift;
    }
}
void PlayWindow::on_keyDButton_pressed()
{
    emit buttonPressedSignal('D');
    ui->keyDButton->setStyleSheet(activeButtonColor);
    dStatus[currentLay] = 1;
    if (shift)
    {
        dShift = !dShift;
    }
}
void PlayWindow::on_keyFButton_pressed()
{
    emit buttonPressedSignal('F');
    ui->keyFButton->setStyleSheet(activeButtonColor);
    fStatus[currentLay] = 1;
    if (shift)
    {
        fShift = !fShift;
    }
}
void PlayWindow::on_keyGButton_pressed()
{
    emit buttonPressedSignal('G');
    ui->keyGButton->setStyleSheet(activeButtonColor);
    gStatus[currentLay] = 1;
    if (shift)
    {
        gShift = !gShift;
    }
}
void PlayWindow::on_keyHButton_pressed()
{
    emit buttonPressedSignal('H');
    ui->keyHButton->setStyleSheet(activeButtonColor);
    hStatus[currentLay] = 1;
    if (shift)
    {
        hShift = !hShift;
    }
}
void PlayWindow::on_keyJButton_pressed()
{
    emit buttonPressedSignal('J');
    ui->keyJButton->setStyleSheet(activeButtonColor);
    jStatus[currentLay] = 1;
    if (shift)
    {
        jShift = !jShift;
    }
}
void PlayWindow::on_keyKButton_pressed()
{
    emit buttonPressedSignal('K');
    ui->keyKButton->setStyleSheet(activeButtonColor);
    kStatus[currentLay] = 1;
    if (shift)
    {
        kShift = !kShift;
    }
}
void PlayWindow::on_keyLButton_pressed()
{
    emit buttonPressedSignal('L');
    ui->keyLButton->setStyleSheet(activeButtonColor);
    lStatus[currentLay] = 1;
    if (shift)
    {
        lShift = !lShift;
    }
}
void PlayWindow::on_keyZButton_pressed()
{
    emit buttonPressedSignal('Z');
    ui->keyZButton->setStyleSheet(activeButtonColor);
    zStatus[currentLay] = 1;
    if (shift)
    {
        zShift = !zShift;
    }
}
void PlayWindow::on_keyXButton_pressed()
{
    emit buttonPressedSignal('X');
    ui->keyXButton->setStyleSheet(activeButtonColor);
    xStatus[currentLay] = 1;
    if (shift)
    {
        xShift = !xShift;
    }
}
void PlayWindow::on_keyCButton_pressed()
{
    emit buttonPressedSignal('C');
    ui->keyCButton->setStyleSheet(activeButtonColor);
    cStatus[currentLay] = 1;
    if (shift)
    {
        cShift = !cShift;
    }
}
void PlayWindow::on_keyVButton_pressed()
{
    emit buttonPressedSignal('V');
    ui->keyVButton->setStyleSheet(activeButtonColor);
    vStatus[currentLay] = 1;
    if (shift)
    {
        vShift = !vShift;
    }
}
void PlayWindow::on_keyBButton_pressed()
{
    emit buttonPressedSignal('B');
    ui->keyBButton->setStyleSheet(activeButtonColor);
    bStatus[currentLay] = 1;
    if (shift)
    {
        bShift = !bShift;
    }
}
void PlayWindow::on_keyNButton_pressed()
{
    emit buttonPressedSignal('N');
    ui->keyNButton->setStyleSheet(activeButtonColor);
    nStatus[currentLay] = 1;
    if (shift)
    {
        nShift = !nShift;
    }
}
void PlayWindow::on_keyMButton_pressed()
{
    emit buttonPressedSignal('M');
    ui->keyMButton->setStyleSheet(activeButtonColor);
    mStatus[currentLay] = 1;
    if (shift)
    {
        mShift = !mShift;
    }
}
void PlayWindow::on_keyShiftButton_pressed()
{
    emit buttonPressedSignal('.');
    shift = true;
    ui->keyShiftButton->setStyleSheet(activeButtonColor);
}


//---------RELEASED----------------------------------------


void PlayWindow::on_keyQButton_released()
{
    emit buttonReleasedSignal('Q');
    if (!qShift || !shift)
    {
        qShift = false;
        ui->keyQButton->setStyleSheet(passiveButtonColor);
        qStatus[currentLay] = 0;
    }
    else
    {
        ui->keyQButton->setStyleSheet(startButtonColor);
        qStatus[currentLay] = 2;
    }
}
void PlayWindow::on_keyWButton_released()
{
    emit buttonReleasedSignal('W');
    if (!wShift || !shift)
    {
        wShift = false;
        ui->keyWButton->setStyleSheet(passiveButtonColor);
        wStatus[currentLay] = 0;
    }
    else
    {
        ui->keyWButton->setStyleSheet(startButtonColor);
        wStatus[currentLay] = 2;
    }
}
void PlayWindow::on_keyEButton_released()
{
    emit buttonReleasedSignal('E');
    if (!eShift || !shift)
    {
        eShift = false;
        ui->keyEButton->setStyleSheet(passiveButtonColor);
        eStatus[currentLay] = 0;
    }
    else
    {
        ui->keyEButton->setStyleSheet(startButtonColor);
        eStatus[currentLay] = 2;
    }
}
void PlayWindow::on_keyRButton_released()
{
    emit buttonReleasedSignal('R');
    if (!rShift || !shift)
    {
        rShift = false;
        ui->keyRButton->setStyleSheet(passiveButtonColor);
        rStatus[currentLay] = 0;
    }
    else
    {
        ui->keyRButton->setStyleSheet(startButtonColor);
        rStatus[currentLay] = 2;
    }
}
void PlayWindow::on_keyTButton_released()
{
    emit buttonReleasedSignal('T');
    if (!tShift || !shift)
    {
        tShift = false;
        ui->keyTButton->setStyleSheet(passiveButtonColor);
        tStatus[currentLay] = 0;
    }
    else
    {
        ui->keyTButton->setStyleSheet(startButtonColor);
        tStatus[currentLay] = 2;
    }
}
void PlayWindow::on_keyYButton_released()
{
    emit buttonReleasedSignal('Y');
    if (!yShift || !shift)
    {
        yShift = false;
        ui->keyYButton->setStyleSheet(passiveButtonColor);
        yStatus[currentLay] = 0;
    }
    else
    {
        ui->keyYButton->setStyleSheet(startButtonColor);
        yStatus[currentLay] = 2;
    }
}
void PlayWindow::on_keyUButton_released()
{
    emit buttonReleasedSignal('U');
    if (!uShift || !shift)
    {
        uShift = false;
        ui->keyUButton->setStyleSheet(passiveButtonColor);
        uStatus[currentLay] = 0;
    }
    else
    {
        ui->keyUButton->setStyleSheet(startButtonColor);
        uStatus[currentLay] = 2;
    }
}
void PlayWindow::on_keyIButton_released()
{
    emit buttonReleasedSignal('I');
    if (!iShift || !shift)
    {
        iShift = false;
        ui->keyIButton->setStyleSheet(passiveButtonColor);
        iStatus[currentLay] = 0;
    }
    else
    {
        ui->keyIButton->setStyleSheet(startButtonColor);
        iStatus[currentLay] = 2;
    }
}
void PlayWindow::on_keyOButton_released()
{
    emit buttonReleasedSignal('O');
    if (!oShift || !shift)
    {
        oShift = false;
        ui->keyOButton->setStyleSheet(passiveButtonColor);
        oStatus[currentLay] = 0;
    }
    else
    {
        ui->keyOButton->setStyleSheet(startButtonColor);
        oStatus[currentLay] = 2;
    }
}
void PlayWindow::on_keyPButton_released()
{
    emit buttonReleasedSignal('P');
    if (!pShift || !shift)
    {
        pShift = false;
        ui->keyPButton->setStyleSheet(passiveButtonColor);
        pStatus[currentLay] = 0;
    }
    else
    {
        ui->keyPButton->setStyleSheet(startButtonColor);
        pStatus[currentLay] = 2;
    }
}
void PlayWindow::on_keyAButton_released()
{
    emit buttonReleasedSignal('A');
    if (!aShift || !shift)
    {
        aShift = false;
        ui->keyAButton->setStyleSheet(passiveButtonColor);
        aStatus[currentLay] = 0;
    }
    else
    {
        ui->keyAButton->setStyleSheet(startButtonColor);
        aStatus[currentLay] = 2;
    }
}
void PlayWindow::on_keySButton_released()
{
    emit buttonReleasedSignal('S');
    if (!sShift || !shift)
    {
        sShift = false;
        ui->keySButton->setStyleSheet(passiveButtonColor);
        sStatus[currentLay] = 0;
    }
    else
    {
        ui->keySButton->setStyleSheet(startButtonColor);
        sStatus[currentLay] = 2;
    }
}
void PlayWindow::on_keyDButton_released()
{
    emit buttonReleasedSignal('D');
    if (!dShift || !shift)
    {
        dShift = false;
        ui->keyDButton->setStyleSheet(passiveButtonColor);
        dStatus[currentLay] = 0;
    }
    else
    {
        ui->keyDButton->setStyleSheet(startButtonColor);
        dStatus[currentLay] = 2;
    }
}
void PlayWindow::on_keyFButton_released()
{
    emit buttonReleasedSignal('F');
    if (!fShift || !shift)
    {
        fShift = false;
        ui->keyFButton->setStyleSheet(passiveButtonColor);
        fStatus[currentLay] = 0;
    }
    else
    {
        ui->keyFButton->setStyleSheet(startButtonColor);
        fStatus[currentLay] = 2;
    }
}
void PlayWindow::on_keyGButton_released()
{
    emit buttonReleasedSignal('G');
    if (!gShift || !shift)
    {
        gShift = false;
        ui->keyGButton->setStyleSheet(passiveButtonColor);
        gStatus[currentLay] = 0;
    }
    else
    {
        ui->keyGButton->setStyleSheet(startButtonColor);
        gStatus[currentLay] = 2;
    }
}
void PlayWindow::on_keyHButton_released()
{
    emit buttonReleasedSignal('H');
    if (!hShift || !shift)
    {
        hShift = false;
        ui->keyHButton->setStyleSheet(passiveButtonColor);
        hStatus[currentLay] = 0;
    }
    else
    {
        ui->keyHButton->setStyleSheet(startButtonColor);
        hStatus[currentLay] = 2;
    }
}
void PlayWindow::on_keyJButton_released()
{
    emit buttonReleasedSignal('J');
    if (!jShift || !shift)
    {
        jShift = false;
        ui->keyJButton->setStyleSheet(passiveButtonColor);
        jStatus[currentLay] = 0;
    }
    else
    {
        ui->keyJButton->setStyleSheet(startButtonColor);
        jStatus[currentLay] = 2;
    }
}
void PlayWindow::on_keyKButton_released()
{
    emit buttonReleasedSignal('K');
    if (!kShift || !shift)
    {
        kShift = false;
        ui->keyKButton->setStyleSheet(passiveButtonColor);
        kStatus[currentLay] = 0;
    }
    else
    {
        ui->keyKButton->setStyleSheet(startButtonColor);
        kStatus[currentLay] = 2;
    }
}
void PlayWindow::on_keyLButton_released()
{
    emit buttonReleasedSignal('L');
    if (!lShift || !shift)
    {
        lShift = false;
        ui->keyLButton->setStyleSheet(passiveButtonColor);
        lStatus[currentLay] = 0;
    }
    else
    {
        ui->keyLButton->setStyleSheet(startButtonColor);
        lStatus[currentLay] = 2;
    }
}
void PlayWindow::on_keyZButton_released()
{
    emit buttonReleasedSignal('Z');
    if (!zShift || !shift)
    {
        zShift = false;
        ui->keyZButton->setStyleSheet(passiveButtonColor);
        zStatus[currentLay] = 0;
    }
    else
    {
        ui->keyZButton->setStyleSheet(startButtonColor);
        zStatus[currentLay] = 2;
    }
}
void PlayWindow::on_keyXButton_released()
{
    emit buttonReleasedSignal('X');
    if (!xShift || !shift)
    {
        xShift = false;
        ui->keyXButton->setStyleSheet(passiveButtonColor);
        xStatus[currentLay] = 0;
    }
    else
    {
        ui->keyXButton->setStyleSheet(startButtonColor);
        xStatus[currentLay] = 2;
    }
}
void PlayWindow::on_keyCButton_released()
{
    emit buttonReleasedSignal('C');
    if (!cShift || !shift)
    {
        cShift = false;
        ui->keyCButton->setStyleSheet(passiveButtonColor);
        cStatus[currentLay] = 0;
    }
    else
    {
        ui->keyCButton->setStyleSheet(startButtonColor);
        cStatus[currentLay] = 2;
    }
}
void PlayWindow::on_keyVButton_released()
{
    emit buttonReleasedSignal('V');
    if (!vShift || !shift)
    {
        vShift = false;
        ui->keyVButton->setStyleSheet(passiveButtonColor);
        vStatus[currentLay] = 0;
    }
    else
    {
        ui->keyVButton->setStyleSheet(startButtonColor);
        vStatus[currentLay] = 2;
    }
}
void PlayWindow::on_keyBButton_released()
{
    emit buttonReleasedSignal('B');
    if (!bShift || !shift)
    {
        bShift = false;
        ui->keyBButton->setStyleSheet(passiveButtonColor);
        bStatus[currentLay] = 0;
    }
    else
    {
        ui->keyBButton->setStyleSheet(startButtonColor);
        bStatus[currentLay] = 2;
    }
}
void PlayWindow::on_keyNButton_released()
{
    emit buttonReleasedSignal('N');
    if (!nShift || !shift)
    {
        nShift = false;
        ui->keyNButton->setStyleSheet(passiveButtonColor);
        nStatus[currentLay] = 0;
    }
    else
    {
        ui->keyNButton->setStyleSheet(startButtonColor);
        nStatus[currentLay] = 2;
    }
}
void PlayWindow::on_keyMButton_released()
{
    emit buttonReleasedSignal('M');
    if (!mShift || !shift)
    {
        mShift = false;
        ui->keyMButton->setStyleSheet(passiveButtonColor);
        mStatus[currentLay] = 0;
    }
    else
    {
        ui->keyMButton->setStyleSheet(startButtonColor);
        mStatus[currentLay] = 2;
    }
}
void PlayWindow::on_keyShiftButton_released()
{
    emit buttonReleasedSignal('.');
    shift = false;
    ui->keyShiftButton->setStyleSheet(passiveButtonColor);
}



// -------------PAGES---------------------------------------



void PlayWindow::setCurrentLay(int lay)
{
    emit buttonPressedSignal((char)lay + '0');
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




    switch(qStatus[lay])
    {
    case 0: {ui->keyQButton->setStyleSheet(passiveButtonColor); break;}
    case 1: {ui->keyQButton->setStyleSheet(activeButtonColor); break;}
    case 2: {ui->keyQButton->setStyleSheet(startButtonColor); break;}
    }
    switch(wStatus[lay])
    {
    case 0: {ui->keyWButton->setStyleSheet(passiveButtonColor); break;}
    case 1: {ui->keyWButton->setStyleSheet(activeButtonColor); break;}
    case 2: {ui->keyWButton->setStyleSheet(startButtonColor); break;}
    }
    switch(eStatus[lay])
    {
    case 0: {ui->keyEButton->setStyleSheet(passiveButtonColor); break;}
    case 1: {ui->keyEButton->setStyleSheet(activeButtonColor); break;}
    case 2: {ui->keyEButton->setStyleSheet(startButtonColor); break;}
    }
    switch(rStatus[lay])
    {
    case 0: {ui->keyRButton->setStyleSheet(passiveButtonColor); break;}
    case 1: {ui->keyRButton->setStyleSheet(activeButtonColor); break;}
    case 2: {ui->keyRButton->setStyleSheet(startButtonColor); break;}
    }
    switch(tStatus[lay])
    {
    case 0: {ui->keyTButton->setStyleSheet(passiveButtonColor); break;}
    case 1: {ui->keyTButton->setStyleSheet(activeButtonColor); break;}
    case 2: {ui->keyTButton->setStyleSheet(startButtonColor); break;}
    }
    switch(yStatus[lay])
    {
    case 0: {ui->keyYButton->setStyleSheet(passiveButtonColor); break;}
    case 1: {ui->keyYButton->setStyleSheet(activeButtonColor); break;}
    case 2: {ui->keyYButton->setStyleSheet(startButtonColor); break;}
    }
    switch(uStatus[lay])
    {
    case 0: {ui->keyUButton->setStyleSheet(passiveButtonColor); break;}
    case 1: {ui->keyUButton->setStyleSheet(activeButtonColor); break;}
    case 2: {ui->keyUButton->setStyleSheet(startButtonColor); break;}
    }
    switch(iStatus[lay])
    {
    case 0: {ui->keyIButton->setStyleSheet(passiveButtonColor); break;}
    case 1: {ui->keyIButton->setStyleSheet(activeButtonColor); break;}
    case 2: {ui->keyIButton->setStyleSheet(startButtonColor); break;}
    }
    switch(oStatus[lay])
    {
    case 0: {ui->keyOButton->setStyleSheet(passiveButtonColor); break;}
    case 1: {ui->keyOButton->setStyleSheet(activeButtonColor); break;}
    case 2: {ui->keyOButton->setStyleSheet(startButtonColor); break;}
    }
    switch(pStatus[lay])
    {
    case 0: {ui->keyPButton->setStyleSheet(passiveButtonColor); break;}
    case 1: {ui->keyPButton->setStyleSheet(activeButtonColor); break;}
    case 2: {ui->keyPButton->setStyleSheet(startButtonColor); break;}
    }
    switch(aStatus[lay])
    {
    case 0: {ui->keyAButton->setStyleSheet(passiveButtonColor); break;}
    case 1: {ui->keyAButton->setStyleSheet(activeButtonColor); break;}
    case 2: {ui->keyAButton->setStyleSheet(startButtonColor); break;}
    }
    switch(sStatus[lay])
    {
    case 0: {ui->keySButton->setStyleSheet(passiveButtonColor); break;}
    case 1: {ui->keySButton->setStyleSheet(activeButtonColor); break;}
    case 2: {ui->keySButton->setStyleSheet(startButtonColor); break;}
    }
    switch(dStatus[lay])
    {
    case 0: {ui->keyDButton->setStyleSheet(passiveButtonColor); break;}
    case 1: {ui->keyDButton->setStyleSheet(activeButtonColor); break;}
    case 2: {ui->keyDButton->setStyleSheet(startButtonColor); break;}
    }
    switch(fStatus[lay])
    {
    case 0: {ui->keyFButton->setStyleSheet(passiveButtonColor); break;}
    case 1: {ui->keyFButton->setStyleSheet(activeButtonColor); break;}
    case 2: {ui->keyFButton->setStyleSheet(startButtonColor); break;}
    }
    switch(gStatus[lay])
    {
    case 0: {ui->keyGButton->setStyleSheet(passiveButtonColor); break;}
    case 1: {ui->keyGButton->setStyleSheet(activeButtonColor); break;}
    case 2: {ui->keyGButton->setStyleSheet(startButtonColor); break;}
    }
    switch(hStatus[lay])
    {
    case 0: {ui->keyHButton->setStyleSheet(passiveButtonColor); break;}
    case 1: {ui->keyHButton->setStyleSheet(activeButtonColor); break;}
    case 2: {ui->keyHButton->setStyleSheet(startButtonColor); break;}
    }
    switch(jStatus[lay])
    {
    case 0: {ui->keyJButton->setStyleSheet(passiveButtonColor); break;}
    case 1: {ui->keyJButton->setStyleSheet(activeButtonColor); break;}
    case 2: {ui->keyJButton->setStyleSheet(startButtonColor); break;}
    }
    switch(kStatus[lay])
    {
    case 0: {ui->keyKButton->setStyleSheet(passiveButtonColor); break;}
    case 1: {ui->keyKButton->setStyleSheet(activeButtonColor); break;}
    case 2: {ui->keyKButton->setStyleSheet(startButtonColor); break;}
    }
    switch(lStatus[lay])
    {
    case 0: {ui->keyLButton->setStyleSheet(passiveButtonColor); break;}
    case 1: {ui->keyLButton->setStyleSheet(activeButtonColor); break;}
    case 2: {ui->keyLButton->setStyleSheet(startButtonColor); break;}
    }
    switch(zStatus[lay])
    {
    case 0: {ui->keyZButton->setStyleSheet(passiveButtonColor); break;}
    case 1: {ui->keyZButton->setStyleSheet(activeButtonColor); break;}
    case 2: {ui->keyZButton->setStyleSheet(startButtonColor); break;}
    }
    switch(xStatus[lay])
    {
    case 0: {ui->keyXButton->setStyleSheet(passiveButtonColor); break;}
    case 1: {ui->keyXButton->setStyleSheet(activeButtonColor); break;}
    case 2: {ui->keyXButton->setStyleSheet(startButtonColor); break;}
    }
    switch(cStatus[lay])
    {
    case 0: {ui->keyCButton->setStyleSheet(passiveButtonColor); break;}
    case 1: {ui->keyCButton->setStyleSheet(activeButtonColor); break;}
    case 2: {ui->keyCButton->setStyleSheet(startButtonColor); break;}
    }
    switch(vStatus[lay])
    {
    case 0: {ui->keyVButton->setStyleSheet(passiveButtonColor); break;}
    case 1: {ui->keyVButton->setStyleSheet(activeButtonColor); break;}
    case 2: {ui->keyVButton->setStyleSheet(startButtonColor); break;}
    }
    switch(bStatus[lay])
    {
    case 0: {ui->keyBButton->setStyleSheet(passiveButtonColor); break;}
    case 1: {ui->keyBButton->setStyleSheet(activeButtonColor); break;}
    case 2: {ui->keyBButton->setStyleSheet(startButtonColor); break;}
    }
    switch(nStatus[lay])
    {
    case 0: {ui->keyNButton->setStyleSheet(passiveButtonColor); break;}
    case 1: {ui->keyNButton->setStyleSheet(activeButtonColor); break;}
    case 2: {ui->keyNButton->setStyleSheet(startButtonColor); break;}
    }
    switch(mStatus[lay])
    {
    case 0: {ui->keyMButton->setStyleSheet(passiveButtonColor); break;}
    case 1: {ui->keyMButton->setStyleSheet(activeButtonColor); break;}
    case 2: {ui->keyMButton->setStyleSheet(startButtonColor); break;}
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
