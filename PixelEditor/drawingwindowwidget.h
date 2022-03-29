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
    int width;
    int height;

public:
    explicit drawingwindowwidget(QWidget *parent = nullptr);

signals:
    void getWidthAndHeight();

public slots:
    void displayCurrentFrame(QImage* frame);
    void mousePressEvent(QMouseEvent *event);
    void setWidthAndHeight(int _width, int _height);
};

#endif // DRAWINGWINDOWWIDGET_H
