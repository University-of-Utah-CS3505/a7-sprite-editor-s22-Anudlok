/************************************************
 * DrawingWindow class
 * Class definition for displaying the main
 * window which displays all the widget.
 * @author: Anna Timofeyenko, Gabby Culley,
 *          Gaby Torres, Raynard Christian
 * @date: 4/5/2022
************************************************/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "QtWidgets/qlistwidget.h"
#include "drawingwindowwidget.h"
#include "previewwindow.h"
#include "animationpopup.h"
#include "./ui_animationpopup.h"
#include "frames.h"
#include "toolbar.h"

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
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    std::vector<QListWidgetItem> widgetList;

signals:
    // New file signal
    void makeNewFrame(int width, int height);

    // Frame button signals
    void addFrame();
    void deleteFrame();
    void moveCurrFrame(bool isUp);
    void selectFrame(int index);

    // File menu signals
    void saveFile(QString fileName);
    void loadFile(QString fileName);
    void newFile(int width, int height);
    void saveAndNewFile(QString filename, int width, int height);

    // DELETE THESE
    void currentColor(QColor color);
    void colorPickerPicked(bool state);
    void bucketPicked(bool);
    void startDrawing();

    // ALSO DELETE
    void newFps(int);

private slots:

    // File menu slots
    void on_actionNew_triggered();
    void on_actionSave_triggered();
    void on_actionOpen_triggered();
    void on_actionExit_triggered();

    // Toolbar slots
    void on_brushButton_clicked();
    void on_eraserButton_clicked();
    void on_bucketButton_clicked();
    void on_colorPickerButton_clicked();
    void on_primaryColorButton_clicked();
    void on_secondaryColorButton_clicked();
    void on_swapColorButton_clicked();

    // Slots for other buttons and spinboxes
    void on_playPreviewButton_clicked();
    void on_fpsSpinBox_valueChanged(int arg1);
    void on_deleteFrameButton_clicked();
    void on_addFrameButton_clicked();
    void on_frameUpButton_clicked();
    void on_frameDownButton_clicked();

    // Drawing window slots
    void displayFrame(QImage* frame);

    // Toolbar slots
    void changePrimaryColor(QColor color);

    // Frame list widget slots
    void addFrameToList(QPixmap *frame, int index);
    void removeFrameFromList(int index);
    void displayInList(QPixmap *frame, int index);
    void clearFrameList();

    void on_actionCredits_triggered();

    void on_framesListWidget_itemPressed(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
    AnimationPopUp *popUp;
    Frames* frames;
    DrawingWindow* dw;
    PreviewWindow* pw;

    enum Tools {
        brush,
        eraser,
        bucket,
        colorPicker
    };

    QColor primaryColor, secondaryColor, eraserColor;

    const int frameItemHeight = 100;

    void selectButton(Tools tool);
};
#endif // MAINWINDOW_H
