/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionSave;
    QAction *actionOpen;
    QAction *actionExit;
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QHBoxLayout *framesListView;
    QGraphicsView *prevFrameView;
    QGraphicsView *currFrameView;
    QGraphicsView *nextFrameView;
    QGraphicsView *editFrameView;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Downloads/AddFile.png"), QSize(), QIcon::Normal, QIcon::On);
        actionNew->setIcon(icon);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Downloads/SaveIcon.png"), QSize(), QIcon::Normal, QIcon::On);
        actionSave->setIcon(icon1);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Downloads/OpenIcon.png"), QSize(), QIcon::Normal, QIcon::On);
        actionOpen->setIcon(icon2);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Downloads/CloseIcon.png"), QSize(), QIcon::Normal, QIcon::On);
        actionExit->setIcon(icon3);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(120, 420, 471, 121));
        framesListView = new QHBoxLayout(layoutWidget);
        framesListView->setObjectName(QString::fromUtf8("framesListView"));
        framesListView->setContentsMargins(0, 0, 0, 0);
        prevFrameView = new QGraphicsView(layoutWidget);
        prevFrameView->setObjectName(QString::fromUtf8("prevFrameView"));

        framesListView->addWidget(prevFrameView);

        currFrameView = new QGraphicsView(layoutWidget);
        currFrameView->setObjectName(QString::fromUtf8("currFrameView"));

        framesListView->addWidget(currFrameView);

        nextFrameView = new QGraphicsView(layoutWidget);
        nextFrameView->setObjectName(QString::fromUtf8("nextFrameView"));

        framesListView->addWidget(nextFrameView);

        editFrameView = new QGraphicsView(centralwidget);
        editFrameView->setObjectName(QString::fromUtf8("editFrameView"));
        editFrameView->setGeometry(QRect(120, 20, 471, 391));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 17));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "New", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
