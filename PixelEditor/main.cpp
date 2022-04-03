#include "mainwindow.h"
#include "drawingwindow.h"
#include "drawingwindowwidget.h"
#include "previewwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Frames f;
    drawingwindow dw;
    drawingwindowwidget dww;
    PreviewWindow pw;
    MainWindow w(pw, f, dw, dww);
    w.show();
    return a.exec();
}
