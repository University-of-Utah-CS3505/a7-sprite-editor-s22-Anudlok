#include "animationwindow.h"

AnimationWindow::AnimationWindow(QObject *parent)
    : QObject{parent}
{
    AnimationWindow::framesPerSecond = 3;

}

void AnimationWindow::changeFramesPerSecond(int initFrames){
    framesPerSecond = initFrames;
}
