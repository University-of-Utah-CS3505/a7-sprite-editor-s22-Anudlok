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
    void playPreviewClick();
    void stopPreviewClick();
    void changeFramesPerSecond(int);
signals:

};

#endif // ANIMATIONWINDOW_H
