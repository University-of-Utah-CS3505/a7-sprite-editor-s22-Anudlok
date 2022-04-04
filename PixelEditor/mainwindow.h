#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "QtWidgets/qlistwidget.h"
#include "drawingwindow.h"
#include "drawingwindowwidget.h"
#include "previewwindow.h"
#include "animationpopup.h"
#include "./ui_animationpopup.h"
#include "frames.h"
#include "toolbar.h"
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief The MainWindow class-The view class header file
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(PreviewWindow& pw, Frames& frames, drawingwindow& dw, drawingwindowwidget& dww,
               QWidget *parent = nullptr);
    ~MainWindow();
    std::vector<QListWidgetItem> widgetList;

signals:
    void makeNewFrame(int width, int height);
    void addNewFrame();
    void currentColor(QColor color);
    void colorPickerPicked(bool state);
    void moveCurrFrame(bool isUp);
    void startDrawing();
    //void clearScreen();
    void animateFrames(std::vector<QListWidgetItem> frames);
    void requestFrame();
    void deleteFrame();
    void sendFrame();
    void saveFile(QString fileName);
    void loadFile(QString fileName);
    void newFile(int width, int height);
    void saveAndNewFile(QString filename, int width, int height);
    void resetWindow();
    void newFps(int);
    void bucketPicked(bool);

private slots:

    // File menu slots
    void on_actionNew_triggered();
    void on_actionSave_triggered();
    void on_actionOpen_triggered();
    void on_actionExit_triggered();

    // Button and spinbox slots
    void on_btnTest_clicked(); // TODO remove
    void on_brushButton_clicked();
    void on_eraserButton_clicked();
    void on_bucketButton_clicked();
    void on_colorPickerButton_clicked();
    void on_selectButton_clicked();
    void on_primaryColorButton_clicked();
    void on_secondaryColorButton_clicked();
    void on_swapColorButton_clicked();
    void on_playPreviewButton_clicked();
//    void on_btnClear_clicked(); // TODO remove
    void on_deleteFrameButton_clicked();
    void on_addFrameButton_clicked();
    void on_frameLeftButton_clicked();
    void on_frameRightButton_clicked();
    void on_fpsSpinBox_valueChanged(int arg1);

    // Drawing window slots
    void displayFrame(QImage* frame);

    // Toolbar slots
    void changePrimaryColor(QColor color);

    // Frame list widget slots
    void addFrameToList(QPixmap *frame, int index);
    void removeFrameFromList(int index);
    void displayInList(QPixmap *frame, int index);
    void clearFrameList();

private:
    Ui::MainWindow *ui;
    AnimationPopUp *popUp;
    Toolbar toolbar;
    QColor primaryColor, secondaryColor;
    QColor eraser;
    const int frameItemHeight = 300;
    void selectButton(Toolbar::Tools tool);
};
#endif // MAINWINDOW_H
