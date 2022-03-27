#ifndef FRAMELIST_H
#define FRAMELIST_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

class FrameList : public QObject
{
    Q_OBJECT
public:
    explicit FrameList(QObject *parent = nullptr);
    void displayFrameLists(vector<QImage>);
    void NewFrameClick();
    void selectFrame();
    void moveFrameLeft();
    void moveFrameRight();
signals:

};

#endif // FRAMELIST_H
