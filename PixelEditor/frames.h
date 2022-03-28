#ifndef FRAMES_H
#define FRAMES_H

#include <QObject>
#include <QImage>
#include <vector>
#include STD::VECTOR


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
    vector<QImage> frameList;
signals:

};



#endif // FRAMES_H
