#ifndef PROPERTIESDIALOG_H
#define PROPERTIESDIALOG_H

#include <QDialog>
#include "properties.h"

namespace Ui {
class PropertiesDialog;
}

/**
 * @brief The PropertiesDialog class class of window for changing default settings of application
 */
class PropertiesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PropertiesDialog(QWidget *parent = 0);
    ~PropertiesDialog();

private slots:
    /**
     * @brief on_buttonBox_accepted action, when OKbutton was pressed. Send signal with setted properties to main window
     */
    void on_buttonBox_accepted();

    /**
     * @brief on_volumeSpinBox_valueChanged action, when volumeSpinBox was changed. Change value of volumeSlider
     * @param arg1
     */
    void on_volumeSpinBox_valueChanged(int arg1);

    /**
     * @brief on_volumeSlider_valueChanged action, when volumeSlider was changed. Change value of volumeSpinBox
     * @param value
     */
    void on_volumeSlider_valueChanged(int value);

signals:
    /**
     * @brief changeProperties signal when properties was accepted
     * @param prop object of Properties with all default values
     */
    void changeProperties(Properties* prop);

private:
    /**
     * @brief getTheme getting theme from themeComboBox
     * @return name of choosed theme
     */
    QString getTheme();

    /**
     * @brief getRepeat getting flag of repeating from repeatCheckBox
     * @return choosed repeat flag as default
     */
    bool getRepeat();

    /**
     * @brief getVolume getting choosed default volume value from volumeSpinBox
     * @return value of default volume
     */
    int getVolume();

    /**
     * @brief getCaps getting flag of CapsLock from capsCheckBox
     * @return choosed capsLock flag as default
     */
    bool getCaps();

    /**
     * @brief getShift getting flag of shift inverse from shiftInverseCheckBox
     * @return choosed shiftInverse flag as default
     */
    bool getShift();

    Ui::PropertiesDialog *ui;
};

#endif // PROPERTIESDIALOG_H
