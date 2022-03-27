#include "animationwindow.h"

AnimationWindow::AnimationWindow(QObject *parent)
    : QObject{parent}
{
    AnimationWindow::framesPerSecond = 3;

    AnimationWindow::AnimationWindow(QObject *parent = nullptr){

    }

    void AnimationWindow::changeFramesPerSecond(int initFrames){
        framesPerSecond = initFrames;
    }
}
