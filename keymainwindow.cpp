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
        logging("adding folder...");
        for (QFileInfo temp : folder.entryInfoList())
        {
            if (check > 2)
            {
                if (temp.fileName().endsWith(".mp3") || temp.fileName().endsWith(".wav"))
                {
                    item = new QTreeWidgetItem(parent);
                    item->setText(0, temp.absoluteFilePath());
                    item->setText(1, temp.fileName());
                    ui->fileTreeWidget->addTopLevelItem(item);
                    new TryPlayer(item);
                }
                if (temp.isDir())
                {
                    QTreeWidgetItem* parentFolder;
                    parentFolder = new QTreeWidgetItem(parent);
                    parentFolder->setText(0, temp.absoluteFilePath());
                    getDir(temp.absoluteFilePath(), parentFolder);
                }
            }
            check++;
        }
        logging("folder was added");
    }
    else
    {
        logging("adding file...");
        item = new QTreeWidgetItem(parent);
        item->setText(0,pathInfo.absoluteFilePath());
        item->setText(1, pathInfo.fileName());
        ui->fileTreeWidget->addTopLevelItem(item);
        logging("file was added");
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
        if (ui->fileTreeWidget->currentItem()->text(1).endsWith(".mp3") || ui->fileTreeWidget->currentItem()->text(1).endsWith(".wav"))
        {
            logging("start editing...");
            KeyEditDialog* dialog = new KeyEditDialog();
            dialog->setPath(ui->fileTreeWidget->currentItem());
            connect(dialog,SIGNAL(finish(KeyElement*)),this, SLOT(editOk(KeyElement*)));
            dialog->show();
            logging("finish editing");
        }
        else
        {
            logging("it's folder");
        }
    }
    else
    {
        logging("nothing to edit");
    }
}

void KeyMainWindow::on_addButton_clicked()
{
    logging("adding folder with resources...");
    QString root = QFileDialog::getExistingDirectoryUrl().toLocalFile();
    if (root.isEmpty())
    {
        logging("cancelling adding dirictory");
        return;
    }
    QTreeWidgetItem* item = new QTreeWidgetItem();
    item->setText(0, root);
    ui->fileTreeWidget->addTopLevelItem(item);
    getDir(root, item);
    logging("dirictory was added");
}


void KeyMainWindow::on_deleteButton_clicked()
{
    int index = ui->keyListWidget->currentIndex().row();
    if (index >= 0)
    {
        logging("deleting element...");
        KeyElement* elem = this->keys.at(index);
        keys.removeAt(index);
        if (elem->getItem()->backgroundColor(1) != QColor(250,80,80,235))
        {
            elem->getItem()->setBackgroundColor(1,QColor(0,0,0,0));
        }
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
        logging("key element was deleted");
    }
    else
    {
        logging("nothing to delete");
    }
}

void KeyMainWindow::on_deleteAllButton_clicked()
{
    logging("deleting all key elements...");
    for (int i = 0; i < keys.length(); i++)
    {
        if (keys.at(i)->getItem()->backgroundColor(1) != QColor(250,80,80,235))
        {
            keys.at(i)->getItem()->setBackgroundColor(1,QColor(0,0,0,0));
        }
        delete keys.at(i);
    }
    keys.clear();
    ui->keyListWidget->clear();
    logging("all key elements was deleted");
}

void KeyMainWindow::on_playButton_clicked()
{
    stopAllPlay();
    logging("start playing... Enjoy =)");
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
        logging("listening - " + keys.at(index.row())->getName());
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
                            elem->setFormat(0);
                            if (elem->isRepeated())
                            {
                                disconnect(elem->getPlayer(), SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)), elem->getPlayer(), SLOT(play()));
                            }
                            elem->stop();
                            return;
                        }
                        if (shift && elem->getFormat() == 0)
                        {
                            elem->setFormat(1);
                            elem->play();
                            if (elem->isRepeated())
                            {
                                connect(elem->getPlayer(), SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)), elem->getPlayer(), SLOT(play()));
                            }
                            return;
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
                        if (!shift)
                        {
                            if (elem->isRepeated())
                            {
                                disconnect(elem->getPlayer(), SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)), elem->getPlayer(), SLOT(play()));
                            }
                            elem->setFormat(0);
                            elem->stop();
                        }
                    }
                }
            }
        }
    }
}

void KeyMainWindow::stopAllPlay()
{
    logging("stopping all...");
    for (int i = 0; i < keys.length(); i++)
    {
        keys.value(i)->setFormat(0);
        if (keys.value(i)->isRepeated())
        {
            disconnect(keys.value(i)->getPlayer(), SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)), keys.value(i)->getPlayer(), SLOT(play()));
        }
        keys.value(i)->stop();
    }
    shift = false;
    logging("all plays was stopped");
}

void KeyMainWindow::editOk(KeyElement *element)
{
    addInList(element);
    if (element->isValid())
    {
        if (element->isRepeated())
        {
            element->getItem()->setBackgroundColor(1,QColor(80,80,250,235));
        }
        else
        {
            element->getItem()->setBackgroundColor(1,QColor(80,250,80,235));
        }
    }
    else
    {
        element->getItem()->setBackgroundColor(1,QColor(250,80,80,235));
    }
    logging("element was added");
}

void KeyMainWindow::on_actionSaveFile_triggered()
{
    FILE *file = new FILE;
    logging("choosing file...");
    QString name = QFileDialog::getSaveFileName(this, tr("Save Key List"), QDir::currentPath(), tr("Key List files (*.kpl);; All files(*.*)"));
    if (name.isEmpty())
    {
        logging("canceling saving file");
        return;
    }
    file = fopen(name.toLatin1().data(), "w+b");
    logging("rewriting file...");
    if (!file)
    {
        logging("can't create file...");
        return;
    }
    logging("file was created. Writting...");
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
    logging("file - " + name +" was saved");
}

void KeyMainWindow::on_actionOpenFile_triggered()
{

    FILE *file = new FILE;
    logging("choosing file...");

    QString name = QFileDialog::getOpenFileName(this, tr("Open Key List"), QDir::currentPath(), tr("Key List files (*.kpl);; All files(*.*)"));
    if (name.isEmpty())
    {
        logging("canceling opening file");
        return;
    }
    file = fopen(name.toLatin1().data(), "r+b");
    if (!file)
    {
        logging("file not founded");
        return;
    }

    logging("opening file...");

    on_deleteAllButton_clicked();
    int len = 0;
    fread(&len,sizeof(int),1,file);

    for (int i = 0; i < len; i++)
    {
        bool repeat = false;
        int volume = 0;
        char key;
        char temp = ' ';
        fread(&repeat, sizeof(bool), 1, file);
        fread(&volume, sizeof(int), 1, file);
        fread(&key, sizeof(char), 1, file);
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
        KeyElement* elem = new KeyElement(qstr);
        elem->setVolume(volume);
        elem->setKey(key);
        elem->setRepeated(repeat);

        QList<QTreeWidgetItem*> list = ui->fileTreeWidget->findItems(qstr, Qt::MatchRecursive | Qt::MatchFixedString, 0);
        if (list.isEmpty())
        {
            elem->setItem(getDir(qstr, NULL));
            logging("adding Item - " + elem->getItem()->text(0));
        }
        else
        {
            elem->setItem(list.at(0));
        }
        editOk(elem);
        logging("added key item from file");
    }
    fclose(file);
    logging("file - " + name + " was readed");
}

void KeyMainWindow::on_actionSaveFileMenu_triggered()
{
    on_actionSaveFile_triggered();
}

void KeyMainWindow::on_actionOpenFileMenu_triggered()
{
    on_actionOpenFile_triggered();
}


void KeyMainWindow::logging(QString message)
{
    this->ui->infoLabel->setText("Info: " + message);
    qDebug() << message;
}

void KeyMainWindow::addInList(KeyElement *element)
{
    QString buffer = ": ";
    logging("adding key element...");
    buffer.insert(0, element->getKey());
    buffer += element->getName();
    ui->keyListWidget->addItem(buffer);
    keys.append(element);
}

void KeyMainWindow::on_autoButton_clicked()
{
    logging("autoFilling...");
    on_deleteAllButton_clicked();
    sum = 0;
    for (int i = 0; i < ui->fileTreeWidget->topLevelItemCount(); i++)
    {
        if (!autoFill(ui->fileTreeWidget->topLevelItem(i)))
        {
            return;
        }
    }
    logging("autoFilling finished sucessfully");
}

bool KeyMainWindow::autoFill(QTreeWidgetItem* current)
{
    if (current->childCount() > 0)
    {
        for (int j = 0; j < current->childCount(); j++)
        {
            if (!(this->autoFill(current->child(j))))
            {
                return false;
            }
        }
    }
    else
    {
        if (current->text(1).endsWith(".mp3") || current->text(1).endsWith(".wav"))
        {
            if (current->backgroundColor(1) != QColor(250,80,80,235))
            {
                if (sum + 'A' > 'Z')
                {
                    return false;
                }
                KeyElement* element = new KeyElement(current->text(0));
                element->setKey('A' + sum);
                sum++;
                element->setItem(current);
                element->setRepeated(true);
                element->setVolume(100);
                editOk(element);
            }
        }
    }
    return true;
}

void KeyMainWindow::on_keyListWidget_itemClicked(QListWidgetItem *item)
{
    int i = ui->keyListWidget->currentIndex().row();
    QString out = keys.at(i)->getName() + " ";
    qint64 sec = keys.at(i)->duration()/1000;
    out += QString::number(sec / 3600  % 24);
    out += ":";
    out += QString::number(sec / 60 % 60);
    out += ":";
    out += QString::number(sec % 60);
    fileInfo(out);
}

void KeyMainWindow::fileInfo(QString info)
{
    ui->fileLabel->setText("File Info: " + info);
}
