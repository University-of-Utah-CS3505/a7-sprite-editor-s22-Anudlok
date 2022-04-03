#include "previewwindow.h"
#include <QPixmap>
#include <QImage>

PreviewWindow::PreviewWindow(QWidget *parent)
    : QWidget{parent}
{
    this->setGeometry(530, 40, screenWidth, screenHeight);

    previewWindow = new QLabel(this);
    previewWindow->setGeometry(0, 0, screenWidth, screenHeight);
    previewWindow->setAlignment(Qt::AlignCenter);
    previewWindow->setFrameShape(QFrame::Box);
}

void PreviewWindow::displayPreviewFrame(QImage* frame) {
    previewWindow->setPixmap(QPixmap::fromImage(*frame));
}

void PreviewWindow::requestForWindow(){
    QPixmap pxMap = previewWindow->pixmap();
    emit sendWindow(&pxMap);
}
