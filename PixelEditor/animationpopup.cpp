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
 * @brief AnimationPopUp constructor
 * @param parent
 */
AnimationPopUp::AnimationPopUp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AnimationPopUp)
{
    //Sets up the size and ui
    ui->setupUi(this);
    this->setGeometry(530, 40, screenWidth,
                      screenHeight);

    //Sets up the display window
    animationWindow = new QLabel(this);
    animationWindow->setGeometry(0, 0,
                                 screenWidth,
                                 screenHeight);
    animationWindow->setAlignment(Qt::AlignCenter);
    animationWindow->setFrameShape(QFrame::Box);

    //Intializes the FPS
    framesPerSecond = 30;
}

/**
 * @brief AnimationPopUp destructor
 */
AnimationPopUp::~AnimationPopUp()
{
    delete animationWindow;
    delete ui;
}

/**
 * @brief Event when close button is pressed
 * @param event
 */
void AnimationPopUp::closeEvent (QCloseEvent *event)
{
    emit stopAnim();
    event->accept();
}

/**
 * @brief Changes the FPS to the given amount
 * @param newFPS
 */
void AnimationPopUp::setFPS(int newFPS)
{
    framesPerSecond = newFPS;
}

/**
 * @brief Sends the current frames per second
 * @return the current frames per second
 */
int AnimationPopUp::getFPS() {
    return framesPerSecond;
}

/**
 * @brief Displays the frame given to the popup window
 * @param frame
 */
void AnimationPopUp::displayAnimFrame(QImage* frame) {
    //Displays the frame in the window
    animationWindow->setPixmap(QPixmap::fromImage(*frame));
}
