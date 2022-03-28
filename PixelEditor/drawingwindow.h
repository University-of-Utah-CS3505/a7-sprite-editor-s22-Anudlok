#ifndef DRAWINGWINDOW_H
#define DRAWINGWINDOW_H

#include <QObject>

class drawingwindow : public QObject
{
    Q_OBJECT
public:
    explicit drawingwindow(QObject *parent = nullptr);

signals:

public slots:
    void displayCurrentFrame(QImage frame);
    void clickOnFrame();
};

#endif // DRAWINGWINDOW_H
