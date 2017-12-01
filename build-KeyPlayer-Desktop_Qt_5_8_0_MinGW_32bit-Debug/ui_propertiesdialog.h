/********************************************************************************
** Form generated from reading UI file 'propertiesdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROPERTIESDIALOG_H
#define UI_PROPERTIESDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PropertiesDialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *themeLabel;
    QComboBox *themeComboBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *repeatLabel;
    QCheckBox *repeatCheckBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *volumeLabel;
    QSlider *volumeSlider;
    QSpinBox *volumeSpinBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *capsLabel;
    QCheckBox *capsCheckBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *shiftLabel;
    QCheckBox *shiftCheckBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *PropertiesDialog)
    {
        if (PropertiesDialog->objectName().isEmpty())
            PropertiesDialog->setObjectName(QStringLiteral("PropertiesDialog"));
        PropertiesDialog->resize(400, 300);
        gridLayout = new QGridLayout(PropertiesDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        themeLabel = new QLabel(PropertiesDialog);
        themeLabel->setObjectName(QStringLiteral("themeLabel"));

        horizontalLayout->addWidget(themeLabel);

        themeComboBox = new QComboBox(PropertiesDialog);
        themeComboBox->setObjectName(QStringLiteral("themeComboBox"));

        horizontalLayout->addWidget(themeComboBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        repeatLabel = new QLabel(PropertiesDialog);
        repeatLabel->setObjectName(QStringLiteral("repeatLabel"));

        horizontalLayout_2->addWidget(repeatLabel);

        repeatCheckBox = new QCheckBox(PropertiesDialog);
        repeatCheckBox->setObjectName(QStringLiteral("repeatCheckBox"));

        horizontalLayout_2->addWidget(repeatCheckBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        volumeLabel = new QLabel(PropertiesDialog);
        volumeLabel->setObjectName(QStringLiteral("volumeLabel"));

        horizontalLayout_3->addWidget(volumeLabel);

        volumeSlider = new QSlider(PropertiesDialog);
        volumeSlider->setObjectName(QStringLiteral("volumeSlider"));
        volumeSlider->setMaximum(100);
        volumeSlider->setValue(100);
        volumeSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(volumeSlider);

        volumeSpinBox = new QSpinBox(PropertiesDialog);
        volumeSpinBox->setObjectName(QStringLiteral("volumeSpinBox"));
        volumeSpinBox->setMaximum(100);

        horizontalLayout_3->addWidget(volumeSpinBox);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        capsLabel = new QLabel(PropertiesDialog);
        capsLabel->setObjectName(QStringLiteral("capsLabel"));

        horizontalLayout_4->addWidget(capsLabel);

        capsCheckBox = new QCheckBox(PropertiesDialog);
        capsCheckBox->setObjectName(QStringLiteral("capsCheckBox"));

        horizontalLayout_4->addWidget(capsCheckBox);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        shiftLabel = new QLabel(PropertiesDialog);
        shiftLabel->setObjectName(QStringLiteral("shiftLabel"));

        horizontalLayout_5->addWidget(shiftLabel);

        shiftCheckBox = new QCheckBox(PropertiesDialog);
        shiftCheckBox->setObjectName(QStringLiteral("shiftCheckBox"));

        horizontalLayout_5->addWidget(shiftCheckBox);


        verticalLayout->addLayout(horizontalLayout_5);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(PropertiesDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(PropertiesDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), PropertiesDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), PropertiesDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(PropertiesDialog);
    } // setupUi

    void retranslateUi(QDialog *PropertiesDialog)
    {
        PropertiesDialog->setWindowTitle(QApplication::translate("PropertiesDialog", "Dialog", Q_NULLPTR));
        themeLabel->setText(QApplication::translate("PropertiesDialog", "Theme", Q_NULLPTR));
        themeComboBox->setCurrentText(QString());
        repeatLabel->setText(QApplication::translate("PropertiesDialog", "repeat Default", Q_NULLPTR));
        repeatCheckBox->setText(QString());
        volumeLabel->setText(QApplication::translate("PropertiesDialog", "Volume Default", Q_NULLPTR));
        capsLabel->setText(QApplication::translate("PropertiesDialog", "CapsLock", Q_NULLPTR));
        capsCheckBox->setText(QString());
        shiftLabel->setText(QApplication::translate("PropertiesDialog", "Shift inverse with Caps", Q_NULLPTR));
        shiftCheckBox->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PropertiesDialog: public Ui_PropertiesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROPERTIESDIALOG_H
