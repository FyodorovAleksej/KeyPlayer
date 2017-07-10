#include "keymainwindow.h"
#include "ui_keymainwindow.h"


QTreeWidgetItem* KeyMainWindow::getDir(QString path, QTreeWidgetItem* parent)
{
    int check = 1;
    QTreeWidgetItem* item = NULL;
    QDir folder(path);
    QFileInfo pathInfo(path);
    if (pathInfo.isDir())
    {
        for (QFileInfo temp : folder.entryInfoList())
        {
            if (check > 2)
            {
                item = new QTreeWidgetItem(parent);
                item->setText(0, temp.absoluteFilePath());
                item->setText(1, temp.fileName());
                ui->fileTreeWidget->addTopLevelItem(item);
                if (temp.isDir())
                    getDir(temp.absoluteFilePath(), item);
            }
            check++;
        }
    }
    else
    {
        item = new QTreeWidgetItem(parent);
        item->setText(0,pathInfo.absoluteFilePath());
        item->setText(1, pathInfo.fileName());
        ui->fileTreeWidget->addTopLevelItem(item);
    }
    return item;
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
    qDebug() << "settng buffer";
    buffer.insert(0, element->getKey());
    qDebug() << "after key";
    buffer += element->getName();
    qDebug() << "adding key Item";
    ui->keyListWidget->addItem(buffer);
    keys.append(element);
    qDebug() << "append element";
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

void KeyMainWindow::on_actionSaveFile_triggered()
{
    FILE *file = new FILE;
    QString name = QFileDialog::getSaveFileName(this, tr("Save Key List"), QDir::currentPath(), tr("Key List files (*.kpl);; All files(*.*)"));
    file = fopen(name.toLatin1().data(), "w+b");
    if (!file)
    {
        return;
    }
    int len = keys.length();
    fwrite(&len,sizeof(int),1,file);
    for (int i = 0; i < keys.length(); i++)
    {
        QString qstr = keys.at(i)->getKey();
        qstr += "\t";
        qstr += keys.at(i)->getPath();
        qstr += "\n";
        const char *str = qstr.toLatin1().data();
        const int volume = keys.at(i)->getVolume();
        const bool repeat = keys.at(i)->isRepeated();
        fwrite(&repeat, sizeof(bool), 1, file);
        fwrite(&volume, sizeof(int), 1, file);
        fwrite(str, sizeof(char), qstr.length(), file);
    }
    fclose(file);
}

void KeyMainWindow::on_actionOpenFile_triggered()
{

    FILE *file = new FILE;
    QString name = QFileDialog::getOpenFileName(this, tr("Open Key List"), QDir::currentPath(), tr("Key List files (*.kpl);; All files(*.*)"));
    file = fopen(name.toLatin1().data(), "r+b");
    if (!file)
    {
        return;
    }
    qDebug() << "start reading";
    on_deleteAllButton_clicked();
    int len = 0;
    fread(&len,sizeof(int),1,file);
    qDebug() << "len - " << len;
    for (int i = 0; i < len; i++)
    {
        bool repeat = false;
        int volume = 0;
        char key;
        char temp = ' ';
        fread(&repeat, sizeof(bool), 1, file);
        qDebug() << "repeat - " << repeat;
        fread(&volume, sizeof(int), 1, file);
        qDebug() << "volume - " << volume;
        fread(&key, sizeof(char), 1, file);
        qDebug() << "key - " << key;
        fseek(file, 1, 1);
        QString qstr = "";
        while (true)
        {
            fread(&temp, sizeof(char), 1, file);
            if (temp != '\n')
            {
                qstr.append(temp);
            }
            else
            {
                break;
            }
        }
        qDebug() << "path - " << qstr;
        KeyElement* elem = new KeyElement(qstr);
        elem->setVolume(volume);
        elem->setKey(key);
        elem->setRepeated(repeat);

        QList<QTreeWidgetItem*> list = ui->fileTreeWidget->findItems(qstr, Qt::MatchRecursive | Qt::MatchFixedString, 0);
        qDebug() << "tree len - " << list.length();
        if (list.isEmpty())
        {
            elem->setItem(getDir(qstr, NULL));
            qDebug() << "adding Item";
        }
        else
        {
            elem->setItem(list.at(0));
        }
        editOk(elem);
    }
    fclose(file);
}

void KeyMainWindow::on_actionSaveFileMenu_triggered()
{
    on_actionSaveFile_triggered();
}

void KeyMainWindow::on_actionOpenFileMenu_triggered()
{
    on_actionOpenFile_triggered();
}
