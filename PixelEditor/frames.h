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
    void updateFrame();
    void changeFrame();
    void playAllFrames();

private:
    QImage image;

signals:

};



#endif // FRAMES_H
