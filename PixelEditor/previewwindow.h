/************************************************
 * PreviewWindow class
 * Class definition for displaying the preview
 * window
 * @author: Anna Timofeyenko, Gabby Culley,
 *          Gaby Torres, Raynard Christian
 * @date: 4/5/2022
************************************************/
#ifndef PREVIEWWINDOW_H
#define PREVIEWWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPixmap>

/**
 * @brief The PreviewWindow class
 */
class PreviewWindow : public QWidget
{
    Q_OBJECT
public:
    explicit PreviewWindow(QWidget *parent = nullptr);

private:
    QLabel* previewWindow;
    int screenWidth = 128;
    int screenHeight = 128;

signals:
    void sendWindow(QPixmap *frame);

public slots:
    void displayPreviewFrame(QImage* frame);
};

#endif // PREVIEWWINDOW_H
