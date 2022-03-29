#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "QtWidgets/qlistwidget.h"
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
signals:
    void currentFrameChanged(QImage * frame);

private slots:

    void on_actionNew_triggered();

    void on_actionSave_triggered();

    void on_actionOpen_triggered();

    void on_actionExit_triggered();

   void on_framesListWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_framesListWidget_itemActivated(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
    void loadFile(QString);
    void saveFile();
    void newFile();
};
#endif // MAINWINDOW_H
