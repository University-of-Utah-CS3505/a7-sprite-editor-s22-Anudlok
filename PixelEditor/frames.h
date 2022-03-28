#ifndef FRAMES_H
#define FRAMES_H

#include <QObject>
#include <QImage>

class Frames : public QObject
{
    Q_OBJECT
public:
    explicit Frames(QObject *parent = nullptr);
    void addFrame(int height, int width);
    void deleteFrame();
    void updateFrame(QColor color, int row, int column);
    void changeFrame(bool upOrDown);
    void playAllFrames();


private:
    QVector<QImage> frameList;
    int currentFrame = -1;

signals:
    void displayFrame(QImage* frame);

};



#endif // FRAMES_H
