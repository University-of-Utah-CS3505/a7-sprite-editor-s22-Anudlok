#ifndef ANIMATIONWINDOW_H
#define ANIMATIONWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

class AnimationWindow : public QObject
{
    Q_OBJECT
    int framesPerSecond;
public:
    explicit AnimationWindow(QObject *parent = nullptr);

    void changeFramesPerSecond(int);
signals:
    void playPreviewClick();
    void stopPreviewClick();
};

#endif // ANIMATIONWINDOW_H
