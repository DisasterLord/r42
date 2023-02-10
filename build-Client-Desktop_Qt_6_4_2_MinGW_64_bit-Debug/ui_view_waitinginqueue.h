/********************************************************************************
** Form generated from reading UI file 'view_waitinginqueue.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEW_WAITINGINQUEUE_H
#define UI_VIEW_WAITINGINQUEUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_view_waitinginqueue
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *view_waitinginqueue)
    {
        if (view_waitinginqueue->objectName().isEmpty())
            view_waitinginqueue->setObjectName("view_waitinginqueue");
        view_waitinginqueue->resize(400, 300);
        buttonBox = new QDialogButtonBox(view_waitinginqueue);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(view_waitinginqueue);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, view_waitinginqueue, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, view_waitinginqueue, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(view_waitinginqueue);
    } // setupUi

    void retranslateUi(QDialog *view_waitinginqueue)
    {
        view_waitinginqueue->setWindowTitle(QCoreApplication::translate("view_waitinginqueue", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class view_waitinginqueue: public Ui_view_waitinginqueue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEW_WAITINGINQUEUE_H
