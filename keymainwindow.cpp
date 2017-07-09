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

    prelistening = false;
}

KeyMainWindow::~KeyMainWindow()
{
    stopAllPlay();
    on_deleteAllButton_clicked();
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
    int index = ui->keyListWidget->currentIndex().row();
    if (index >= 0)
    {
        KeyElement* elem = this->keys.at(index);
        keys.removeAt(index);
        elem->getItem()->setBackgroundColor(0,QColor(0,0,0,0));
        ui->keyListWidget->takeItem(index);
        if (index > 0)
        {
            ui->keyListWidget->setCurrentRow(index - 1);
        }
        else
        {
            ui->keyListWidget->setCurrentRow(index);
        }
        delete elem;
    }
}

void KeyMainWindow::on_deleteAllButton_clicked()
{
  for (int i = 0; i < keys.length(); i++)
  {
      keys.at(i)->getItem()->setBackgroundColor(0,QColor(0,0,0,0));
      delete keys.at(i);
  }
  keys.clear();
  ui->keyListWidget->clear();
}

void KeyMainWindow::on_playButton_clicked()
{
    PlayWindow* window = new PlayWindow(this);
    connect (window,SIGNAL(buttonPressedSignal(QChar)),this,SLOT(startPlay(QChar)));
    connect (window,SIGNAL(buttonReleasedSignal(QChar)),this,SLOT(stopPlay(QChar)));
    connect(window,SIGNAL(rejected()),this,SLOT(stopAllPlay()));

    shift = false;
    window->show();
}

void KeyMainWindow::on_fileTreeWidget_doubleClicked(const QModelIndex &index)
{
    on_editButton_clicked();
}

void KeyMainWindow::on_keyListWidget_doubleClicked(const QModelIndex &index)
{
    if (!prelistening)
    {
        keys.at(index.row())->play();
    }
    else
    {
        stopAllPlay();
    }
    prelistening = !prelistening;
}

void KeyMainWindow::startPlay(QChar key)
{
    if (key == '.')
    {
        shift = true;
    }
    else
    {
        QList<QListWidgetItem*> list = ui->keyListWidget->findItems(key,Qt::MatchStartsWith);
        //qDebug() << list.at(0)->text();
        if (!list.isEmpty())
        {
            if (list.at(0)->text()[0] == key)
            {
                //qDebug() << key;
                for (int i = 0; i < keys.length(); i++)
                {
                    if (keys.value(i)->getKey() == key)
                    {
                        //qDebug() << key;
                        KeyElement *elem = keys.value(i);
                        if (shift && elem->getFormat() == 1)
                        {
                            elem->setFormat(0);
                            elem->stop();
                            return;
                        }
                        else
                        {
                            if (shift && elem->getFormat() == 0)
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
        shift = false;
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
                        if (shift && elem->getFormat() == 1)
                        {
                            return;
                        }
                        else
                        {
                            if (shift && elem->getFormat() == 0)
                            {
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
    //qDebug() << keys.length();
    for (int i = 0; i < keys.length(); i++)
    {
        keys.value(i)->setFormat(0);
        keys.value(i)->stop();
    }
    shift = false;
}

void KeyMainWindow::editOk(KeyElement *element)
{
    QString buffer = ": ";
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
