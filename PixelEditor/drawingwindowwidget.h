#ifndef DRAWINGWINDOWWIDGET_H
#define DRAWINGWINDOWWIDGET_H

#include <QWidget>
#include <QLabel>

class drawingwindowwidget : public QWidget
{
    Q_OBJECT

private:
    QLabel* drawingWindow;
    QLabel* gridWindow;
    int screenWidth = 400;
    int screenHeight = 400;
    int height = 1;
    int width = 1;

public:
    explicit drawingwindowwidget(QWidget *parent = nullptr);

signals:
    void colorPixel(QColor color, int row, int column);

public slots:
    void displayCurrentFrame(QImage* frame, int width, int height);
    void mousePressEvent(QMouseEvent *event);
    void setWidthAndHeight(int _width, int _height);
};

#endif // DRAWINGWINDOWWIDGET_H
