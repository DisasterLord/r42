/********************************************************************************
** Form generated from reading UI file 'view_multiplayer.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEW_MULTIPLAYER_H
#define UI_VIEW_MULTIPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_view_multiplayer
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *view_multiplayer)
    {
        if (view_multiplayer->objectName().isEmpty())
            view_multiplayer->setObjectName("view_multiplayer");
        view_multiplayer->resize(400, 300);
        buttonBox = new QDialogButtonBox(view_multiplayer);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(view_multiplayer);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, view_multiplayer, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, view_multiplayer, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(view_multiplayer);
    } // setupUi

    void retranslateUi(QDialog *view_multiplayer)
    {
        view_multiplayer->setWindowTitle(QCoreApplication::translate("view_multiplayer", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class view_multiplayer: public Ui_view_multiplayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEW_MULTIPLAYER_H
