/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QListView *listView;
    QHBoxLayout *horizontalLayout;
    QCheckBox *CheckBoxListAndIcon;
    QPushButton *pushButtonUp;
    QPushButton *pushButtonDown;
    QPushButton *pushButtonDel;
    QPushButton *pushButtonAdd;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(518, 273);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 495, 253));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listView = new QListView(layoutWidget);
        listView->setObjectName(QString::fromUtf8("listView"));

        verticalLayout->addWidget(listView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        CheckBoxListAndIcon = new QCheckBox(layoutWidget);
        CheckBoxListAndIcon->setObjectName(QString::fromUtf8("CheckBoxListAndIcon"));

        horizontalLayout->addWidget(CheckBoxListAndIcon);

        pushButtonUp = new QPushButton(layoutWidget);
        pushButtonUp->setObjectName(QString::fromUtf8("pushButtonUp"));

        horizontalLayout->addWidget(pushButtonUp);

        pushButtonDown = new QPushButton(layoutWidget);
        pushButtonDown->setObjectName(QString::fromUtf8("pushButtonDown"));

        horizontalLayout->addWidget(pushButtonDown);

        pushButtonDel = new QPushButton(layoutWidget);
        pushButtonDel->setObjectName(QString::fromUtf8("pushButtonDel"));

        horizontalLayout->addWidget(pushButtonDel);

        pushButtonAdd = new QPushButton(layoutWidget);
        pushButtonAdd->setObjectName(QString::fromUtf8("pushButtonAdd"));

        horizontalLayout->addWidget(pushButtonAdd);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_2->addWidget(pushButton);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        CheckBoxListAndIcon->setText(QApplication::translate("MainWindow", "list/icon", nullptr));
        pushButtonUp->setText(QApplication::translate("MainWindow", "up", nullptr));
        pushButtonDown->setText(QApplication::translate("MainWindow", "down", nullptr));
        pushButtonDel->setText(QApplication::translate("MainWindow", "del", nullptr));
        pushButtonAdd->setText(QApplication::translate("MainWindow", "add", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "tsk3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
