/************************************************
 * PreviewWindow class
 * Class definition for displaying the preview
 * window
 * @author: Anna Timofeyenko, Gabby Culley,
 *          Gaby Torres, Raynard Christian
 * @date: 4/5/2022
************************************************/
#include "previewwindow.h"
#include <QPixmap>
#include <QImage>

/**
 * @brief Preview Window Constructor
 * @param parent
 */
PreviewWindow::PreviewWindow(QWidget *parent)
    : QWidget{parent}
{
    // Set up the preview window screen
    this->setGeometry(540, 40, screenWidth, screenHeight);

    previewWindow = new QLabel(this);
    previewWindow->setGeometry(0, 0, screenWidth, screenHeight);
    previewWindow->setAlignment(Qt::AlignCenter);
    previewWindow->setFrameShape(QFrame::Box);
}

/**
 * @brief displays the frame inside the preview window
 * @param frame to be displayed
 */
void PreviewWindow::displayPreviewFrame(QImage* frame) {
    previewWindow->setPixmap(QPixmap::fromImage(*frame));
}
