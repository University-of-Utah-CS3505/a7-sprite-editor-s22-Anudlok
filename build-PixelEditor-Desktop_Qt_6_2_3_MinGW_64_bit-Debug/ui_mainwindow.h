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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
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
    QAction *actionCredits;
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *brushButton;
    QPushButton *eraserButton;
    QPushButton *bucketButton;
    QPushButton *colorPickerButton;
    QWidget *widget;
    QPushButton *swapColorButton;
    QPushButton *primaryColorButton;
    QPushButton *secondaryColorButton;
    QListWidget *framesListWidget;
    QLabel *editDrawingWindow;
    QPushButton *playPreviewButton;
    QPushButton *deleteFrameButton;
    QPushButton *addFrameButton;
    QPushButton *frameUpButton;
    QPushButton *frameDownButton;
    QSpinBox *fpsSpinBox;
    QLabel *fpsLabel;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuCredits;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(731, 587);
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
        actionCredits = new QAction(MainWindow);
        actionCredits->setObjectName(QString::fromUtf8("actionCredits"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 20, 106, 441));
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
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/Icons/icons8-curved-arrows-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        swapColorButton->setIcon(icon8);
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
"    background-color: black;\n"
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
        framesListWidget->setEnabled(true);
        framesListWidget->setGeometry(QRect(540, 200, 141, 321));
        sizePolicy.setHeightForWidth(framesListWidget->sizePolicy().hasHeightForWidth());
        framesListWidget->setSizePolicy(sizePolicy);
        editDrawingWindow = new QLabel(centralwidget);
        editDrawingWindow->setObjectName(QString::fromUtf8("editDrawingWindow"));
        editDrawingWindow->setGeometry(QRect(140, 20, 384, 384));
        editDrawingWindow->setAutoFillBackground(true);
        editDrawingWindow->setFrameShape(QFrame::Box);
        editDrawingWindow->setAlignment(Qt::AlignCenter);
        playPreviewButton = new QPushButton(centralwidget);
        playPreviewButton->setObjectName(QString::fromUtf8("playPreviewButton"));
        playPreviewButton->setGeometry(QRect(120, 430, 81, 81));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/Icons/icons8-circled-play-96.png"), QSize(), QIcon::Normal, QIcon::Off);
        playPreviewButton->setIcon(icon9);
        playPreviewButton->setIconSize(QSize(60, 60));
        deleteFrameButton = new QPushButton(centralwidget);
        deleteFrameButton->setObjectName(QString::fromUtf8("deleteFrameButton"));
        deleteFrameButton->setGeometry(QRect(390, 430, 81, 81));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/Icons/icons8-remove-image-96.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteFrameButton->setIcon(icon10);
        deleteFrameButton->setIconSize(QSize(60, 60));
        addFrameButton = new QPushButton(centralwidget);
        addFrameButton->setObjectName(QString::fromUtf8("addFrameButton"));
        addFrameButton->setGeometry(QRect(310, 430, 81, 81));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/Icons/icons8-add-image-96.png"), QSize(), QIcon::Normal, QIcon::Off);
        addFrameButton->setIcon(icon11);
        addFrameButton->setIconSize(QSize(60, 60));
        frameUpButton = new QPushButton(centralwidget);
        frameUpButton->setObjectName(QString::fromUtf8("frameUpButton"));
        frameUpButton->setGeometry(QRect(480, 420, 51, 51));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/Icons/icons8-sort-up-96.png"), QSize(), QIcon::Normal, QIcon::Off);
        frameUpButton->setIcon(icon12);
        frameUpButton->setIconSize(QSize(50, 50));
        frameDownButton = new QPushButton(centralwidget);
        frameDownButton->setObjectName(QString::fromUtf8("frameDownButton"));
        frameDownButton->setGeometry(QRect(480, 470, 51, 51));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/Icons/icons8-sort-down-96.png"), QSize(), QIcon::Normal, QIcon::Off);
        frameDownButton->setIcon(icon13);
        frameDownButton->setIconSize(QSize(50, 50));
        fpsSpinBox = new QSpinBox(centralwidget);
        fpsSpinBox->setObjectName(QString::fromUtf8("fpsSpinBox"));
        fpsSpinBox->setGeometry(QRect(210, 480, 71, 22));
        fpsSpinBox->setMinimum(1);
        fpsSpinBox->setMaximum(120);
        fpsLabel = new QLabel(centralwidget);
        fpsLabel->setObjectName(QString::fromUtf8("fpsLabel"));
        fpsLabel->setGeometry(QRect(210, 440, 71, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 731, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuCredits = new QMenu(menubar);
        menuCredits->setObjectName(QString::fromUtf8("menuCredits"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuCredits->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuCredits->addAction(actionCredits);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Pixel Editor", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "New", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionCredits->setText(QCoreApplication::translate("MainWindow", "Credits", nullptr));
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
        framesListWidget->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        framesListWidget->setAccessibleName(QCoreApplication::translate("MainWindow", "Frame List", nullptr));
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(tooltip)
        editDrawingWindow->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        editDrawingWindow->setAccessibleName(QCoreApplication::translate("MainWindow", "Drawing Window", nullptr));
#endif // QT_CONFIG(accessibility)
        editDrawingWindow->setText(QString());
#if QT_CONFIG(tooltip)
        playPreviewButton->setToolTip(QCoreApplication::translate("MainWindow", "Play Preview", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        playPreviewButton->setAccessibleName(QCoreApplication::translate("MainWindow", "Play Preview", nullptr));
#endif // QT_CONFIG(accessibility)
        playPreviewButton->setText(QString());
#if QT_CONFIG(tooltip)
        deleteFrameButton->setToolTip(QCoreApplication::translate("MainWindow", "Delete Frame", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        deleteFrameButton->setAccessibleName(QCoreApplication::translate("MainWindow", "Delete Frame", nullptr));
#endif // QT_CONFIG(accessibility)
        deleteFrameButton->setText(QString());
#if QT_CONFIG(tooltip)
        addFrameButton->setToolTip(QCoreApplication::translate("MainWindow", "Add Frame", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        addFrameButton->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(accessibility)
        addFrameButton->setAccessibleName(QCoreApplication::translate("MainWindow", "Add Frame", nullptr));
#endif // QT_CONFIG(accessibility)
        addFrameButton->setText(QString());
#if QT_CONFIG(tooltip)
        frameUpButton->setToolTip(QCoreApplication::translate("MainWindow", "Move Up a Frame", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        frameUpButton->setAccessibleName(QCoreApplication::translate("MainWindow", "Move Up a Frame", nullptr));
#endif // QT_CONFIG(accessibility)
        frameUpButton->setText(QString());
#if QT_CONFIG(tooltip)
        frameDownButton->setToolTip(QCoreApplication::translate("MainWindow", "Move Down a Frame", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        frameDownButton->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(accessibility)
        frameDownButton->setAccessibleName(QCoreApplication::translate("MainWindow", "Move Down a Frame", nullptr));
#endif // QT_CONFIG(accessibility)
        frameDownButton->setText(QString());
#if QT_CONFIG(tooltip)
        fpsSpinBox->setToolTip(QCoreApplication::translate("MainWindow", "Frames Per Second", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(accessibility)
        fpsSpinBox->setAccessibleName(QCoreApplication::translate("MainWindow", "Frames Per Second Spinbox", nullptr));
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(accessibility)
        fpsLabel->setAccessibleName(QCoreApplication::translate("MainWindow", "Frames Per Second Label", nullptr));
#endif // QT_CONFIG(accessibility)
        fpsLabel->setText(QCoreApplication::translate("MainWindow", "Frames \n"
"Per Second", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuCredits->setTitle(QCoreApplication::translate("MainWindow", "Credits", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
