#include "drawingwindowwidget.h"
#include "QImage"

DrawingWindow::DrawingWindow(QWidget *parent)
    : QWidget{parent}
{
    this->setGeometry(120, 40, screenWidth, screenHeight);

    shadowWindow = new QLabel(this);
    shadowWindow->setGeometry(0, 0, screenWidth, screenHeight);
    shadowWindow->setAlignment(Qt::AlignCenter);
    shadowWindow->setFrameShape(QFrame::Box);

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

DrawingWindow::~DrawingWindow() {
    delete drawingWindow;
    delete gridWindow;
    delete shadowWindow;
}

void DrawingWindow::displayCurrentFrame(QImage* frame, QImage* prevFrame, int width, int height)
{
    setWidthAndHeight(width, height);
    QImage bars(gridWindow->width(), gridWindow->height(), QImage::Format_ARGB32);
    QImage pixels(drawingWindow->width(), drawingWindow->height(), QImage::Format_ARGB32);
    int vLines = screenWidth / width;
    int hLines = screenHeight / height;

    QImage scaledFrame = frame->scaled(screenWidth, screenHeight); 
    QImage scaledPrevFrame = prevFrame->scaled(screenWidth, screenHeight);

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

    QPixmap pixmap = QPixmap::fromImage(scaledPrevFrame);
    scaledPrevFrame.fill(Qt::transparent);
    QPainter p(&scaledPrevFrame);
    p.setOpacity(0.2);
    p.drawPixmap(0, 0, pixmap);
    p.end();
    pixmap = QPixmap::fromImage(scaledPrevFrame);
    shadowWindow->setPixmap(pixmap);
    shadowWindow->show();

    drawingWindow->setPixmap(QPixmap::fromImage(scaledFrame));
    drawingWindow->show();
}

void DrawingWindow::mouseMoveEvent(QMouseEvent *event){
    int x = drawingWindow->mapFromGlobal(QCursor::pos()).x();
    int y = drawingWindow->mapFromGlobal(QCursor::pos()).y();
    if (mouseButtonDown && (x >= 0 && x < screenWidth) && (y >= 0 && y < screenHeight)) {
        mouseColor(x, y);
    }
}

void DrawingWindow::mouseColor(int x, int y) {
    int row = x / (screenWidth / width);
    int column = y / (screenHeight / height);
    emit colorPixel(color, row, column);
}

void DrawingWindow::mouseFillColor(int x, int y) {
    int row = x / (screenWidth / width);
    int column = y / (screenHeight / height);
    emit fillPixel(color, row, column);
}

void DrawingWindow::mousePressEvent(QMouseEvent *event)
{
        int x = drawingWindow->mapFromGlobal(QCursor::pos()).x();
        int y = drawingWindow->mapFromGlobal(QCursor::pos()).y();
        if (bucket) {
            mouseFillColor(x, y);
        }
        else if (colorPicker) {
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

void DrawingWindow::mouseReleaseEvent(QMouseEvent *event) {
    mouseButtonDown = false;
}

void DrawingWindow::setWidthAndHeight(int _width, int _height) {
    height = _height;
    width = _width;
}

void DrawingWindow::setCurrentColor(QColor _color) {
    color = _color;
}

void DrawingWindow::bucketPicked(bool state) {
    bucket = state;
}

void DrawingWindow::colorPicked(bool state) {
    colorPicker = state;
}

void DrawingWindow::startDrawing() {
    start = true;
}
