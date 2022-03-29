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
    int width = 100;
    int height = 100;

signals:
    void displayFrame(QImage* frame);

public slots:
    void addFrame();
    void addFrame(QImage frame);
    void deleteFrame();
    void updateFrame(QColor color, int row, int column);
    void changeFrame(bool upOrDown);
    void playAllFrames();
    void setWidthAndHeight(int width, int height);

};



#endif // FRAMES_H
