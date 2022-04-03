#include "animationpopup.h"
#include "ui_animationpopup.h"
#include <QCloseEvent>

AnimationPopUp::AnimationPopUp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AnimationPopUp)
{
    ui->setupUi(this);
    currFrameIndex = 0;
    AnimationPopUp::framesPerSecond = 3;
    AnimationPopUp::interval = 6000/framesPerSecond;
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

void AnimationPopUp::closeEvent (QCloseEvent *event)
{
    emit stopAnim();
    event->accept();
}


void AnimationPopUp::changeFramesPerSecond(int initFrames){
    framesPerSecond = initFrames;
}

void AnimationPopUp::displayAnimFrame(QImage* frame) {//, int width, int height) {
    animationWindow->setPixmap(QPixmap::fromImage(*frame));
}

//void AnimationPopUp::playPreviewClick(std::vector<QListWidgetItem> initFrames){
//    //QTimer timer;
//    frames = initFrames;
//   // timer.setInterval(interval);
//    //error: no such signal emitted
//   QTimer::singleShot(interval, this, &AnimationPopUp::animate);
//   //connect(&timer, SIGNAL(QTimer::timeout()), this, SLOT(AnimationPopUp::animate()));
//}

//void AnimationPopUp::animate(){
//    QIcon icon = frames[currFrameIndex].icon();
//    animationWindow->setWindowIcon(icon);
//    currFrameIndex = (currFrameIndex + 1) % frames.size();
//    QTimer::singleShot(interval, this, &AnimationPopUp::animate);

//    QIcon frameIcon(*frame);
//    QListWidgetItem item;
//    QImage clickedFrame;

//    item.setIcon(frameIcon);
//    widgetList.push_back(item);
//    currFrame++;
//    clickedFrame = frame->toImage();
//    emit currentFrameChanged(clickedFrame);
//}
