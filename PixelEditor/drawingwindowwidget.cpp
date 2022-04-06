/************************************************
 * DrawingWindow class
 * Class definition for displaying Drawing
 * Window
 * @author: Anna Timofeyenko, Gabby Culley,
 *          Gaby Torres, Raynard Christian
 * @date: 4/5/2022
************************************************/
#include "drawingwindowwidget.h"
#include "QImage"

DrawingWindow::DrawingWindow(QWidget *parent)
    : QWidget{parent}
{   
    this->setGeometry(130, 40, SCREEN_WIDTH, SCREEN_HEIGHT);

    gridWindow = new QLabel(this);
    gridWindow->setGeometry(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    gridWindow->setAlignment(Qt::AlignCenter);
    gridWindow->setFrameShape(QFrame::Box);

    shadowWindow = new QLabel(this);
    shadowWindow->setGeometry(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    shadowWindow->setAlignment(Qt::AlignCenter);
    shadowWindow->setFrameShape(QFrame::Box);

    drawingWindow = new QLabel(this);
    drawingWindow->setGeometry(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    drawingWindow->setAlignment(Qt::AlignCenter);
//    drawingWindow->setAutoFillBackground(true);
//    drawingWindow->setStyleSheet("background-color: white;");
    drawingWindow->setFrameShape(QFrame::Box);
}

DrawingWindow::~DrawingWindow() {
    delete drawingWindow;
    delete gridWindow;
    delete shadowWindow;
}

void DrawingWindow::displayCurrentFrame(QImage* frame, QImage* prevFrame, int width, int height)
{
    setWidthAndHeight(width, height);
    QImage pixels(drawingWindow->width(), drawingWindow->height(), QImage::Format_ARGB32);

    QImage scaledFrame = frame->scaled(SCREEN_WIDTH, SCREEN_HEIGHT);
    QImage scaledPrevFrame = prevFrame->scaled(SCREEN_WIDTH, SCREEN_HEIGHT);
    QImage bars(width, height, QImage::Format_ARGB32);
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if ((i + j) % 2 == 0) {
                bars.setPixelColor(i, j, QColor(100, 100, 100, 30));
            }
            else {
                bars.setPixelColor(i, j, QColor(0, 0, 0, 30));
            }
        }
    }
    bars = bars.scaled(SCREEN_WIDTH, SCREEN_HEIGHT);

    gridWindow->setPixmap(QPixmap::fromImage(bars));
    gridWindow->setEnabled(false);
    gridWindow->show();

    QPixmap pixmap = QPixmap::fromImage(scaledPrevFrame);
    scaledPrevFrame.fill(Qt::transparent);
    QPainter p(&scaledPrevFrame);
    p.setOpacity(0.3);
    p.drawPixmap(0, 0, pixmap);
    p.end();
    pixmap = QPixmap::fromImage(scaledPrevFrame);
    shadowWindow->setPixmap(pixmap);
    shadowWindow->show();

    drawingWindow->setPixmap(QPixmap::fromImage(scaledFrame));
    drawingWindow->show();
}

void DrawingWindow::mouseColor(int x, int y) {
    int row = x / (SCREEN_WIDTH / width);
    int column = y / (SCREEN_HEIGHT / height);
    qDebug() << "actual: " << row << ", " << column;
    if (row >= 0 && row < width && column >= 0 && column < height)
        emit colorPixel(color, row, column);
}

void DrawingWindow::mouseFillColor(int x, int y) {
    int row = x / (SCREEN_WIDTH / width);
    int column = y / (SCREEN_HEIGHT / height);
    qDebug() << "fill: " << row << ", " << column;
    if (row >= 0 && row < width && column >= 0 && column < height)
        emit fillPixel(color, row, column);
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

bool DrawingWindow::getColorPicked() {
    return colorPicker;
}

void DrawingWindow::startDrawing() {
    start = true;
}

QImage DrawingWindow::getImage() {
    return drawingWindow->pixmap().toImage();
}

void DrawingWindow::setMouseButtonDown(bool state) {
    mouseButtonDown = state;
}

bool DrawingWindow::getMouseButtonDown() {
    return mouseButtonDown;
}

int DrawingWindow::getX() {
    return drawingWindow->mapFromGlobal(QCursor::pos()).x();
}

int DrawingWindow::getY() {
    return drawingWindow->mapFromGlobal(QCursor::pos()).y();
}
