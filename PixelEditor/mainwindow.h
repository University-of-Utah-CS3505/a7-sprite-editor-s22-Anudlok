#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "framelist.h"
#include "drawingwindow.h"
#include "frames.h"

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
    MainWindow(Frames& frames, drawingwindow& dw, QWidget *parent = nullptr);
    ~MainWindow();
    std::vector<QImage> frames;

private slots:
    void prevFrameViewChanged(const QIcon &icon);

    void currFrameViewChanged(const QIcon &icon);

    void nextFrameViewChanged(const QIcon &icon);

    void updateCurrFrameLeft(int, std::vector<QImage>);
    void updateCurrFrameRight(int,std:: vector<QImage>);

    void on_actionNew_triggered();

    void on_actionSave_triggered();

    void on_actionOpen_triggered();

    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;
    void loadFile(QString);
    void saveFile();

};
#endif // MAINWINDOW_H
