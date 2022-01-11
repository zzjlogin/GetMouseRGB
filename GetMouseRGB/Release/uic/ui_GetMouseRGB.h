/********************************************************************************
** Form generated from reading UI file 'GetMouseRGB.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GETMOUSERGB_H
#define UI_GETMOUSERGB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GetMouseRGBClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GetMouseRGBClass)
    {
        if (GetMouseRGBClass->objectName().isEmpty())
            GetMouseRGBClass->setObjectName(QString::fromUtf8("GetMouseRGBClass"));
        GetMouseRGBClass->resize(600, 400);
        menuBar = new QMenuBar(GetMouseRGBClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        GetMouseRGBClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GetMouseRGBClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        GetMouseRGBClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(GetMouseRGBClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        GetMouseRGBClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(GetMouseRGBClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        GetMouseRGBClass->setStatusBar(statusBar);

        retranslateUi(GetMouseRGBClass);

        QMetaObject::connectSlotsByName(GetMouseRGBClass);
    } // setupUi

    void retranslateUi(QMainWindow *GetMouseRGBClass)
    {
        GetMouseRGBClass->setWindowTitle(QApplication::translate("GetMouseRGBClass", "GetMouseRGB", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GetMouseRGBClass: public Ui_GetMouseRGBClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GETMOUSERGB_H
