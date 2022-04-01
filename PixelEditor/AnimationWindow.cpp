#include "animationwindow.h"
#include "./ui_animationwindow.h"
#include <QWidget>
#include <QLabel>
#include <QPixmap>

AnimationWindow::AnimationWindow(QWidget *parent)
    : QWidget(parent),
      ui(new Ui::AnimationWindow)
{
    AnimationWindow::framesPerSecond = 3;
    this->setGeometry(530, 40, screenWidth, screenHeight);
    animationWindow = new QLabel(this);
    animationWindow->setGeometry(0, 0, screenWidth, screenHeight);
    animationWindow->setAlignment(Qt::AlignCenter);
    animationWindow->setFrameShape(QFrame::Box);
}

void AnimationWindow::changeFramesPerSecond(int initFrames){
    framesPerSecond = initFrames;
}

void AnimationWindow::playPreviewClick(std::vector<QImage> frames ){

}
