#include "mainwindow.h"
#include "drawingwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Frames f;
    drawingwindow dw;
    MainWindow w(f, dw);
    w.show();
    return a.exec();
}
