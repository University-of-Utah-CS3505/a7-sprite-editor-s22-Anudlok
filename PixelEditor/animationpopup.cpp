/************************************************
 * AnimationPopUp class
 * Class definition for displaying the animation
 * pop up window
 * @author: Anna Timofeyenko, Gabby Culley,
 *          Gaby Torres, Raynard Christian
 * @date: 4/5/2022
************************************************/
#include "animationpopup.h"
#include "ui_animationpopup.h"
#include <QCloseEvent>

/**
 * @brief AnimationPopUp::AnimationPopUp
 * @param parent
 */
AnimationPopUp::AnimationPopUp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AnimationPopUp)
{
    ui->setupUi(this);

    this->setGeometry(530, 40, screenWidth,
                      screenHeight);
    animationWindow = new QLabel(this);
    animationWindow->setGeometry(0, 0,
                                 screenWidth,
                                 screenHeight);
    animationWindow->setAlignment(Qt::AlignCenter);
    animationWindow->setFrameShape(QFrame::Box);

    AnimationPopUp::framesPerSecond = 30;
}

AnimationPopUp::~AnimationPopUp()
{
    delete animationWindow;
    delete ui;
}

void AnimationPopUp::closeEvent (QCloseEvent *event)
{
    emit stopAnim();
    event->accept();
}

void AnimationPopUp::changeFramesPerSecond(int initFrames)
{
    framesPerSecond = initFrames;
}

int AnimationPopUp::getFPS() {
    return framesPerSecond;
}

void AnimationPopUp::displayAnimFrame(QImage* frame) {
    animationWindow->setPixmap(QPixmap::fromImage(*frame));
}
