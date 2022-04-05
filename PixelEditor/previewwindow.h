#ifndef PREVIEWWINDOW_H
#define PREVIEWWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPixmap>

class PreviewWindow : public QWidget
{
    Q_OBJECT
public:
    explicit PreviewWindow(QWidget *parent = nullptr);

private:
    QLabel* previewWindow;
    int screenWidth = 160;
    int screenHeight = 160;

signals:
    void sendWindow(QPixmap *frame);

public slots:
    void displayPreviewFrame(QImage* frame);
};

#endif // PREVIEWWINDOW_H
