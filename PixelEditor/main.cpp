#include "mainwindow.h"
#include "drawingwindow.h"
#include "drawingwindowwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Frames f;
    drawingwindow dw;
    drawingwindowwidget dww;
    MainWindow w(f, dw, dww);
    w.show();
    return a.exec();
}
