#include "animationpopup.h"
#include "ui_animationpopup.h"

AnimationPopUp::AnimationPopUp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AnimationPopUp)
{
    ui->setupUi(this);
    AnimationPopUp::framesPerSecond = 3;
    this->setGeometry(530, 40, screenWidth, screenHeight);
    animationPopUp = new QLabel(this);
    animationPopUp->setGeometry(0, 0, screenWidth, screenHeight);
    animationPopUp->setAlignment(Qt::AlignCenter);
    animationPopUp->setFrameShape(QFrame::Box);
}

AnimationPopUp::~AnimationPopUp()
{
    delete ui;
}

void AnimationPopUp::changeFramesPerSecond(int initFrames){
    framesPerSecond = initFrames;
}

void AnimationPopUp::playPreviewClick(std::vector<QImage> frames ){

}
