#ifndef ANIMATIONPOPUP_H
#define ANIMATIONPOPUP_H

#include <QWidget>
#include <QLabel>
#include <QPixmap>

namespace Ui {
class AnimationPopUp;
}

class AnimationPopUp : public QWidget
{
    Q_OBJECT
    int framesPerSecond;
    QLabel* animationPopUp;
    int screenWidth = 141;
    int screenHeight = 141;

public:
    explicit AnimationPopUp(QWidget *parent = nullptr);
    ~AnimationPopUp();
    void changeFramesPerSecond(int);
signals:
    void displayAnimationFrame(QImage* frame);
public slots:
    void playPreviewClick(std::vector<QImage>);
private:
    Ui::AnimationPopUp *ui;
};

#endif // ANIMATIONPOPUP_H
