#ifndef ANIMATIONWINDOW_H
#define ANIMATIONWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

class AnimationWindow : public QObject
{
    Q_OBJECT
public:
    explicit AnimationWindow(QObject *parent = nullptr);

signals:

};

#endif // ANIMATIONWINDOW_H
