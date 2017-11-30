#include "keymainwindow.h"
#include "ui_keymainwindow.h"


QString rgbToString(QColor color)
{
    return "rgb(" + QString::number(color.red()) + "," + QString::number(color.green()) + "," + QString::number(color.blue()) + ");";
}


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
    this->prop = NULL;
    ui->setupUi(this);
<<<<<<< HEAD
    this->changeMainProp(Properties::loadProperties());
=======

>>>>>>> origin/master
    ui->fileTreeWidget->setColumnCount(2);
    QStringList headsList(QString("Path"));
    headsList.append("Name");
    ui->fileTreeWidget->setHeaderLabels(headsList);
    ui->fileTreeWidget->setSortingEnabled(true);

    //this->keyPagesList = new QList<QListWidget*>;
    this->keyPagesList.append(ui->keyListWidget_0);
    this->keyPagesList.append(ui->keyListWidget_1);
    this->keyPagesList.append(ui->keyListWidget_2);
    this->keyPagesList.append(ui->keyListWidget_3);
    this->keyPagesList.append(ui->keyListWidget_4);
    this->keyPagesList.append(ui->keyListWidget_5);
    this->keyPagesList.append(ui->keyListWidget_6);
    this->keyPagesList.append(ui->keyListWidget_7);
    this->keyPagesList.append(ui->keyListWidget_8);
    this->keyPagesList.append(ui->keyListWidget_9);

    connect(ui->keyListWidget_0, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(on_keyListWidget_itemClicked(QListWidgetItem*)));
    connect(ui->keyListWidget_1, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(on_keyListWidget_itemClicked(QListWidgetItem*)));
    connect(ui->keyListWidget_2, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(on_keyListWidget_itemClicked(QListWidgetItem*)));
    connect(ui->keyListWidget_3, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(on_keyListWidget_itemClicked(QListWidgetItem*)));
    connect(ui->keyListWidget_4, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(on_keyListWidget_itemClicked(QListWidgetItem*)));
    connect(ui->keyListWidget_5, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(on_keyListWidget_itemClicked(QListWidgetItem*)));
    connect(ui->keyListWidget_6, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(on_keyListWidget_itemClicked(QListWidgetItem*)));
    connect(ui->keyListWidget_7, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(on_keyListWidget_itemClicked(QListWidgetItem*)));
    connect(ui->keyListWidget_8, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(on_keyListWidget_itemClicked(QListWidgetItem*)));
    connect(ui->keyListWidget_9, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(on_keyListWidget_itemClicked(QListWidgetItem*)));


    connect(ui->keyListWidget_0, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(on_keyListWidget_doubleClicked(QModelIndex)));
    connect(ui->keyListWidget_1, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(on_keyListWidget_doubleClicked(QModelIndex)));
    connect(ui->keyListWidget_2, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(on_keyListWidget_doubleClicked(QModelIndex)));
    connect(ui->keyListWidget_3, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(on_keyListWidget_doubleClicked(QModelIndex)));
    connect(ui->keyListWidget_4, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(on_keyListWidget_doubleClicked(QModelIndex)));
    connect(ui->keyListWidget_5, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(on_keyListWidget_doubleClicked(QModelIndex)));
    connect(ui->keyListWidget_6, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(on_keyListWidget_doubleClicked(QModelIndex)));
    connect(ui->keyListWidget_7, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(on_keyListWidget_doubleClicked(QModelIndex)));
    connect(ui->keyListWidget_8, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(on_keyListWidget_doubleClicked(QModelIndex)));
    connect(ui->keyListWidget_9, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(on_keyListWidget_doubleClicked(QModelIndex)));


    //this->keys = new QList<QList<KeyElement*>*>;
    this->keys.append(new QList<KeyElement*>); //0
    this->keys.append(new QList<KeyElement*>); //1
    this->keys.append(new QList<KeyElement*>); //2
    this->keys.append(new QList<KeyElement*>); //3
    this->keys.append(new QList<KeyElement*>); //4
    this->keys.append(new QList<KeyElement*>); //5
    this->keys.append(new QList<KeyElement*>); //6
    this->keys.append(new QList<KeyElement*>); //7
    this->keys.append(new QList<KeyElement*>); //8
    this->keys.append(new QList<KeyElement*>); //9

    this->currentPage = 0;

    prelistening = false;
}

KeyMainWindow::~KeyMainWindow()
{
    stopAllPlay();
    on_deleteAllButton_clicked();
    for (int i = 0; i < keys.length(); i++)
    {
        keys.at(i)->clear();
        delete keys.at(i);
    }
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
    int index = this->keyPagesList.at(ui->tabWidget->currentIndex())->currentIndex().row();
    if (index >= 0)
    {
        logging("deleting element...");
        KeyElement* elem = this->keys.at(getCurrentPage())->at(index);
        keys.at(getCurrentPage())->removeAt(index);
        if (elem->getItem()->backgroundColor(1) != QColor(250,80,80,235))
        {
            elem->getItem()->setBackgroundColor(1,QColor(0,0,0,0));
        }
        keyPagesList.at(getCurrentPage())->takeItem(index);
        if (index > 0)
        {
            keyPagesList.at(getCurrentPage())->setCurrentRow(index - 1);
        }
        else
        {
            keyPagesList.at(getCurrentPage())->setCurrentRow(index);
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
    for (int j= 0; j < keys.length(); j++)
    {
        for (int i = 0; i < keys.at(j)->length(); i++)
        {
            if (keys.at(j)->at(i)->getItem()->backgroundColor(1) != QColor(250,80,80,235))
            {
                keys.at(j)->at(i)->getItem()->setBackgroundColor(1,QColor(0,0,0,0));
            }
            delete keys.at(j)->at(i);
        }
        keys.at(j)->clear();
        keyPagesList.at(j)->clear();
    }
    logging("all key elements was deleted");
}

void KeyMainWindow::on_playButton_clicked()
{
    stopAllPlay();
    currentPage = 0;
    logging("start playing... Enjoy =)");
    PlayWindow* window = new PlayWindow(this, this->prop);
    //connect (window,SIGNAL(buttonPressedSignal(QChar)),this,SLOT(startPlay(QChar)));
    //connect (window,SIGNAL(buttonReleasedSignal(QChar)),this,SLOT(stopPlay(QChar)));

    connect(window, SIGNAL(startSignal(QChar,int)), this, SLOT(start(QChar,int)));
    connect(window, SIGNAL(stopSignal(QChar,int)), this, SLOT(stop(QChar,int)));

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
        keys.at(getCurrentPage())->at(index.row())->play();
        logging("listening - " + keys.at(getCurrentPage())->at(index.row())->getName());
    }
    else
    {
        stopAllPlay();
    }
    prelistening = !prelistening;
}


void KeyMainWindow::start(QChar key, int page)
{
    QList<QListWidgetItem*> list = keyPagesList.at(page)->findItems(key,Qt::MatchStartsWith);
    if (!list.isEmpty())
    {
        if (list.at(0)->text()[0] == key)
        {
            for (int i = 0; i < keys.at(page)->length(); i++)
            {
                if (keys.at(page)->value(i)->getKey() == key)
                {
                    KeyElement *elem = keys.at(page)->value(i);
                    if (elem->getFormat() == 1)
                    {
                        elem->setFormat(0);
                        if (elem->isRepeated())
                        {
                            disconnect(elem->getPlayer(), SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)), elem->getPlayer(), SLOT(play()));
                        }
                        elem->stop();
                        return;
                    }
                    if (elem->getFormat() == 0)
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

void KeyMainWindow::stop(QChar key, int page)
{
    QList<QListWidgetItem*> list = keyPagesList.at(page)->findItems(key,Qt::MatchStartsWith);
    if (!list.isEmpty())
    {
        if (list.at(0)->text()[0] == key)
        {
            for (int i = 0; i < keys.at(page)->length(); i++)
            {
                if (keys.at(page)->value(i)->getKey() == key)
                {
                    KeyElement *elem = keys.at(page)->value(i);
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

void KeyMainWindow::stopAllPlay()
{
    logging("stopping all...");
    for (int j = 0; j < keys.length(); j++)
    {
        for (int i = 0; i < keys.at(j)->length(); i++)
        {
            keys.at(j)->value(i)->setFormat(0);
            if (keys.at(j)->value(i)->isRepeated())
            {
                disconnect(keys.at(j)->value(i)->getPlayer(), SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)), keys.at(j)->value(i)->getPlayer(), SLOT(play()));
            }
            keys.at(j)->value(i)->stop();
        }
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
    FILE *file;
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
    for (int j = 0; j < keys.length(); j++)
    {
        len = keys.at(j)->length();
        fwrite(&len,sizeof(int),1,file);
        for (int i = 0; i < keys.at(j)->length(); i++)
        {
            QString qstr = keys.at(j)->at(i)->getKey();
            qstr += "\t";
            qstr += keys.at(j)->at(i)->getPath();
            qstr += "\n";
            const char *str = qstr.toLatin1().data();
            const int volume = keys.at(j)->at(i)->getVolume();
            const bool repeat = keys.at(j)->at(i)->isRepeated();
            fwrite(&repeat, sizeof(bool), 1, file);
            fwrite(&volume, sizeof(int), 1, file);
            fwrite(str, sizeof(char), qstr.length(), file);
        }
    }
    fclose(file);
    logging("file - " + name +" was saved");
    delete file;
}

void KeyMainWindow::on_actionOpenFile_triggered()
{

    FILE *file;
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
    int temp = getCurrentPage();
    int pages = 0;
    fread(&pages,sizeof(int),1,file);
    for (int j = 0; j < pages; j++)
    {
        ui->tabWidget->setCurrentIndex(j);
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
    }
    fclose(file);
    ui->tabWidget->setCurrentIndex(temp);
    logging("file - " + name + " was readed");
    delete file;
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
    keyPagesList.at(getCurrentPage())->addItem(buffer);
    keys.at(getCurrentPage())->append(element);
}

void KeyMainWindow::on_autoButton_clicked()
{
    logging("autoFilling...");
    int oldPage = ui->tabWidget->currentIndex();
    on_deleteAllButton_clicked();
    sum = 0;
    currentPage = 0;
    ui->tabWidget->setCurrentIndex(currentPage);
    for (int i = 0; i < ui->fileTreeWidget->topLevelItemCount(); i++)
    {
        if (!autoFill(ui->fileTreeWidget->topLevelItem(i)))
        {
            return;
        }
    }
    currentPage = oldPage;
    ui->tabWidget->setCurrentIndex(currentPage);
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
                    if (++currentPage >= 10)
                    {
                        return false;
                    }
                    sum = 0;
                    ui->tabWidget->setCurrentIndex(currentPage);
                }
                KeyElement* element = new KeyElement(current->text(0));
                element->setKey('A' + sum);
                sum++;
                element->setItem(current);
                element->setRepeated(this->prop->getRepeat());
                element->setVolume(this->prop->getVolume());
                editOk(element);
            }
        }
    }
    return true;
}

void KeyMainWindow::on_keyListWidget_itemClicked(QListWidgetItem *item)
{
    int i = keyPagesList.at(getCurrentPage())->currentIndex().row();
    QString out = keys.at(getCurrentPage())->at(i)->getName() + " ";
    qint64 sec = keys.at(getCurrentPage())->at(i)->duration()/1000;
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

int KeyMainWindow::getCurrentPage()
{
    return ui->tabWidget->currentIndex();
}

void KeyMainWindow::on_actionProperties_triggered()
{
    PropertiesDialog* dialog = new PropertiesDialog(this);
    connect(dialog, SIGNAL(changeProperties(Properties*)), this, SLOT(changeMainProp(Properties*)));
    dialog->show();
}

void KeyMainWindow::changeMainProp(Properties *prop)
{
    if (prop != NULL)
    {
        QApplication::setPalette(prop->getPalette());
        ui->fileTreeWidget->headerItem()->setBackgroundColor(0, prop->getPalette().button().color());
        ui->fileTreeWidget->headerItem()->setBackgroundColor(1, prop->getPalette().button().color());
        ui->addButton->setStyleSheet("background-color:" + rgbToString(prop->getPalette().button().color()));
        ui->deleteButton->setStyleSheet("background-color:" + rgbToString(prop->getPalette().button().color()));
        ui->editButton->setStyleSheet("background-color:" + rgbToString(prop->getPalette().button().color()));
        ui->playButton->setStyleSheet("background-color:" + rgbToString(prop->getPalette().button().color()));
        ui->deleteAllButton->setStyleSheet("background-color:" + rgbToString(prop->getPalette().button().color()));
        ui->autoButton->setStyleSheet("background-color:" + rgbToString(prop->getPalette().button().color()));

        ui->keyListWidget_0->setStyleSheet("background-color:" + rgbToString(prop->getPalette().button().color()));
        ui->keyListWidget_1->setStyleSheet("background-color:" + rgbToString(prop->getPalette().button().color()));
        ui->keyListWidget_2->setStyleSheet("background-color:" + rgbToString(prop->getPalette().button().color()));
        ui->keyListWidget_3->setStyleSheet("background-color:" + rgbToString(prop->getPalette().button().color()));
        ui->keyListWidget_4->setStyleSheet("background-color:" + rgbToString(prop->getPalette().button().color()));
        ui->keyListWidget_5->setStyleSheet("background-color:" + rgbToString(prop->getPalette().button().color()));
        ui->keyListWidget_6->setStyleSheet("background-color:" + rgbToString(prop->getPalette().button().color()));
        ui->keyListWidget_7->setStyleSheet("background-color:" + rgbToString(prop->getPalette().button().color()));
        ui->keyListWidget_8->setStyleSheet("background-color:" + rgbToString(prop->getPalette().button().color()));
        ui->keyListWidget_9->setStyleSheet("background-color:" + rgbToString(prop->getPalette().button().color()));

        ui->tabWidget->setStyleSheet("background-color:" + rgbToString(prop->getPalette().button().color()));
        ui->tabWidget->setStyleSheet("qproperty-titleColor:" + rgbToString(prop->getPalette().button().color()));
        ui->tabWidget->setStyleSheet("qproperty-titleButtonColor:" + rgbToString(prop->getPalette().button().color()));

#ifdef __WIN32
        qDebug() << prop->getPalette().button().color();
        qDebug() << prop->getPalette().window().color();

#endif

        if (this->prop != NULL)
        {
            delete this->prop;
        }
        this->prop = prop;
        this->prop->saveProperties();
    }
}
