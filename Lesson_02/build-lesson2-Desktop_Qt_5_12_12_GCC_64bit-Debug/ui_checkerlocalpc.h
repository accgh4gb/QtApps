/********************************************************************************
** Form generated from reading UI file 'checkerlocalpc.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKERLOCALPC_H
#define UI_CHECKERLOCALPC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CheckerLocalPC
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QTableView *tableView;
    QTableWidget *tableAdress;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButtonCheckAdr;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *CheckerLocalPC)
    {
        if (CheckerLocalPC->objectName().isEmpty())
            CheckerLocalPC->setObjectName(QString::fromUtf8("CheckerLocalPC"));
        CheckerLocalPC->resize(571, 303);
        layoutWidget = new QWidget(CheckerLocalPC);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 551, 281));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        tableView = new QTableView(layoutWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        horizontalLayout_2->addWidget(tableView);

        tableAdress = new QTableWidget(layoutWidget);
        tableAdress->setObjectName(QString::fromUtf8("tableAdress"));

        horizontalLayout_2->addWidget(tableAdress);

        horizontalLayout_2->setStretch(0, 6);
        horizontalLayout_2->setStretch(1, 4);

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButtonCheckAdr = new QPushButton(layoutWidget);
        pushButtonCheckAdr->setObjectName(QString::fromUtf8("pushButtonCheckAdr"));

        horizontalLayout->addWidget(pushButtonCheckAdr);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(CheckerLocalPC);

        QMetaObject::connectSlotsByName(CheckerLocalPC);
    } // setupUi

    void retranslateUi(QDialog *CheckerLocalPC)
    {
        CheckerLocalPC->setWindowTitle(QApplication::translate("CheckerLocalPC", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("CheckerLocalPC", "apply", nullptr));
        pushButtonCheckAdr->setText(QApplication::translate("CheckerLocalPC", "chekAdressPS", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CheckerLocalPC: public Ui_CheckerLocalPC {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKERLOCALPC_H
