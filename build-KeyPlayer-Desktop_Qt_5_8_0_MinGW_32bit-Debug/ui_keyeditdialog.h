/********************************************************************************
** Form generated from reading UI file 'keyeditdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEYEDITDIALOG_H
#define UI_KEYEDITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QKeySequenceEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_KeyEditDialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *pathLabel;
    QLabel *messageLabel;
    QKeySequenceEdit *keySequenceEdit;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *repeatBox;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QHBoxLayout *horizontalLayout;
    QSlider *volumeSlider;
    QVBoxLayout *verticalLayout;
    QLabel *volumeLabel;
    QSpinBox *volumeSpin;

    void setupUi(QDialog *KeyEditDialog)
    {
        if (KeyEditDialog->objectName().isEmpty())
            KeyEditDialog->setObjectName(QStringLiteral("KeyEditDialog"));
        KeyEditDialog->resize(400, 300);
        gridLayout = new QGridLayout(KeyEditDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pathLabel = new QLabel(KeyEditDialog);
        pathLabel->setObjectName(QStringLiteral("pathLabel"));

        horizontalLayout_2->addWidget(pathLabel);

        messageLabel = new QLabel(KeyEditDialog);
        messageLabel->setObjectName(QStringLiteral("messageLabel"));

        horizontalLayout_2->addWidget(messageLabel);

        keySequenceEdit = new QKeySequenceEdit(KeyEditDialog);
        keySequenceEdit->setObjectName(QStringLiteral("keySequenceEdit"));

        horizontalLayout_2->addWidget(keySequenceEdit);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        repeatBox = new QCheckBox(KeyEditDialog);
        repeatBox->setObjectName(QStringLiteral("repeatBox"));

        horizontalLayout_3->addWidget(repeatBox);

        okButton = new QPushButton(KeyEditDialog);
        okButton->setObjectName(QStringLiteral("okButton"));

        horizontalLayout_3->addWidget(okButton);

        cancelButton = new QPushButton(KeyEditDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout_3->addWidget(cancelButton);


        verticalLayout_2->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        volumeSlider = new QSlider(KeyEditDialog);
        volumeSlider->setObjectName(QStringLiteral("volumeSlider"));
        volumeSlider->setMaximum(100);
        volumeSlider->setValue(100);
        volumeSlider->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(volumeSlider);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        volumeLabel = new QLabel(KeyEditDialog);
        volumeLabel->setObjectName(QStringLiteral("volumeLabel"));

        verticalLayout->addWidget(volumeLabel);

        volumeSpin = new QSpinBox(KeyEditDialog);
        volumeSpin->setObjectName(QStringLiteral("volumeSpin"));
        volumeSpin->setMaximum(100);
        volumeSpin->setValue(100);

        verticalLayout->addWidget(volumeSpin);


        horizontalLayout->addLayout(verticalLayout);


        horizontalLayout_4->addLayout(horizontalLayout);


        gridLayout->addLayout(horizontalLayout_4, 0, 0, 1, 1);


        retranslateUi(KeyEditDialog);
        QObject::connect(volumeSlider, SIGNAL(valueChanged(int)), volumeSpin, SLOT(setValue(int)));
        QObject::connect(volumeSpin, SIGNAL(valueChanged(int)), volumeSlider, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(KeyEditDialog);
    } // setupUi

    void retranslateUi(QDialog *KeyEditDialog)
    {
        KeyEditDialog->setWindowTitle(QApplication::translate("KeyEditDialog", "Dialog", Q_NULLPTR));
        pathLabel->setText(QApplication::translate("KeyEditDialog", "path:", Q_NULLPTR));
        messageLabel->setText(QApplication::translate("KeyEditDialog", "Press Key:", Q_NULLPTR));
        repeatBox->setText(QApplication::translate("KeyEditDialog", "repeat", Q_NULLPTR));
        okButton->setText(QApplication::translate("KeyEditDialog", "&OK", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("KeyEditDialog", "&Cancel", Q_NULLPTR));
        volumeLabel->setText(QApplication::translate("KeyEditDialog", "Volume:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class KeyEditDialog: public Ui_KeyEditDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEYEDITDIALOG_H
