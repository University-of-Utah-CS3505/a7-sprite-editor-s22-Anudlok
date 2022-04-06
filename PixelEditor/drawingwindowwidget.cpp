/************************************************
 * DrawingWindow class
 * Class definition for displaying Drawing
 * Window
 * @author: Anna Timofeyenko, Gabby Culley,
 *          Gaby Torres, Raynard Christian
 * @date: 4/5/2022
************************************************/
#include "drawingwindowwidget.h"
#include "QImage"

/**
 * @brief DrawingWindow::DrawingWindow
 * the drawingWindow class contains the gui
 * objects necessary to make the logic of the
 * drawingwindow run.This includes the gridWindow
 * which shows just the grid, the shadowWindow,
 * which shows the previous frame, and the
 * drawingWindow which is where the user actually
 * draws
 *
 * @param parent the QWidget Object that is created
 * in the Main class
 */
DrawingWindow::DrawingWindow(QWidget *parent)
    : QWidget{parent}
{   
    this->setGeometry(130, 40, SCREEN_WIDTH, SCREEN_HEIGHT);

    gridWindow = new QLabel(this);
    gridWindow->setGeometry(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    gridWindow->setAlignment(Qt::AlignCenter);
    gridWindow->setFrameShape(QFrame::Box);

    shadowWindow = new QLabel(this);
    shadowWindow->setGeometry(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    shadowWindow->setAlignment(Qt::AlignCenter);
    shadowWindow->setFrameShape(QFrame::Box);

    drawingWindow = new QLabel(this);
    drawingWindow->setGeometry(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    drawingWindow->setAlignment(Qt::AlignCenter);
    drawingWindow->setFrameShape(QFrame::Box);
}

/**
 * @brief Drawing window destructor
 */
DrawingWindow::~DrawingWindow() {
    delete drawingWindow;
    delete gridWindow;
    delete shadowWindow;
}

/**
 * @brief DrawingWindow::displayCurrentFrame slot to display current frame
 * @param frame pointer to the QImage of what the current frame should look like
 * @param prevFrame pointer to the QImage of what the previous frame should look like
 * @param width the int width provided by the user in pixels
 * @param height the int height provided by the user in pixels
 */
void DrawingWindow::displayCurrentFrame(QImage* frame, QImage* prevFrame, int width,
                                        int height)
{
    setWidthAndHeight(width, height);
    QImage pixels(drawingWindow->width(), drawingWindow->height(), QImage::Format_ARGB32);

    QImage scaledFrame = frame->scaled(SCREEN_WIDTH, SCREEN_HEIGHT);
    QImage scaledPrevFrame = prevFrame->scaled(SCREEN_WIDTH, SCREEN_HEIGHT);
    QImage bars(width, height, QImage::Format_ARGB32);

    //draws the bars for gray and white background
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if ((i + j) % 2 == 0) {
                bars.setPixelColor(i, j, QColor(100, 100, 100, 30));
            }
            else {
                bars.setPixelColor(i, j, QColor(0, 0, 0, 30));
            }
        }
    }
    //scales and displays the g&w background
    bars = bars.scaled(SCREEN_WIDTH, SCREEN_HEIGHT);

    gridWindow->setPixmap(QPixmap::fromImage(bars));
    gridWindow->setEnabled(false);
    gridWindow->show();

    //draw the shadow of scaled previous frame
    QPixmap pixmap = QPixmap::fromImage(scaledPrevFrame);
    scaledPrevFrame.fill(Qt::transparent);
    QPainter p(&scaledPrevFrame);
    p.setOpacity(0.3);
    p.drawPixmap(0, 0, pixmap);
    p.end();
    pixmap = QPixmap::fromImage(scaledPrevFrame);
    shadowWindow->setPixmap(pixmap);
    shadowWindow->show();

    //draws current scaled frame on drawingwindow
    drawingWindow->setPixmap(QPixmap::fromImage(scaledFrame));
    drawingWindow->show();
}

/**
 * @brief DrawingWindow::mouseColor helper method to set the color of a mouse
 * at a specific x,y coordinate
 * @param x the int x value of the coordinate
 * @param y the int y value of the coordinate
 */
void DrawingWindow::mouseColor(int x, int y) {
    int row = x / (SCREEN_WIDTH / width);
    int column = y / (SCREEN_HEIGHT / height);

    //checks if its within the bounds
    if (row >= 0 && row < width && column >= 0 && column < height)
        emit colorPixel(color, row, column);
}

/**
 * @brief DrawingWindow::bucketColor helper method to set color of a paint bucket,
 * also serves as a driver method
 * @param x the int x value of the coordinate
 * @param y the int y value of the coordinate
 */
void DrawingWindow::bucketColor(int x, int y) {
    int row = x / (SCREEN_WIDTH / width);
    int column = y / (SCREEN_HEIGHT / height);
    if (row >= 0 && row < width && column >= 0 && column < height)
        emit fillPixel(color, row, column);
}

/**
 * @brief DrawingWindow::setWidthAndHeight slot to set width and height in pixels
 * @param _width int width in pixels
 * @param _height int height in pixels
 */
void DrawingWindow::setWidthAndHeight(int _width, int _height) {
    height = _height;
    width = _width;
}

/**
 * @brief DrawingWindow::setCurrentColor slot to set the color of the brush
 * @param _color QColor color to send
 */
void DrawingWindow::setCurrentColor(QColor _color) {
    color = _color;
}

/**
 * @brief DrawingWindow::bucketPicked slot to indicate that the bucket tool
 * was selected
 * @param state bool where true if the bucket was selected and false otherwise
 */
void DrawingWindow::bucketPicked(bool state) {
    bucket = state;
}

/**
 * @brief DrawingWindow::colorPickerPicked slot to indicate that the color picker
 * was picked
 * @param state bool where true if color picked and false otherwise
 */
void DrawingWindow::colorPickerPicked(bool state) {
    colorPicker = state;
}

/**
 * @brief DrawingWindow::getColorPicked slot to indicate whther the color picker
 * was picked
 * @return whether or not color picker was picked
 */
bool DrawingWindow::getColorPicked() {
    return colorPicker;
}

/**
 * @brief DrawingWindow::startDrawing slot to indicate that the user should
 * start drawing.
 */

void DrawingWindow::startDrawing() {
    start = true;
}

/**
 * @brief DrawingWindow::getImage Returns the image to be drawn
 * @return the image to be drawn
 */
QImage DrawingWindow::getImage() {
    return drawingWindow->pixmap().toImage();
}

/**
 * @brief DrawingWindow::setMouseButtonDown Sets whether the mouse is
 * set down
 * @param state - Whether the mouse is down or not
 */
void DrawingWindow::setMouseButtonDown(bool state) {
    mouseButtonDown = state;
}

/**
 * @brief DrawingWindow::getMouseButtonDown
 * @return
 */
bool DrawingWindow::getMouseButtonDown() {
    return mouseButtonDown;
}

/**
 * @brief DrawingWindow::getX Gets the x position of the mouse in
 * relation to the drawing window
 * @return the x position
 */
int DrawingWindow::getX() {
    return drawingWindow->mapFromGlobal(QCursor::pos()).x();
}

/**
 * @brief DrawingWindow::getY Gets the y position of the mouse in
 * relation to the drawing window
 * @return the y position
 */
int DrawingWindow::getY() {
    return drawingWindow->mapFromGlobal(QCursor::pos()).y();
}

/**
 * @brief DrawingWindow::getBucket Gets whether the bucket was chosen
 * or not
 * @return whether the bucket was chosen or not
 */
bool DrawingWindow::getBucket() {
    return bucket;
}
