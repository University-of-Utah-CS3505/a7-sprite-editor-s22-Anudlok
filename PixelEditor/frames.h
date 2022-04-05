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
    int animFrame = 0;
    int interval = 6000 / 24;
    bool animPlaying = false;

    void updateView();
    void updateViewFrameList();
    void addToFrameList();
    void removeFromFrameList(int);
    void playNextFrame();

signals:
    void displayFrame(QImage* frame, QImage* prevFrame, int width, int height);
    void displayPreview(QImage* frame);
    void sendFrame(QPixmap *frame, int index);
    void displayAnimFrame(QImage* frame);//, int width, int height);
    void displayInList(QPixmap*, int);
    void addFrameToList(QPixmap *, int);
    void removeFrameFromList(int);
    void clearFrameList();

public slots:
    void addFrame(int _width, int _height);
    void addNewFrame();
    void deleteFrame();
    void updateFrame(QColor color, int row, int column);
    void changeFrame(bool upOrDown);
    void playAllFrames(int framesPerSecond);
    void stopPlayingFrames();
    void setWidthAndHeight(int width, int height);
    void saveFile(QString fileName);
    void loadFile(QString fileName);
    void newFile(int width, int height);
    void saveAndNewFile(QString filename, int width, int height);
    void bucketToolFrame(QColor color, int row, int column);
    void selectFrames(int index);
};



#endif // FRAMES_H
