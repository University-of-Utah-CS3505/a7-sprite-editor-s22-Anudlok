#ifndef ANIMATIONPOPUP_H
#define ANIMATIONPOPUP_H

#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QTimer>

namespace Ui {
class AnimationPopUp;
}

class AnimationPopUp : public QWidget
{
    Q_OBJECT
    int framesPerSecond;
    unsigned int currFrameIndex;
    QLabel* animationWindow;
    std::vector<QImage> frames;
    int screenWidth = 141;
    int screenHeight = 141;

public:
    explicit AnimationPopUp(QWidget *parent = nullptr);
    ~AnimationPopUp();
    void changeFramesPerSecond(int);

public slots:
    void playPreviewClick(std::vector<QImage>);
    void animate();

private:
    Ui::AnimationPopUp *ui;
};

#endif // ANIMATIONPOPUP_H
