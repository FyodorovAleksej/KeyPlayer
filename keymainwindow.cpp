#include "keymainwindow.h"
#include "ui_keymainwindow.h"

KeyMainWindow::KeyMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::KeyMainWindow)
{
    ui->setupUi(this);
}

KeyMainWindow::~KeyMainWindow()
{
    delete ui;
}

void KeyMainWindow::on_editButton_clicked()
{

}

void KeyMainWindow::on_addButton_clicked()
{

}

void KeyMainWindow::on_deleteButton_clicked()
{

}

void KeyMainWindow::on_deleteAllButton_clicked()
{

}

void KeyMainWindow::on_playButton_clicked()
{
    PlayWindow* window = new PlayWindow(this);
    connect (window,SIGNAL(buttonPressedSignal(QChar)),this,SLOT(startPlay(QChar)));
    connect (window,SIGNAL(buttonReleasedSignal(QChar)),this,SLOT(stopPlay(QChar)));
    connect(window,SIGNAL(rejected()),this,SLOT(stopAllPlay(QChar)));

    window->show();
}

void KeyMainWindow::on_fileTreeWidget_doubleClicked(const QModelIndex &index)
{

}

void KeyMainWindow::on_keyListWidget_doubleClicked(const QModelIndex &index)
{

}

void KeyMainWindow::startPlay(QChar key)
{

}

void KeyMainWindow::stopPlay(QChar key)
{

}

void KeyMainWindow::stopAllPlay()
{

}
