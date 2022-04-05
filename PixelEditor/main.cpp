#include "mainwindow.h"
#include "drawingwindowwidget.h"
#include "previewwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Frames f;
    DrawingWindow dw;
    PreviewWindow pw;
    MainWindow w(pw, f, dw);
    w.show();
    return a.exec();
}
