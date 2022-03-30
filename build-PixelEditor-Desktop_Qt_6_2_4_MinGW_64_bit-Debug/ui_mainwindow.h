/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
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
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *brushButton;
    QPushButton *eraserButton;
    QPushButton *bucketButton;
    QPushButton *colorPickerButton;
    QPushButton *selectButton;
    QWidget *widget;
    QPushButton *swapColorButton;
    QPushButton *primaryColorButton;
    QPushButton *secondaryColorButton;
    QListWidget *framesListWidget;
    QLabel *editDrawingWindow;
    QPushButton *btnTest;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(763, 600);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icons/AddFile.png"), QSize(), QIcon::Normal, QIcon::On);
        actionNew->setIcon(icon);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Icons/SaveIcon.png"), QSize(), QIcon::Normal, QIcon::On);
        actionSave->setIcon(icon1);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Icons/OpenIcon.png"), QSize(), QIcon::Normal, QIcon::On);
        actionOpen->setIcon(icon2);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Icons/CloseIcon.png"), QSize(), QIcon::Normal, QIcon::On);
        actionExit->setIcon(icon3);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 20, 85, 512));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(verticalLayoutWidget->sizePolicy().hasHeightForWidth());
        verticalLayoutWidget->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        brushButton = new QPushButton(verticalLayoutWidget);
        brushButton->setObjectName(QString::fromUtf8("brushButton"));
        sizePolicy.setHeightForWidth(brushButton->sizePolicy().hasHeightForWidth());
        brushButton->setSizePolicy(sizePolicy);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Icons/icons8-paint-96.png"), QSize(), QIcon::Normal, QIcon::Off);
        brushButton->setIcon(icon4);
        brushButton->setIconSize(QSize(70, 70));
        brushButton->setCheckable(true);
        brushButton->setChecked(true);

        verticalLayout->addWidget(brushButton);

        eraserButton = new QPushButton(verticalLayoutWidget);
        eraserButton->setObjectName(QString::fromUtf8("eraserButton"));
        sizePolicy.setHeightForWidth(eraserButton->sizePolicy().hasHeightForWidth());
        eraserButton->setSizePolicy(sizePolicy);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Icons/icons8-erase-96.png"), QSize(), QIcon::Normal, QIcon::Off);
        eraserButton->setIcon(icon5);
        eraserButton->setIconSize(QSize(70, 70));
        eraserButton->setCheckable(true);

        verticalLayout->addWidget(eraserButton);

        bucketButton = new QPushButton(verticalLayoutWidget);
        bucketButton->setObjectName(QString::fromUtf8("bucketButton"));
        sizePolicy.setHeightForWidth(bucketButton->sizePolicy().hasHeightForWidth());
        bucketButton->setSizePolicy(sizePolicy);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Icons/icons8-fill-color-96.png"), QSize(), QIcon::Normal, QIcon::Off);
        bucketButton->setIcon(icon6);
        bucketButton->setIconSize(QSize(70, 70));
        bucketButton->setCheckable(true);

        verticalLayout->addWidget(bucketButton);

        colorPickerButton = new QPushButton(verticalLayoutWidget);
        colorPickerButton->setObjectName(QString::fromUtf8("colorPickerButton"));
        sizePolicy.setHeightForWidth(colorPickerButton->sizePolicy().hasHeightForWidth());
        colorPickerButton->setSizePolicy(sizePolicy);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/Icons/icons8-color-dropper-96.png"), QSize(), QIcon::Normal, QIcon::Off);
        colorPickerButton->setIcon(icon7);
        colorPickerButton->setIconSize(QSize(70, 70));
        colorPickerButton->setCheckable(true);

        verticalLayout->addWidget(colorPickerButton);

        selectButton = new QPushButton(verticalLayoutWidget);
        selectButton->setObjectName(QString::fromUtf8("selectButton"));
        sizePolicy.setHeightForWidth(selectButton->sizePolicy().hasHeightForWidth());
        selectButton->setSizePolicy(sizePolicy);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/Icons/icons8-select-all-96.png"), QSize(), QIcon::Normal, QIcon::Off);
        selectButton->setIcon(icon8);
        selectButton->setIconSize(QSize(70, 70));
        selectButton->setCheckable(true);

        verticalLayout->addWidget(selectButton);

        widget = new QWidget(verticalLayoutWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        widget->setMinimumSize(QSize(80, 80));
        swapColorButton = new QPushButton(widget);
        swapColorButton->setObjectName(QString::fromUtf8("swapColorButton"));
        swapColorButton->setGeometry(QRect(0, 50, 31, 31));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/Icons/icons8-curved-arrow-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        swapColorButton->setIcon(icon9);
        swapColorButton->setFlat(true);
        primaryColorButton = new QPushButton(widget);
        primaryColorButton->setObjectName(QString::fromUtf8("primaryColorButton"));
        primaryColorButton->setGeometry(QRect(0, 0, 50, 50));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(primaryColorButton->sizePolicy().hasHeightForWidth());
        primaryColorButton->setSizePolicy(sizePolicy2);
        primaryColorButton->setMinimumSize(QSize(50, 50));
        primaryColorButton->setStyleSheet(QString::fromUtf8("QPushButton#primaryColorButton {\n"
"    background-color: red;\n"
"	border-style: none;\n"
"}"));
        primaryColorButton->setFlat(false);
        secondaryColorButton = new QPushButton(widget);
        secondaryColorButton->setObjectName(QString::fromUtf8("secondaryColorButton"));
        secondaryColorButton->setGeometry(QRect(30, 30, 50, 50));
        sizePolicy2.setHeightForWidth(secondaryColorButton->sizePolicy().hasHeightForWidth());
        secondaryColorButton->setSizePolicy(sizePolicy2);
        secondaryColorButton->setStyleSheet(QString::fromUtf8("QPushButton#secondaryColorButton {\n"
"    background-color: white;\n"
"	border-style: none;\n"
"}"));
        swapColorButton->raise();
        secondaryColorButton->raise();
        primaryColorButton->raise();

        verticalLayout->addWidget(widget);

        framesListWidget = new QListWidget(centralwidget);
        framesListWidget->setObjectName(QString::fromUtf8("framesListWidget"));
        framesListWidget->setGeometry(QRect(120, 421, 471, 101));
        sizePolicy.setHeightForWidth(framesListWidget->sizePolicy().hasHeightForWidth());
        framesListWidget->setSizePolicy(sizePolicy);
        editDrawingWindow = new QLabel(centralwidget);
        editDrawingWindow->setObjectName(QString::fromUtf8("editDrawingWindow"));
        editDrawingWindow->setGeometry(QRect(120, 20, 471, 391));
        editDrawingWindow->setAutoFillBackground(true);
        editDrawingWindow->setFrameShape(QFrame::Box);
        editDrawingWindow->setAlignment(Qt::AlignCenter);
        btnTest = new QPushButton(centralwidget);
        btnTest->setObjectName(QString::fromUtf8("btnTest"));
        btnTest->setGeometry(QRect(620, 30, 80, 18));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 763, 26));
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
#if QT_CONFIG(tooltip)
        verticalLayoutWidget->setToolTip(QCoreApplication::translate("MainWindow", "Select Tool", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        verticalLayoutWidget->setAccessibleName(QCoreApplication::translate("MainWindow", "Select Tool", nullptr));
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(tooltip)
        brushButton->setToolTip(QCoreApplication::translate("MainWindow", "Brush Tool", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        brushButton->setAccessibleName(QCoreApplication::translate("MainWindow", "Brush Tool", nullptr));
#endif // QT_CONFIG(accessibility)
        brushButton->setText(QString());
#if QT_CONFIG(tooltip)
        eraserButton->setToolTip(QCoreApplication::translate("MainWindow", "Eraser Tool", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        eraserButton->setAccessibleName(QCoreApplication::translate("MainWindow", "Eraser Tool", nullptr));
#endif // QT_CONFIG(accessibility)
        eraserButton->setText(QString());
#if QT_CONFIG(tooltip)
        bucketButton->setToolTip(QCoreApplication::translate("MainWindow", "Bucket Tool", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        bucketButton->setAccessibleName(QCoreApplication::translate("MainWindow", "Bucket Tool", nullptr));
#endif // QT_CONFIG(accessibility)
        bucketButton->setText(QString());
#if QT_CONFIG(tooltip)
        colorPickerButton->setToolTip(QCoreApplication::translate("MainWindow", "Color Picker Tool", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        colorPickerButton->setAccessibleName(QCoreApplication::translate("MainWindow", "Color Picker Tool", nullptr));
#endif // QT_CONFIG(accessibility)
        colorPickerButton->setText(QString());
#if QT_CONFIG(tooltip)
        selectButton->setToolTip(QCoreApplication::translate("MainWindow", "Select Tool", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        selectButton->setAccessibleName(QCoreApplication::translate("MainWindow", "Select Tool", nullptr));
#endif // QT_CONFIG(accessibility)
        selectButton->setText(QString());
#if QT_CONFIG(tooltip)
        widget->setToolTip(QCoreApplication::translate("MainWindow", "Select Tool", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        widget->setAccessibleName(QCoreApplication::translate("MainWindow", "Select Tool", nullptr));
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(tooltip)
        swapColorButton->setToolTip(QCoreApplication::translate("MainWindow", "Swap Colors", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        swapColorButton->setAccessibleName(QCoreApplication::translate("MainWindow", "Swap Colors", nullptr));
#endif // QT_CONFIG(accessibility)
        swapColorButton->setText(QString());
#if QT_CONFIG(tooltip)
        primaryColorButton->setToolTip(QCoreApplication::translate("MainWindow", "Primary Color", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        primaryColorButton->setAccessibleName(QCoreApplication::translate("MainWindow", "Primary Color", nullptr));
#endif // QT_CONFIG(accessibility)
        primaryColorButton->setText(QString());
#if QT_CONFIG(tooltip)
        secondaryColorButton->setToolTip(QCoreApplication::translate("MainWindow", "Secondary Color", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        secondaryColorButton->setAccessibleName(QCoreApplication::translate("MainWindow", "Secondary Color", nullptr));
#endif // QT_CONFIG(accessibility)
        secondaryColorButton->setText(QString());
#if QT_CONFIG(tooltip)
        framesListWidget->setToolTip(QCoreApplication::translate("MainWindow", "Select Tool", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        framesListWidget->setAccessibleName(QCoreApplication::translate("MainWindow", "Select Tool", nullptr));
#endif // QT_CONFIG(accessibility)
        editDrawingWindow->setText(QString());
        btnTest->setText(QCoreApplication::translate("MainWindow", "New", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
