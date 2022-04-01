#ifndef ANIMATIONPOPUP_H
#define ANIMATIONPOPUP_H

#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QTimer>
#include <QListWidget>

namespace Ui {
class AnimationPopUp;
}

class AnimationPopUp : public QWidget
{
    Q_OBJECT
    int framesPerSecond;
    unsigned int currFrameIndex;
    QLabel* animationWindow;
    std::vector<QListWidgetItem> frames;
    int screenWidth = 141;
    int screenHeight = 141;

public:
    explicit AnimationPopUp(QWidget *parent = nullptr);
    ~AnimationPopUp();

public slots:
    void changeFramesPerSecond(int);
    void playPreviewClick(std::vector<QListWidgetItem>);
    void animate();

private:
    Ui::AnimationPopUp *ui;
};

#endif // ANIMATIONPOPUP_H
