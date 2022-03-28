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

signals:
    void displayFrameLists(std::vector<QImage>);
    void NewFrameClick();
    void selectFrame(int, std::vector<QImage>);
    void moveFrameLeft(int, std::vector<QImage>);
    void moveFrameRight(int, std::vector<QImage>);
};

#endif // FRAMELIST_H
