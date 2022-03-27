#ifndef FRAMELIST_H
#define FRAMELIST_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <vector>

class FrameList : public QObject
{
    Q_OBJECT
public:
    explicit FrameList(QObject *parent = nullptr);

    //don't know if this is a signal
    void displayFrameLists(std::vector<QImage>);

signals:
    void NewFrameClick();
    void selectFrame();
    void moveFrameLeft();
    void moveFrameRight();
};

#endif // FRAMELIST_H
