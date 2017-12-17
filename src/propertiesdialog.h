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
    explicit PropertiesDialog(QWidget *parent = nullptr);
    ~PropertiesDialog();

private slots:
    /**
     * @brief on_buttonBox_accepted action, when OKbutton was pressed. Send signal with setted properties to main window
     */
    void OnButtonBoxAccepted();

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
    QString GetTheme() const;

    /**
     * @brief getRepeat getting flag of repeating from repeatCheckBox
     * @return choosed repeat flag as default
     */
    bool GetRepeat() const;

    /**
     * @brief getVolume getting choosed default volume value from volumeSpinBox
     * @return value of default volume
     */
    int GetVolume() const;

    /**
     * @brief getCaps getting flag of CapsLock from capsCheckBox
     * @return choosed capsLock flag as default
     */
    bool GetCaps() const;

    /**
     * @brief getShift getting flag of shift inverse from shiftInverseCheckBox
     * @return choosed shiftInverse flag as default
     */
    bool GetShift() const;

    void ButtonsPaint(Properties* prop);

    void Initialize();

    void InitializeButtonsConnections();

    void InitializeSpecificConnections();

    QString RgbToString(QColor);


    Ui::PropertiesDialog *ui_;
};

#endif // PROPERTIESDIALOG_H
