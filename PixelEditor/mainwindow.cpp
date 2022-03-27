#include "mainwindow.h"
#include "./ui_mainwindow.h"

/**
 * @brief MainWindow::MainWindow The View Class
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::prevFrameViewChanged(const QIcon &icon)
{

}


void MainWindow::currFrameViewChanged(const QIcon &icon)
{

}


void MainWindow::nextFrameViewChanged(const QIcon &icon)
{

}

