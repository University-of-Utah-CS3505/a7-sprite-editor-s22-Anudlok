#ifndef FRAMES_H
#define FRAMES_H

#include <QObject>
#include <QImage>

class Frames : public QObject
{
    Q_OBJECT
public:
    explicit Frames(QObject *parent = nullptr);

private:
    QVector<QImage> frameList;
    int currentFrame = -1;
    int width = 3;
    int height = 3;

signals:
    void displayFrame(QImage* frame, int width, int height);

public slots:
    void addFrame(int _width, int _height);
    void addFrameWithFrame(QImage frame);
    void deleteFrame();
    void updateFrame(QColor color, int row, int column);
    void changeFrame(bool upOrDown);
    void playAllFrames();
    void setWidthAndHeight(int width, int height);
    void clearFrame();
};



#endif // FRAMES_H
