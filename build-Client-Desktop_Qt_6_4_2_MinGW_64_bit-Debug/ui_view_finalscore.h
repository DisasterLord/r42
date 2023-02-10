/********************************************************************************
** Form generated from reading UI file 'view_finalscore.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEW_FINALSCORE_H
#define UI_VIEW_FINALSCORE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_view_finalscore
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *view_finalscore)
    {
        if (view_finalscore->objectName().isEmpty())
            view_finalscore->setObjectName("view_finalscore");
        view_finalscore->resize(400, 300);
        buttonBox = new QDialogButtonBox(view_finalscore);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(view_finalscore);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, view_finalscore, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, view_finalscore, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(view_finalscore);
    } // setupUi

    void retranslateUi(QDialog *view_finalscore)
    {
        view_finalscore->setWindowTitle(QCoreApplication::translate("view_finalscore", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class view_finalscore: public Ui_view_finalscore {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEW_FINALSCORE_H
