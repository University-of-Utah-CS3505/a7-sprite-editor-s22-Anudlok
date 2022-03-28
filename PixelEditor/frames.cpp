#include "frames.h"
#include <QImage>

Frames::Frames(QObject *parent)
    : QObject{parent}
{

}

void Frames::addFrame(int height, int width){
    image = QImage(width, height, QImage::Format_ARGB32);
}

void Frames::deleteFrame() {

}

void Frames::updateFrame() {

}

void Frames::changeFrame() {

}

void Frames::playAllFrames() {

}
