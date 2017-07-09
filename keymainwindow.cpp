#include "keymainwindow.h"
#include "ui_keymainwindow.h"


void KeyMainWindow::getDir(QString path, QTreeWidgetItem* parent)
{
    int check = 1;
    QDir folder(path);
    for (QFileInfo temp : folder.entryInfoList())
    {
        if (check > 2)
        {
            QTreeWidgetItem* item = new QTreeWidgetItem(parent);
            item->setText(0, temp.absoluteFilePath());
            item->setText(1, temp.fileName());
            ui->fileTreeWidget->addTopLevelItem(item);
            if (temp.isDir())
                getDir(temp.absoluteFilePath(), item);
        }
        check++;
    }
}


KeyMainWindow::KeyMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::KeyMainWindow)
{
    ui->setupUi(this);
    ui->fileTreeWidget->setColumnCount(2);
    QStringList headsList(QString("Path"));
    headsList.append("Name");
    ui->fileTreeWidget->setHeaderLabels(headsList);
    ui->fileTreeWidget->setSortingEnabled(true);
}

KeyMainWindow::~KeyMainWindow()
{
    delete ui;
}

void KeyMainWindow::on_editButton_clicked()
{
    if (ui->fileTreeWidget->currentItem() != NULL)
    {
        KeyEditDialog* dialog = new KeyEditDialog();
        dialog->setPath(ui->fileTreeWidget->currentItem());
        connect(dialog,SIGNAL(finish(KeyElement*)),this, SLOT(editOk(KeyElement*)));
        dialog->show();
    }
}

void KeyMainWindow::on_addButton_clicked()
{
    QString root = QFileDialog::getExistingDirectoryUrl().toLocalFile();
    QTreeWidgetItem* item = new QTreeWidgetItem();
    item->setText(0, root);
    ui->fileTreeWidget->addTopLevelItem(item);
    getDir(root, item);
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
    connect(window,SIGNAL(rejected()),this,SLOT(stopAllPlay()));

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
    if (key == '.')
    {
        shift = shift*(-1);
    }
    else
    {
        QList<QListWidgetItem*> list = ui->keyListWidget->findItems(key,Qt::MatchStartsWith);
        qDebug() << list.at(0)->text();
        if (!list.isEmpty())
        {
            if (list.at(0)->text()[0] == key)
            {
                qDebug() << key;
                for (int i = 0; i < keys.length(); i++)
                {
                    if (keys.value(i)->getKey() == key)
                    {
                        qDebug() << key;
                        KeyElement *elem = keys.value(i);
                        if (shift == 1 && elem->getFormat() == 1)
                        {
                            elem->setFormat(0);
                            elem->stop();
                            return;
                        }
                        else
                        {
                            if (shift == 1 && elem->getFormat() == 0)
                            {
                                elem->setFormat(1);
                                elem->play();
                                return;
                            }
                        }
                        elem->play();
                    }
                }
            }
        }
    }
}

void KeyMainWindow::stopPlay(QChar key)
{
    if (key == '.')
    {
        shift = shift*(-1);
    }
    else
    {
        QList<QListWidgetItem*> list = ui->keyListWidget->findItems(key,Qt::MatchStartsWith);
        if (!list.isEmpty())
        {
            if (list.at(0)->text()[0] == key)
            {
                for (int i = 0; i < keys.length(); i++)
                {
                    if (keys.value(i)->getKey() == key)
                    {
                        KeyElement *elem = keys.value(i);
                        if (shift == 1 && elem->getFormat() == 1)
                        {
                            elem->setFormat(0);
                            elem->stop();
                            return;
                        }
                        else
                        {
                            if (shift == 1 && elem->getFormat() == 0)
                            {
                                elem->setFormat(0);
                                elem->stop();
                                return;
                            }
                        }
                        elem->stop();
                    }
                }
            }
        }
    }
}

void KeyMainWindow::stopAllPlay()
{
    for (int i = 0; i < keys.length(); i++)
    {
        keys.value(i)->setFormat(0);
        keys.value(i)->stop();
    }
}

void KeyMainWindow::editOk(KeyElement *element)
{
    QString buffer = " ";
    buffer.insert(0, element->getKey());
    buffer += element->getName();
    ui->keyListWidget->addItem(buffer);
    keys.append(element);
    if (element->isValid())
    {
        if (element->isRepeated())
        {
            element->getItem()->setBackgroundColor(0,QColor(80,80,250,235));
        }
        else
        {
            element->getItem()->setBackgroundColor(0,QColor(80,250,80,235));
        }
    }
    else
    {
        element->getItem()->setBackgroundColor(0,QColor(250,80,80,235));
    }
}
