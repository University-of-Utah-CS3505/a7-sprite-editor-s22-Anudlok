#include "mainwindow.h"
#include "drawingwindow.h"
#include "drawingwindowwidget.h"
#include "previewwindow.h"
#include "animationpopup.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Frames f;
    drawingwindow dw;
    drawingwindowwidget dww;
    PreviewWindow pw;
    AnimationPopUp aw;
    MainWindow w(aw, pw, f, dw, dww);
    w.show();
    return a.exec();
}
