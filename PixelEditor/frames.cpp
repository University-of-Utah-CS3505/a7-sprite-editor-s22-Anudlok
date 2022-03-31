#include "frames.h"
#include <QImage>

Frames::Frames(QObject *parent)
    : QObject{parent}
{

}

void Frames::setWidthAndHeight(int _width, int _height) {
    width = _width;
    height = _height;
}

void Frames::clearFrame() {
    frameList[currentFrame].fill(QColor(0, 0, 0, 0));
    emit displayFrame(&(frameList[currentFrame]), width, height);
}

void Frames::addFrame(int _width, int _height){
    setWidthAndHeight(_width, _height);
    QImage image = QImage(width, height, QImage::Format_ARGB32);
    image.fill(QColor(0, 0, 0, 0));
    frameList.append(image);
    currentFrame += 1;
    emit displayFrame(&(frameList[currentFrame]), width, height);
}

void Frames::addFrameWithFrame(QImage frame){
    frameList.append(frame);
    currentFrame += 1;
    emit displayFrame(&(frameList[currentFrame]), width, height);
}

void Frames::deleteFrame() {
    int deleteFrameIndex = currentFrame;
    frameList.removeAt(deleteFrameIndex);
}

void Frames::updateFrame(QColor color, int row, int column) {
    frameList[currentFrame].setPixelColor(row, column, color);
    emit displayFrame(&frameList[currentFrame], width, height);
}

void Frames::changeFrame(bool upOrDown) {
    if (upOrDown) {
        currentFrame += 1;
    }
    else {
        currentFrame -= 1;
    }
    emit displayFrame(&(frameList[currentFrame]), width, height);
}

void Frames::playAllFrames() {

}
