#include "animationpopup.h"
#include "ui_animationpopup.h"

AnimationPopUp::AnimationPopUp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AnimationPopUp)
{
    ui->setupUi(this);
    currFrameIndex = 0;
    AnimationPopUp::framesPerSecond = 3;
    this->setGeometry(530, 40, screenWidth, screenHeight);
    animationWindow = new QLabel(this);
    animationWindow->setGeometry(0, 0, screenWidth, screenHeight);
    animationWindow->setAlignment(Qt::AlignCenter);
    animationWindow->setFrameShape(QFrame::Box);
}

AnimationPopUp::~AnimationPopUp()
{
    delete ui;
}

void AnimationPopUp::changeFramesPerSecond(int initFrames){
    framesPerSecond = initFrames;
}

void AnimationPopUp::playPreviewClick(std::vector<QImage> initFrames){
    QTimer timer;
    int interval = 6000/framesPerSecond;
    frames = initFrames;
    timer.setInterval(interval);
    connect(&timer, SIGNAL(QTimer::timeout()), this, SLOT(AnimationPopUp::animate()));
}

void AnimationPopUp::animate(){
    if(currFrameIndex > frames.size()-1){
        currFrameIndex = 0;
    }
    animationWindow->setPixmap(QPixmap::fromImage(frames[currFrameIndex]));
    currFrameIndex++;
}
