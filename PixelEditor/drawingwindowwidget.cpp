#include "drawingwindowwidget.h"
#include "QImage"

drawingwindowwidget::drawingwindowwidget(QWidget *parent)
    : QWidget{parent}
{
    this->setGeometry(120, 40, 471, 391);
    drawingWindow = new QLabel(this);
    drawingWindow->setGeometry(0, 0, 471, 391);
    drawingWindow->setAlignment(Qt::AlignCenter);
    drawingWindow->setAutoFillBackground(true);
    drawingWindow->setStyleSheet("background-color: white;");
    drawingWindow->setFrameShape(QFrame::Box);

    gridWindow = new QLabel(this);
    gridWindow->setGeometry(0, 0, 471, 391);
    gridWindow->setAlignment(Qt::AlignCenter);
    gridWindow->setAutoFillBackground(true);
    gridWindow->setStyleSheet("background-color: white;");
    gridWindow->setFrameShape(QFrame::Box);

    //emit getWidthAndHeight();
    QImage bars(gridWindow->width(), gridWindow->height(), QImage::Format_ARGB32);
    int vLines = gridWindow->width() / 3;
    int hLines = gridWindow->height() / 3;
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
}

void drawingwindowwidget::displayCurrentFrame(QImage* frame) {
    drawingWindow->setPixmap(QPixmap::fromImage(*frame));
}

void drawingwindowwidget::mousePressEvent(QMouseEvent *event)
{
    int x = QCursor::pos().x();
    int y = QCursor::pos().y();
    qDebug() << x << ", " << y;
}

void drawingwindowwidget::setWidthAndHeight(int _width, int _height) {
    height = _height;
    width = _width;
}
