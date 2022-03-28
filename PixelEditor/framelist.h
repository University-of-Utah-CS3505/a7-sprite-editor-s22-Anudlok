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
    QImage nextFrame();

    QImage currFrame();

    QImage prevFrame();

signals:
    void NewFrameClick();
    void selectFrame(int, std::vector<QImage>);
    void moveFrameLeft(int, std::vector<QImage>);
    void moveFrameRight(int, std::vector<QImage>);

public slots:
    void displayFrameLists(std::vector<QImage> &frames);
};

#endif // FRAMELIST_H
