#include "keymainwindow.h"
#include "ui_keymainwindow.h"
#include <QApplication>


QString rgb_to_string(QColor color)
{
    return "rgb(" + QString::number(color.red()) + "," + QString::number(color.green()) + "," + QString::number(color.blue()) + ");";
}




QTreeWidgetItem* KeyMainWindow::GetDir(QString path, QTreeWidgetItem* parent) const
{
    int check = 1;
    QTreeWidgetItem* item = nullptr;
    QDir folder(path);
    QFileInfo path_info(path);
    if (path_info.isDir())
    {
        Logging("adding folder...");
        for (QFileInfo temp : folder.entryInfoList())
        {
            if (check > 2)
            {
                if (temp.fileName().endsWith(".mp3") || temp.fileName().endsWith(".wav"))
                {
                    item = new QTreeWidgetItem(parent);
                    item->setText(0, temp.absoluteFilePath());
                    item->setText(1, temp.fileName());
                    ui_->fileTreeWidget->addTopLevelItem(item);
                    new TryPlayer(item);
                }
                if (temp.isDir())
                {
	                QTreeWidgetItem * parentFolder = new QTreeWidgetItem(parent);
                    parentFolder->setText(0, temp.absoluteFilePath());
                    GetDir(temp.absoluteFilePath(), parentFolder);
                }
            }
            check++;
        }
        Logging("folder was added");
    }
    else
    {
        Logging("adding file...");
        item = new QTreeWidgetItem(parent);
        item->setText(0,path_info.absoluteFilePath());
        item->setText(1, path_info.fileName());
        ui_->fileTreeWidget->addTopLevelItem(item);
        Logging("file was added");
    }
    return item;
}




KeyMainWindow::KeyMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui_(new Ui::KeyMainWindow)
{
    ui_->setupUi(this);
    this->Initialize();
}




KeyMainWindow::~KeyMainWindow()
{
    StopAllPlay();
    OnDeleteAllButtonClicked();
    for (int i = 0; i < keys_.length(); i++)
    {
        keys_.at(i)->clear();
        delete keys_.at(i);
    }
    delete ui_;
}




void KeyMainWindow::OnEditButtonClicked() const
{
    if (ui_->fileTreeWidget->currentItem() != NULL)
    {
        if (ui_->fileTreeWidget->currentItem()->text(1).endsWith(".mp3") || ui_->fileTreeWidget->currentItem()->text(1).endsWith(".wav"))
        {
            Logging("start editing...");
            KeyEditDialog* dialog = new KeyEditDialog();
            dialog->SetPath(ui_->fileTreeWidget->currentItem());
            connect(dialog,SIGNAL(finish(KeyElement*)),this, SLOT(EditOk(KeyElement*)));
            dialog->show();
            Logging("finish editing");
        }
        else
        {
            Logging("it's folder");
        }
    }
    else
    {
        Logging("nothing to edit");
    }
}





void KeyMainWindow::OnAddButtonClicked() const
{
    Logging("adding folder with resources...");
    QString root = QFileDialog::getExistingDirectoryUrl().toLocalFile();
    if (root.isEmpty())
    {
        Logging("cancelling adding dirictory");
        return;
    }
    QTreeWidgetItem* item = new QTreeWidgetItem();
    item->setText(0, root);
    ui_->fileTreeWidget->addTopLevelItem(item);
    GetDir(root, item);
    Logging("dirictory was added");
}





void KeyMainWindow::OnDeleteButtonClicked()
{
	const int index = this->key_pages_list_.at(ui_->tabWidget->currentIndex())->currentIndex().row();
    if (index >= 0)
    {
        Logging("deleting element...");
        KeyElement* elem = this->keys_.at(GetCurrentPage())->at(index);
        keys_.at(GetCurrentPage())->removeAt(index);
        if (elem->GetItem()->backgroundColor(1) != QColor(250, 80, 80, 235))
        {
            elem->GetItem()->setBackgroundColor(1, QColor(0, 0, 0, 0));
        }
        key_pages_list_.at(GetCurrentPage())->takeItem(index);
        if (index > 0)
        {
            key_pages_list_.at(GetCurrentPage())->setCurrentRow(index - 1);
        }
        else
        {
            key_pages_list_.at(GetCurrentPage())->setCurrentRow(index);
        }
        delete elem;
        Logging("key element was deleted");
    }
    else
    {
        Logging("nothing to delete");
    }
}





void KeyMainWindow::OnDeleteAllButtonClicked()
{
    Logging("deleting all key elements...");
    for (int j = 0; j < keys_.length(); j++)
    {
        for (int i = 0; i < keys_.at(j)->length(); i++)
        {
            if (keys_.at(j)->at(i)->GetItem()->backgroundColor(1) != QColor(250,80,80,235))
            {
                keys_.at(j)->at(i)->GetItem()->setBackgroundColor(1,QColor(0,0,0,0));
            }
            delete keys_.at(j)->at(i);
        }
        keys_.at(j)->clear();
        key_pages_list_.at(j)->clear();
    }
    Logging("all key elements was deleted");
}




void KeyMainWindow::OnPlayButtonClicked()
{
    StopAllPlay();
    current_page_ = 0;
    Logging("start playing... Enjoy =)");
    PlayWindow* window = new PlayWindow(this, this->prop_);;

    connect(window, SIGNAL(startSignal(QChar,int)), this, SLOT(Start(QChar,int)));
    connect(window, SIGNAL(stopSignal(QChar,int)), this, SLOT(Stop(QChar,int)));

    connect(window,SIGNAL(rejected()),this,SLOT(StopAllPlay()));
    shift_ = false;
    window->show();
}




void KeyMainWindow::OnFileTreeWidgetDoubleClicked(const QModelIndex &index)
{
    OnEditButtonClicked();
}




void KeyMainWindow::OnKeyListWidgetDoubleClicked(const QModelIndex &index)
{
    if (!prelistening_)
    {
        keys_.at(GetCurrentPage())->at(index.row())->Play();
        Logging("listening - " + keys_.at(GetCurrentPage())->at(index.row())->GetName());
    }
    else
    {
        StopAllPlay();
    }
    prelistening_ = !prelistening_;
}




void KeyMainWindow::Start(const QChar key, const int page) const
{
    QList<QListWidgetItem*> list = key_pages_list_.at(page)->findItems(key,Qt::MatchStartsWith);
    if (!list.isEmpty())
    {
        if (list.at(0)->text()[0] == key)
        {
            for (int i = 0; i < keys_.at(page)->length(); i++)
            {
                if (keys_.at(page)->value(i)->GetKey() == key)
                {
                    KeyElement *elem = keys_.at(page)->value(i);
                    if (elem->GetFormat() == 1)
                    {
                        elem->SetFormat(0);
                        if (elem->IsRepeated())
                        {
                            disconnect(elem->GetPlayer(), SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)), elem->GetPlayer(), SLOT(play()));
                        }
                        elem->Stop();
                        return;
                    }
                    if (elem->GetFormat() == 0)
                    {
                        elem->SetFormat(1);
                        elem->Play();
                        if (elem->IsRepeated())
                        {
                            connect(elem->GetPlayer(), SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)), elem->GetPlayer(), SLOT(play()));
                        }
                        return;
                    }
                    elem->Play();
                }
            }
        }
    }
}




void KeyMainWindow::Stop(const QChar key, const int page) const
{
    QList<QListWidgetItem*> list = key_pages_list_.at(page)->findItems(key,Qt::MatchStartsWith);
    if (!list.isEmpty())
    {
        if (list.at(0)->text()[0] == key)
        {
            for (int i = 0; i < keys_.at(page)->length(); i++)
            {
                if (keys_.at(page)->value(i)->GetKey() == key)
                {
                    KeyElement *elem = keys_.at(page)->value(i);
                    if (elem->IsRepeated())
                    {
                        disconnect(elem->GetPlayer(), SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)), elem->GetPlayer(), SLOT(play()));
                    }
                    elem->SetFormat(0);
                    elem->Stop();
                }
            }
        }
    }
}





void KeyMainWindow::StopAllPlay()
{
    Logging("stopping all...");
    for (int j = 0; j < keys_.length(); j++)
    {
        for (int i = 0; i < keys_.at(j)->length(); i++)
        {
            keys_.at(j)->value(i)->SetFormat(0);
            if (keys_.at(j)->value(i)->IsRepeated())
            {
                disconnect(keys_.at(j)->value(i)->GetPlayer(), SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)), keys_.at(j)->value(i)->GetPlayer(), SLOT(play()));
            }
            keys_.at(j)->value(i)->Stop();
        }
    }
    shift_ = false;
    Logging("all plays was stopped");
}





void KeyMainWindow::EditOk(KeyElement *element)
{
    AddInList(element);
    if (element->IsValid())
    {
        if (element->IsRepeated())
        {
            element->GetItem()->setBackgroundColor(1,QColor(80,80,250,235));
        }
        else
        {
            element->GetItem()->setBackgroundColor(1,QColor(80,250,80,235));
        }
    }
    else
    {
        element->GetItem()->setBackgroundColor(1,QColor(250,80,80,235));
    }
    Logging("element was added");
}




void KeyMainWindow::OnActionSaveFileTriggered()
{
	Logging("choosing file...");
    QString name = QFileDialog::getSaveFileName(this, tr("Save Key List"), QDir::currentPath(), tr("Key List files (*.kpl);; All files(*.*)"));
    if (name.isEmpty())
    {
        Logging("canceling saving file");
        return;
    }
    FILE *file = fopen(name.toLatin1().data(), "w+b");
    Logging("rewriting file...");
    if (!file)
    {
        Logging("can't create file...");
        return;
    }
    Logging("file was created. Writting...");
    int len = keys_.length();
    fwrite(&len,sizeof(int),1,file);
    for (int j = 0; j < keys_.length(); j++)
    {
        len = keys_.at(j)->length();
        fwrite(&len,sizeof(int),1,file);
        for (int i = 0; i < keys_.at(j)->length(); i++)
        {
            QString qstr = keys_.at(j)->at(i)->GetKey();
            qstr += "\t";
            qstr += keys_.at(j)->at(i)->GetPath();
            qstr += "\n";
            const char *str = qstr.toLatin1().data();
            const int volume = keys_.at(j)->at(i)->GetVolume();
            const bool repeat = keys_.at(j)->at(i)->IsRepeated();
            fwrite(&repeat, sizeof(bool), 1, file);
            fwrite(&volume, sizeof(int), 1, file);
            fwrite(str, sizeof(char), qstr.length(), file);
        }
    }
    fclose(file);
    Logging("file - " + name +" was saved");
    delete file;
}




void KeyMainWindow::OnActionOpenFileTriggered()
{
	Logging("choosing file...");

    QString name = QFileDialog::getOpenFileName(this, tr("Open Key List"), QDir::currentPath(), tr("Key List files (*.kpl);; All files(*.*)"));
    if (name.isEmpty())
    {
        Logging("canceling opening file");
        return;
    }
    FILE *file = fopen(name.toLatin1().data(), "r+b");
    if (!file)
    {
        Logging("file not founded");
        return;
    }

    Logging("opening file...");

    OnDeleteAllButtonClicked();
    int len = 0;
    int temp = GetCurrentPage();
    int pages = 0;
    fread(&pages,sizeof(int),1,file);
    for (int j = 0; j < pages; j++)
    {
        ui_->tabWidget->setCurrentIndex(j);
        fread(&len,sizeof(int),1,file);

        for (int i = 0; i < len; i++)
        {
            bool repeat = false;
            int volume = 0;
            char key;
            char current_char = ' ';
            fread(&repeat, sizeof(bool), 1, file);
            fread(&volume, sizeof(int), 1, file);
            fread(&key, sizeof(char), 1, file);
            fseek(file, 1, 1);
            QString qstr = "";
            while (true)
            {
                fread(&current_char, sizeof(char), 1, file);
                if (current_char != '\n')
                {
                    qstr.append(current_char);
                }
                else
                {
                    break;
                }
            }
            KeyElement* elem = new KeyElement(qstr);
            elem->set_volume(volume);
            elem->SetKey(key);
            elem->SetRepeated(repeat);

            QList<QTreeWidgetItem*> list = ui_->fileTreeWidget->findItems(qstr, Qt::MatchRecursive | Qt::MatchFixedString, 0);
            if (list.isEmpty())
            {
                elem->SetItem(GetDir(qstr, nullptr));
                Logging("adding Item - " + elem->GetItem()->text(0));
            }
            else
            {
                elem->SetItem(list.at(0));
            }
            EditOk(elem);
            Logging("added key item from file");
        }
    }
    fclose(file);
    ui_->tabWidget->setCurrentIndex(temp);
    Logging("file - " + name + " was readed");
    delete file;
}




void KeyMainWindow::OnActionSaveFileMenuTriggered()
{
    OnActionSaveFileTriggered();
}





void KeyMainWindow::OnActionOpenFileMenuTriggered()
{
    OnActionOpenFileTriggered();
}




void KeyMainWindow::Logging(const QString message) const
{
    this->ui_->infoLabel->setText("Info: " + message);
    qDebug() << message;
}





void KeyMainWindow::AddInList(KeyElement *element) const
{
    QString buffer = ": ";
    Logging("adding key element...");
    buffer.insert(0, element->GetKey());
    buffer += element->GetName();
    key_pages_list_.at(GetCurrentPage())->addItem(buffer);
    keys_.at(GetCurrentPage())->append(element);
}





void KeyMainWindow::OnAutoButtonClicked()
{
    Logging("autoFilling...");
	const int old_page = ui_->tabWidget->currentIndex();
    OnDeleteAllButtonClicked();
    sum_ = 0;
    current_page_ = 0;
    ui_->tabWidget->setCurrentIndex(current_page_);
    for (int i = 0; i < ui_->fileTreeWidget->topLevelItemCount(); i++)
    {
        if (!AutoFill(ui_->fileTreeWidget->topLevelItem(i)))
        {
            return;
        }
    }
    current_page_ = old_page;
    ui_->tabWidget->setCurrentIndex(current_page_);
    Logging("autoFilling finished sucessfully");
}




bool KeyMainWindow::AutoFill(QTreeWidgetItem* current)
{
    if (current->childCount() > 0)
    {
        for (int j = 0; j < current->childCount(); j++)
        {
            if (!(this->AutoFill(current->child(j))))
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
                if (sum_ + 'A' > 'Z')
                {
                    if (++current_page_ >= 10)
                    {
                        return false;
                    }
                    sum_ = 0;
                    ui_->tabWidget->setCurrentIndex(current_page_);
                }
                KeyElement* element = new KeyElement(current->text(0));
                element->SetKey('A' + sum_);
                sum_++;
                element->SetItem(current);
                element->SetRepeated(this->prop_->GetRepeat());
                element->set_volume(this->prop_->GetVolume());
                EditOk(element);
            }
        }
    }
    return true;
}




void KeyMainWindow::OnKeyListWidgetItemClicked(QListWidgetItem *item)
{
	const int i = key_pages_list_.at(GetCurrentPage())->currentIndex().row();
    QString out = keys_.at(GetCurrentPage())->at(i)->GetName() + " ";
	const qint64 sec = keys_.at(GetCurrentPage())->at(i)->Duration()/1000;
    out += QString::number(sec / 3600  % 24);
    out += ":";
    out += QString::number(sec / 60 % 60);
    out += ":";
    out += QString::number(sec % 60);
    FileInfo(out);
}




void KeyMainWindow::FileInfo(const QString info) const
{
    ui_->fileLabel->setText("File Info: " + info);
}




int KeyMainWindow::GetCurrentPage() const
{
    return ui_->tabWidget->currentIndex();
}




void KeyMainWindow::Initialize()
{
    this->prop_ = nullptr;
    this->current_page_ = 0;
    prelistening_ = false;

    this->ChangeMainProp(Properties::LoadProperties());

    ui_->fileTreeWidget->setColumnCount(2);
    QStringList headsList(QString("Path"));
    headsList.append("Name");
    ui_->fileTreeWidget->setHeaderLabels(headsList);
    ui_->fileTreeWidget->setSortingEnabled(true);

    this->key_pages_list_.append(ui_->keyListWidget_0);
    this->key_pages_list_.append(ui_->keyListWidget_1);
    this->key_pages_list_.append(ui_->keyListWidget_2);
    this->key_pages_list_.append(ui_->keyListWidget_3);
    this->key_pages_list_.append(ui_->keyListWidget_4);
    this->key_pages_list_.append(ui_->keyListWidget_5);
    this->key_pages_list_.append(ui_->keyListWidget_6);
    this->key_pages_list_.append(ui_->keyListWidget_7);
    this->key_pages_list_.append(ui_->keyListWidget_8);
    this->key_pages_list_.append(ui_->keyListWidget_9);

    this->keys_.append(new QList<KeyElement*>); //0
    this->keys_.append(new QList<KeyElement*>); //1
    this->keys_.append(new QList<KeyElement*>); //2
    this->keys_.append(new QList<KeyElement*>); //3
    this->keys_.append(new QList<KeyElement*>); //4
    this->keys_.append(new QList<KeyElement*>); //5
    this->keys_.append(new QList<KeyElement*>); //6
    this->keys_.append(new QList<KeyElement*>); //7
    this->keys_.append(new QList<KeyElement*>); //8
    this->keys_.append(new QList<KeyElement*>); //9

    this->InitializeButtonsConnections();
    this->InitializeActionsConnections();
    this->InitializeSpecificConnections();
}

void KeyMainWindow::InitializeButtonsConnections()
{
    connect(ui_->addButton, SIGNAL(clicked(bool)), this, SLOT(OnAddButtonClicked()));
    connect(ui_->playButton, SIGNAL(clicked(bool)), this, SLOT(OnPlayButtonClicked()));
    connect(ui_->editButton, SIGNAL(clicked(bool)), this, SLOT(OnEditButtonClicked()));
    connect(ui_->autoButton, SIGNAL(clicked(bool)), this, SLOT(OnAutoButtonClicked()));
    connect(ui_->deleteButton, SIGNAL(clicked(bool)), this, SLOT(OnDeleteButtonClicked()));
    connect(ui_->deleteAllButton, SIGNAL(clicked(bool)), this, SLOT(OnDeleteAllButtonClicked()));
}

void KeyMainWindow::InitializeActionsConnections()
{
    connect(ui_->actionSaveFile, SIGNAL(triggered(bool)), this, SLOT(OnActionSaveFileTriggered()));
    connect(ui_->actionSaveFileMenu, SIGNAL(triggered(bool)), this, SLOT(OnActionSaveFileMenuTriggered()));
    connect(ui_->actionOpenFile, SIGNAL(triggered(bool)), this, SLOT(OnActionOpenFileTriggered()));
    connect(ui_->actionOpenFileMenu, SIGNAL(triggered(bool)), this, SLOT(OnActionOpenFileMenuTriggered()));
    connect(ui_->actionProperties, SIGNAL(triggered(bool)), this, SLOT(OnActionPropertiesTriggered()));
}




void KeyMainWindow::InitializeSpecificConnections()
{
    connect(ui_->keyListWidget_0, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(OnKeyListWidgetItemClicked(QListWidgetItem*)));
    connect(ui_->keyListWidget_1, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(OnKeyListWidgetItemClicked(QListWidgetItem*)));
    connect(ui_->keyListWidget_2, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(OnKeyListWidgetItemClicked(QListWidgetItem*)));
    connect(ui_->keyListWidget_3, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(OnKeyListWidgetItemClicked(QListWidgetItem*)));
    connect(ui_->keyListWidget_4, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(OnKeyListWidgetItemClicked(QListWidgetItem*)));
    connect(ui_->keyListWidget_5, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(OnKeyListWidgetItemClicked(QListWidgetItem*)));
    connect(ui_->keyListWidget_6, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(OnKeyListWidgetItemClicked(QListWidgetItem*)));
    connect(ui_->keyListWidget_7, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(OnKeyListWidgetItemClicked(QListWidgetItem*)));
    connect(ui_->keyListWidget_8, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(OnKeyListWidgetItemClicked(QListWidgetItem*)));
    connect(ui_->keyListWidget_9, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(OnKeyListWidgetItemClicked(QListWidgetItem*)));


    connect(ui_->keyListWidget_0, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(OnKeyListWidgetDoubleClicked(QModelIndex)));
    connect(ui_->keyListWidget_1, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(OnKeyListWidgetDoubleClicked(QModelIndex)));
    connect(ui_->keyListWidget_2, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(OnKeyListWidgetDoubleClicked(QModelIndex)));
    connect(ui_->keyListWidget_3, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(OnKeyListWidgetDoubleClicked(QModelIndex)));
    connect(ui_->keyListWidget_4, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(OnKeyListWidgetDoubleClicked(QModelIndex)));
    connect(ui_->keyListWidget_5, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(OnKeyListWidgetDoubleClicked(QModelIndex)));
    connect(ui_->keyListWidget_6, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(OnKeyListWidgetDoubleClicked(QModelIndex)));
    connect(ui_->keyListWidget_7, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(OnKeyListWidgetDoubleClicked(QModelIndex)));
    connect(ui_->keyListWidget_8, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(OnKeyListWidgetDoubleClicked(QModelIndex)));
    connect(ui_->keyListWidget_9, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(OnKeyListWidgetDoubleClicked(QModelIndex)));

}




void KeyMainWindow::OnActionPropertiesTriggered()
{
    PropertiesDialog* dialog = new PropertiesDialog(this);
    connect(dialog, SIGNAL(changeProperties(Properties*)), this, SLOT(ChangeMainProp(Properties*)));
    dialog->show();
}




void KeyMainWindow::ChangeMainProp(Properties *prop)
{
    if (prop != nullptr)
    {
        QApplication::setPalette(prop->GetPalette());
        ui_->fileTreeWidget->headerItem()->setBackgroundColor(0, prop->GetPalette().button().color());
        ui_->fileTreeWidget->headerItem()->setBackgroundColor(1, prop->GetPalette().button().color());
        ui_->addButton->setStyleSheet("background-color:" + rgb_to_string(prop->GetPalette().button().color()));
        ui_->deleteButton->setStyleSheet("background-color:" + rgb_to_string(prop->GetPalette().button().color()));
        ui_->editButton->setStyleSheet("background-color:" + rgb_to_string(prop->GetPalette().button().color()));
        ui_->playButton->setStyleSheet("background-color:" + rgb_to_string(prop->GetPalette().button().color()));
        ui_->deleteAllButton->setStyleSheet("background-color:" + rgb_to_string(prop->GetPalette().button().color()));
        ui_->autoButton->setStyleSheet("background-color:" + rgb_to_string(prop->GetPalette().button().color()));

        ui_->keyListWidget_0->setStyleSheet("background-color:" + rgb_to_string(prop->GetPalette().button().color()));
        ui_->keyListWidget_1->setStyleSheet("background-color:" + rgb_to_string(prop->GetPalette().button().color()));
        ui_->keyListWidget_2->setStyleSheet("background-color:" + rgb_to_string(prop->GetPalette().button().color()));
        ui_->keyListWidget_3->setStyleSheet("background-color:" + rgb_to_string(prop->GetPalette().button().color()));
        ui_->keyListWidget_4->setStyleSheet("background-color:" + rgb_to_string(prop->GetPalette().button().color()));
        ui_->keyListWidget_5->setStyleSheet("background-color:" + rgb_to_string(prop->GetPalette().button().color()));
        ui_->keyListWidget_6->setStyleSheet("background-color:" + rgb_to_string(prop->GetPalette().button().color()));
        ui_->keyListWidget_7->setStyleSheet("background-color:" + rgb_to_string(prop->GetPalette().button().color()));
        ui_->keyListWidget_8->setStyleSheet("background-color:" + rgb_to_string(prop->GetPalette().button().color()));
        ui_->keyListWidget_9->setStyleSheet("background-color:" + rgb_to_string(prop->GetPalette().button().color()));

        ui_->tabWidget->setStyleSheet("background-color:" + rgb_to_string(prop->GetPalette().button().color()));
        ui_->tabWidget->setStyleSheet("qproperty-titleColor:" + rgb_to_string(prop->GetPalette().button().color()));
#ifdef __WIN32
        qDebug() << prop->GetPalette().button().color();
        qDebug() << prop->GetPalette().window().color();

#endif

        if (this->prop_ != nullptr)
        {
            delete this->prop_;
        }
        this->prop_ = prop;
        this->prop_->SaveProperties();
    }
}
