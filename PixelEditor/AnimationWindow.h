#ifndef ANIMATIONWINDOW_H
#define ANIMATIONWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPixmap>

QT_BEGIN_NAMESPACE
namespace Ui { class AnimationWindow; }
QT_END_NAMESPACE

class AnimationWindow : public QWidget
{
    Q_OBJECT
    int framesPerSecond;
    QLabel* animationWindow;
    int screenWidth = 141;
    int screenHeight = 141;
public:
    explicit AnimationWindow(QWidget *parent = nullptr);

    void changeFramesPerSecond(int);
signals:
    void displayAnimationFrame(QImage* frame);
public slots:
    void playPreviewClick(std::vector<QImage>);
 private:
    Ui::AnimationWindow * ui;
};

#endif // ANIMATIONWINDOW_H
