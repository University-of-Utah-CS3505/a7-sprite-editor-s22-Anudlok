/************************************************
 * DrawingWindow class
 * Class Definition for the Drawing Window
 * @author: Anna Timofeyenko, Gabby Culley,
 *          Gaby Torres, Raynard Christian
 * @date: 4/5/2022
************************************************/
#ifndef DRAWINGWINDOWWIDGET_H
#define DRAWINGWINDOWWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPainter>

class DrawingWindow : public QWidget
{
    Q_OBJECT

private:
    QLabel* drawingWindow;
    QLabel* gridWindow;
    QLabel* shadowWindow;
    int height = 1;
    int width = 1;
    bool mouseButtonDown = false;
    QColor color;
    bool colorPicker = false;
    bool bucket = false;
    bool start = false;

public:
    const int SCREEN_WIDTH = 384;
    const int SCREEN_HEIGHT = 384;

    explicit DrawingWindow(QWidget *parent = nullptr);
    ~DrawingWindow();
    void mouseColor(int x, int y);
    void bucketColor(int x, int y);
    void setCurrentColor(QColor color);
    void colorPickerPicked(bool state);
    bool getColorPicked();
    void bucketPicked(bool state);
    void startDrawing();
    QImage getImage();
    void setMouseButtonDown(bool state);
    bool getMouseButtonDown();
    int getX();
    int getY();
    bool getBucket();

signals:
    void colorPixel(QColor color, int row, int column);
    void fillPixel(QColor color, int row, int column);
    void colorChosen(QColor color);

public slots:
    void displayCurrentFrame(QImage* frame, QImage* prevFrame, int width, int height);
    void setWidthAndHeight(int _width, int _height);
};

#endif // DRAWINGWINDOWWIDGET_H
