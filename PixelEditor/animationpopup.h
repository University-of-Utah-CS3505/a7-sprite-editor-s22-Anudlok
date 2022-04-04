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

class AnimationPopUp : public QWidget
{
    Q_OBJECT
    int framesPerSecond;
    int interval;
    unsigned int currFrameIndex;
    QLabel* animationWindow;
    std::vector<QListWidgetItem> frames;
    int screenWidth = 141;
    int screenHeight = 141;

protected:
    void closeEvent(QCloseEvent *event) override;

public:
    explicit AnimationPopUp(QWidget *parent = nullptr);
    ~AnimationPopUp();
    //void playPreviewClick(std::vector<QListWidgetItem>);
    //void animate();

signals:
    void playAnim(int framesPerSecond);
    void stopAnim();

public slots:
    void displayAnimFrame(QImage* frame);//, int width, int height);
    void changeFramesPerSecond(int);
private:
    Ui::AnimationPopUp *ui;
};

#endif // ANIMATIONPOPUP_H
