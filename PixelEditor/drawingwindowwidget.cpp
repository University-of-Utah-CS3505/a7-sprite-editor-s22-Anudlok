#include "drawingwindowwidget.h"
#include "QImage"

drawingwindowwidget::drawingwindowwidget(QWidget *parent)
    : QWidget{parent}
{
    this->setGeometry(120, 40, screenWidth, screenHeight);
    drawingWindow = new QLabel(this);
    drawingWindow->setGeometry(0, 0, screenWidth, screenHeight);
    drawingWindow->setAlignment(Qt::AlignCenter);
//    drawingWindow->setAutoFillBackground(true);
//    drawingWindow->setStyleSheet("background-color: white;");
    drawingWindow->setFrameShape(QFrame::Box);

    gridWindow = new QLabel(this);
    gridWindow->setGeometry(0, 0, screenWidth, screenHeight);
    gridWindow->setAlignment(Qt::AlignCenter);
    gridWindow->setFrameShape(QFrame::Box);
}

void drawingwindowwidget::displayCurrentFrame(QImage* frame, int width, int height)
{
    setWidthAndHeight(width, height);
    QImage bars(gridWindow->width(), gridWindow->height(), QImage::Format_ARGB32);
    QImage pixels(drawingWindow->width(), drawingWindow->height(), QImage::Format_ARGB32);
    int vLines = screenWidth / width;
    int hLines = screenHeight / height;

//    QVector<QColor> color;
//    for (int i = 0; i < width; i++) {
//        for (int j = 0; j < height; j++) {
//            color.append(frame->pixelColor(i,j));
//        }
//    }
//    int count = 0;
//    for (int i = 1; i <= width; i++) {
//        for (int j = 1; j <= height; j++) {
//            for (int k = vLines * (i - 1); k < vLines * i; k++) {
//                for (int l = hLines * (j - 1); l < hLines * j; l++) {
//                    pixels.setPixelColor(k, l, color.at(count));
//                }
//            }
//            count++;
//        }
//    }

    QImage scaledFrame = frame->scaled(screenWidth, screenHeight);

    bars.fill(QColor(0, 0, 0, 0));
    for (int i = 0; i < gridWindow->width(); i += vLines) {
        for (int j = 0; j < gridWindow->height(); j++) {
            bars.setPixelColor(i, j, QColor(0, 0, 0, 100));
        }
    }
    for (int i = 0; i < gridWindow->height(); i += hLines) {
        for (int j = 0; j < gridWindow->width(); j++) {
            bars.setPixelColor(j, i, QColor(0, 0, 0, 100));
        }
    }

    gridWindow->setPixmap(QPixmap::fromImage(bars));
    gridWindow->setEnabled(false);
    gridWindow->show();
    drawingWindow->setPixmap(QPixmap::fromImage(scaledFrame));
    drawingWindow->show();
}

void drawingwindowwidget::mouseMoveEvent(QMouseEvent *event){
    int x = drawingWindow->mapFromGlobal(QCursor::pos()).x();
    int y = drawingWindow->mapFromGlobal(QCursor::pos()).y();
    if (mouseButtonDown && (x >= 0 && x < screenWidth) && (y >= 0 && y < screenHeight)) {
        mouseColor(x, y);
    }
}

void drawingwindowwidget::mouseColor(int x, int y) {
    int row = x / (screenWidth / width);
    int column = y / (screenHeight / height);
    emit colorPixel(color, row, column);
}

void drawingwindowwidget::mousePressEvent(QMouseEvent *event)
{
    if (start) {
        int x = drawingWindow->mapFromGlobal(QCursor::pos()).x();
        int y = drawingWindow->mapFromGlobal(QCursor::pos()).y();
        if (colorPicker) {
            QImage pixmap = drawingWindow->pixmap().toImage();
            QColor colorOfPixel = pixmap.pixelColor(x, y);
            if (colorOfPixel.alpha() > 0)
                emit colorChosen(colorOfPixel);
        }
        else {
            mouseColor(x, y);
            mouseButtonDown = true;
        }
        colorPicker = false;
    }
}

void drawingwindowwidget::mouseReleaseEvent(QMouseEvent *event) {
    mouseButtonDown = false;
}

void drawingwindowwidget::setWidthAndHeight(int _width, int _height) {
    height = _height;
    width = _width;
}

void drawingwindowwidget::setCurrentColor(QColor _color) {
    color = _color;
}

void drawingwindowwidget::colorPicked(bool state) {
    colorPicker = state;
}

void drawingwindowwidget::startDrawing() {
    start = true;
}
