#include "properties.h"
#include <QApplication>
#include <QStyle>
#include "nullproperties.h"

Properties::Properties(QObject *parent) : QObject(parent)
{

}

Properties::Properties(const QString theme, const bool repeat_default, const int volume_default, const bool caps_default, const bool shift_inv)
{
    this->theme_ = theme;
    this->repeat_def_ = repeat_default;
    this->volume_def_ = volume_default;
    this->caps_def_ = caps_default;
    this->shift_inv_ = shift_inv;
}

QString Properties::GetTheme() const
{
    return this->theme_;
}

bool Properties::GetRepeat() const
{
    return this->repeat_def_;
}

int Properties::GetVolume() const
{
    return this->volume_def_;
}

bool Properties::GetCaps() const
{
    return this->caps_def_;
}

bool Properties::GetShift() const
{
    return this->shift_inv_;
}

QPalette Properties::GetPalette() const
{
    if (this->GetTheme() == "Dark")
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

    if (this->GetTheme() == "Default")
    {
        return QApplication::style()->standardPalette();
    }

    if (this->GetTheme() == "Calibri")
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

    if (this->GetTheme() == "Union")
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

bool Properties::IsNull()
{
    return false;
}

void Properties::SaveProperties() const
{
	QString name = QApplication::applicationDirPath() + "/prop.kps";
    if (name.isEmpty())
    {
        return;
    }
    FILE *file = fopen(name.toLatin1().data(), "w+b");
    if (!file)
    {
        return;
    }
    fwrite(&(this->shift_inv_), sizeof(bool),1,file);
    fwrite(&(this->caps_def_), sizeof(bool),1,file);
    fwrite(&(this->volume_def_), sizeof(int),1,file);
    fwrite(&(this->repeat_def_), sizeof(bool),1,file);

    const char *str = this->theme_.toLatin1().data();
    fwrite(str, sizeof(char), this->theme_.length(), file);
    fwrite("\n", sizeof(char), 1, file);
    fclose(file);
    delete file;
}

Properties* Properties::LoadProperties()
{
	QString name = QApplication::applicationDirPath() + "/prop.kps";
    if (name.isEmpty())
    {
        return new NullProperties();
    }
    FILE *file = fopen(name.toLatin1().data(), "r+b");
    if (!file)
    {
        return new NullProperties();
    }
    bool shift_inv;
    bool caps_def;
    int volume_def;
    bool repeat_def;
    fread(&shift_inv, sizeof(bool),1,file);
    fread(&caps_def, sizeof(bool),1,file);
    fread(&volume_def, sizeof(int),1,file);
    fread(&repeat_def, sizeof(bool),1,file);
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
    return new Properties(theme, repeat_def, volume_def, caps_def, shift_inv);
}
