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
    bool mouseButtonDown = false;
    QColor color;
    bool colorPicker = false;
    bool start = false;

public:
    explicit drawingwindowwidget(QWidget *parent = nullptr);
    void mouseColor(int x, int y);

signals:
    void colorPixel(QColor color, int row, int column);
    void colorChosen(QColor color);

public slots:
    void displayCurrentFrame(QImage* frame, int width, int height);
    void mousePressEvent(QMouseEvent *event);
    void setWidthAndHeight(int _width, int _height);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void setCurrentColor(QColor color);
    void colorPicked(bool state);
    void startDrawing();
};

#endif // DRAWINGWINDOWWIDGET_H
