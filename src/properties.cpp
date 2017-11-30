#include "properties.h"
#include <QApplication>
#include <QStyle>
#include "nullproperties.h"

Properties::Properties(QObject *parent) : QObject(parent)
{

}

Properties::Properties(QString theme, bool repeatDefault, int volumeDefault, bool capsDefault, bool shiftInv)
{
    this->theme = theme;
    this->repeatDef = repeatDefault;
    this->volumeDef = volumeDefault;
    this->capsDef = capsDefault;
    this->shiftInv = shiftInv;
}

QString Properties::getTheme()
{
    return this->theme;
}

bool Properties::getRepeat()
{
    return this->repeatDef;
}

int Properties::getVolume()
{
    return this->volumeDef;
}

bool Properties::getCaps()
{
    return this->capsDef;
}

bool Properties::getShift()
{
    return this->shiftInv;
}

QPalette Properties::getPalette()
{
    if (this->getTheme() == "Dark")
    {
        QPalette palette;
        palette.setColor(QPalette::Window, QColor(53, 53, 53));
        palette.setColor(QPalette::WindowText, QColor(72, 120, 255));
        palette.setColor(QPalette::Base, QColor(25, 25, 25));
        palette.setColor(QPalette::AlternateBase, QColor(53, 3, 53));
        palette.setColor(QPalette::ToolTipBase, QColor(155, 155, 155));
        palette.setColor(QPalette::ToolTipText, QColor(72, 120, 255));
        palette.setColor(QPalette::Text, QColor(205, 25, 235));
        palette.setColor(QPalette::Button, QColor(55, 55, 55));
        palette.setColor(QPalette::ButtonText, QColor(225,35,255));
        palette.setColor(QPalette::BrightText, QColor(155, 25, 120));
        palette.setColor(QPalette::Link, QColor(72, 120, 255));
        palette.setColor(QPalette::Highlight, QColor(72, 120, 255));
        palette.setColor(QPalette::HighlightedText, QColor(0, 0, 0));
        return palette;
    }

    if (this->getTheme() == "Default")
    {
        return QApplication::style()->standardPalette();
    }

    if (this->getTheme() == "Calibri")
    {
        QPalette palette;
        palette.setColor(QPalette::Window, QColor(100, 155, 255));
        palette.setColor(QPalette::WindowText, QColor(20, 20, 20));
        palette.setColor(QPalette::Base, QColor(100, 155, 255));
        palette.setColor(QPalette::AlternateBase, QColor(70, 145, 255));
        palette.setColor(QPalette::ToolTipBase, QColor(20, 255, 255));
        palette.setColor(QPalette::ToolTipText, QColor(25, 25, 0));
        palette.setColor(QPalette::Text, QColor(10, 10, 10));
        palette.setColor(QPalette::Button, QColor(100, 200, 100));
        palette.setColor(QPalette::ButtonText, QColor(0, 0, 0));
        palette.setColor(QPalette::BrightText, QColor(53, 53, 53));
        palette.setColor(QPalette::Link, QColor(25, 25, 25));
        palette.setColor(QPalette::Highlight, QColor(150, 150, 255));
        palette.setColor(QPalette::HighlightedText, QColor(53, 53, 53));
        return palette;
    }

    if (this->getTheme() == "Union")
    {
        QPalette palette;
        palette.setColor(QPalette::Window, QColor(255, 100, 140));
        palette.setColor(QPalette::WindowText, QColor(50, 10, 50));
        palette.setColor(QPalette::Base, QColor(255, 100, 140));
        palette.setColor(QPalette::AlternateBase, QColor(50, 50, 50));
        palette.setColor(QPalette::ToolTipBase, QColor(20, 20, 20));
        palette.setColor(QPalette::ToolTipText, QColor(200, 200, 255));
        palette.setColor(QPalette::Text, QColor(53, 53, 53));
        palette.setColor(QPalette::Button, QColor(120, 220, 220));
        palette.setColor(QPalette::ButtonText, QColor(53, 53, 53));
        palette.setColor(QPalette::BrightText, QColor(53, 53, 53));
        palette.setColor(QPalette::Link, QColor(120, 220, 220));
        palette.setColor(QPalette::Highlight, QColor(103, 253, 103));
        palette.setColor(QPalette::HighlightedText, QColor(153, 53, 253));
        return palette;
    }
    return QPalette();
}

bool Properties::isNull()
{
    return false;
}

void Properties::saveProperties()
{
    FILE *file;
    QString name = QApplication::applicationDirPath() + "/prop.kps";
    if (name.isEmpty())
    {
        return;
    }
    file = fopen(name.toLatin1().data(), "w+b");
    if (!file)
    {
        return;
    }
    fwrite(&(this->shiftInv), sizeof(bool),1,file);
    fwrite(&(this->capsDef), sizeof(bool),1,file);
    fwrite(&(this->volumeDef), sizeof(int),1,file);
    fwrite(&(this->repeatDef), sizeof(bool),1,file);

    const char *str = this->theme.toLatin1().data();
    fwrite(str, sizeof(char), this->theme.length(), file);
    fwrite("\n", sizeof(char), 1, file);
    fclose(file);
    delete file;
}

Properties* Properties::loadProperties()
{
    FILE *file;
    QString name = QApplication::applicationDirPath() + "/prop.kps";
    if (name.isEmpty())
    {
        return new NullProperties();
    }
    file = fopen(name.toLatin1().data(), "r+b");
    if (!file)
    {
        return new NullProperties();
    }
    bool shiftInv;
    bool capsDef;
    int volumeDef;
    bool repeatDef;
    fread(&shiftInv, sizeof(bool),1,file);
    fread(&capsDef, sizeof(bool),1,file);
    fread(&volumeDef, sizeof(int),1,file);
    fread(&repeatDef, sizeof(bool),1,file);
    char temp = '\n';
    QString theme = "";
    while (true)
    {
        fread(&temp, sizeof(char), 1, file);
        if (temp != '\n')
        {
            theme.append(temp);
        }
        else
        {
            break;
        }
    }
    fclose(file);
    delete file;
    return new Properties(theme, repeatDef, volumeDef, capsDef, shiftInv);
}
