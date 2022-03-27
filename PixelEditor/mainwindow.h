#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>

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
    std::vector<QImage> frames;

private slots:
    void prevFrameViewChanged(const QIcon &icon);

    void currFrameViewChanged(const QIcon &icon);

    void nextFrameViewChanged(const QIcon &icon);

    void loadFile(QString);

    void on_actionNew_triggered();

    void on_actionSave_triggered();

    void on_actionOpen_triggered();

    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
