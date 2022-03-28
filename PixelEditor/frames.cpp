#include "frames.h"
#include <QImage>

Frames::Frames(QObject *parent)
    : QObject{parent}
{

}

void Frames::addFrame(int height, int width){
    QImage image = QImage(width, height, QImage::Format_ARGB32);
    frameList.append(image);
    currentFrame += 1;
}

void Frames::deleteFrame() {
    int deleteFrameIndex = currentFrame;
    frameList.removeAt(deleteFrameIndex);
}

void Frames::updateFrame(QColor color, int row, int column) {
    QImage frame = frameList[currentFrame];
    frame.setPixel(row, column, color.rgba());
    emit displayFrame(frame);
}

void Frames::changeFrame(bool upOrDown) {
    if (upOrDown) {
        currentFrame += 1;
    }
    else {
        currentFrame -= 1;
    }
    emit displayFrame(frameList[currentFrame]);
}

void Frames::playAllFrames() {

}
