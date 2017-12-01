#ifndef PROPERTIES_H
#define PROPERTIES_H

#include <QObject>
#include <QPalette>

class Properties : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Properties - class of saved properties of all application
     * @param parent - the parent Object of window
     */
    explicit Properties(QObject *parent = nullptr);

    /**
     * @brief Properties - creating new Properties object with all properties of all application
     * @param theme - the name of choosing theme
     * @param repeat_default - the default repeating flag
     * @param volume_default - the default volume of music file
     * @param caps_default - the default value of CapsLock
     * @param shift_inv - inverse logic of Shift key
     */
    Properties(QString theme, bool repeat_default, int volume_default, bool caps_default, bool shift_inv);

    /**
     * @brief getTheme - getting the name of choosed theme
     * - "Default" - the default theme
     * - "Calibri" - the theme with blue and green color as base
     * - "Dark" - the theme with dark colors
     * - "Union" - the theme with red color as base
     * @return name of the theme
     */
    QString GetTheme() const;

    /**
     * @brief getRepeat - getting the repeating settings (starting repeating flag of key_edit_dialog)
     * @return default repeating flag
     */
    bool GetRepeat() const;

    /**
     * @brief getVolume - getting the value of volume (starting volume of KeyEdit Dialog)
     * @return default volume
     */
    int GetVolume() const;

    /**
     * @brief getCaps - getting default caps state (state of CapsLock when PlayWindow was run)
     * @return default CapsLock state
     */
    bool GetCaps() const;

    /**
     * @brief getShift - getting default ShiftInverse flag (the logic of Shift key when CapsLock was activated)
     * @return enable shift inverse
     */
    bool GetShift() const;

    /**
     * @brief getPalette - getting Palette for choosing theme of all application
     * @return QPalette with all colors for choosed theme
     */
    QPalette GetPalette() const;

    /**
     * @brief isNull - compare with default properties class (NullProperties)
     * @return true
     */
    virtual bool IsNull();

    /**
     * @brief saveProperties - saving current parametres in file (./prop.kps) in next fprmat:
     * [shiftInverse(bool)]x1  [capsDefault(bool)]x1 [volumeDefault(int)]x4 [repeatDefault(bool)]x1 [theme(QString)]xlen ["\n"(char)]x1
     * []: byte
     * []xA -> A: count of bytes
     */
    void SaveProperties() const;

    /**
     * @brief loadProperties - loading properties from file (./prop.kps) in next format
     * [shiftInverse(bool)]x1  [capsDefault(bool)]x1 [volumeDefault(int)]x4 [repeatDefault(bool)]x1 [theme(QString)]xlen ["\n"(char)]x1
     * []: byte
     * []xA -> A: count of bytes
     * If loading was failed return new NullProperties with default properties
     * @return the object of Properties when loading was successed
     *               the object of NullProperties with default properties when loading was failed
     */
    static Properties* LoadProperties();
signals:

public slots:
protected:
    QString theme_;
    bool repeat_def_;
    int volume_def_;
    bool caps_def_;
    bool shift_inv_;
};

#endif // PROPERTIES_H
