/************************************************
 * DrawingWindow class
 * Class definition for displaying the animation
 * pop up window
 * @author: Anna Timofeyenko, Gabby Culley,
 *          Gaby Torres, Raynard Christian
 * @date: 4/5/2022
************************************************/
#include "previewwindow.h"
#include <QPixmap>
#include <QImage>

PreviewWindow::PreviewWindow(QWidget *parent)
    : QWidget{parent}
{
    this->setGeometry(540, 40, screenWidth, screenHeight);

    previewWindow = new QLabel(this);
    previewWindow->setGeometry(0, 0, screenWidth, screenHeight);
    previewWindow->setAlignment(Qt::AlignCenter);
    previewWindow->setFrameShape(QFrame::Box);
}

void PreviewWindow::displayPreviewFrame(QImage* frame) {
    previewWindow->setPixmap(QPixmap::fromImage(*frame));
}
