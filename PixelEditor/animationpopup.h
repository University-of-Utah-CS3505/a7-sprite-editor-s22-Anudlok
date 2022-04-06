/************************************************
 * AnimationPopUp class
 * Class definition for displaying the animation
 * pop up window
 * @author: Anna Timofeyenko, Gabby Culley,
 *          Gaby Torres, Raynard Christian
 * @date: 4/5/2022
************************************************/
#ifndef ANIMATIONPOPUP_H
#define ANIMATIONPOPUP_H

#include <QMainWindow>
#include <QLabel>
#include <QPixmap>
#include <QTimer>
#include <QListWidget>

namespace Ui {
class AnimationPopUp;
}

/**
 * @brief The AnimationPopUp class
 */
class AnimationPopUp : public QWidget
{
    Q_OBJECT
    QLabel* animationWindow;
    int framesPerSecond;
    int screenWidth = 200;
    int screenHeight = 200;

protected:
    void closeEvent(QCloseEvent *event) override;

public:
    explicit AnimationPopUp(QWidget *parent
                            = nullptr);
    ~AnimationPopUp();
    int getFPS();
    void setFPS(int newFPS);

signals:
    void playAnim(int framesPerSecond);
    void stopAnim();

public slots:
    void displayAnimFrame(QImage* frame);

private:
    Ui::AnimationPopUp *ui;
};

#endif // ANIMATIONPOPUP_H
