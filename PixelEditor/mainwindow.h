#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "QtWidgets/qlistwidget.h"
#include "drawingwindow.h"
#include "drawingwindowwidget.h"
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
    MainWindow(Frames& frames, drawingwindow& dw, drawingwindowwidget& dww, QWidget *parent = nullptr);
    ~MainWindow();
    std::vector<QImage> frames;
signals:
    void currentFrameChanged(QImage * frame);
    void makeNewFrame(int width, int height);
    void currentColor(QColor color);
    void colorPickerPicked(bool state);
    void startDrawing();
    void clearScreen();

private slots:

    void on_actionNew_triggered();

    void on_actionSave_triggered();

    void on_actionOpen_triggered();

    void on_actionExit_triggered();

   void on_framesListWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_framesListWidget_itemActivated(QListWidgetItem *item);

    void on_btnTest_clicked();
    void displayFrame(QImage* frame);

    void on_brushButton_clicked();

    void on_eraserButton_clicked();

    void on_bucketButton_clicked();

    void on_colorPickerButton_clicked();

    void on_selectButton_clicked();

    void on_primaryColorButton_clicked();

    void on_secondaryColorButton_clicked();

    void on_swapColorButton_clicked();

    void on_playPreviewButton_clicked();
    void changePrimaryColor(QColor color);

    void on_btnClear_clicked();

private:
    Ui::MainWindow *ui;
    Toolbar toolbar;
    QColor primaryColor, secondaryColor;
    QColor eraser;
    void loadFile(QString);
    void saveFile();
    void newFile();
    void selectButton(Toolbar::Tools tool);
};
#endif // MAINWINDOW_H
