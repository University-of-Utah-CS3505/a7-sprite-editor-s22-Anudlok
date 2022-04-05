#include <QMessageBox>
#include <QFileDialog>
#include <QImage>
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QColorDialog>
#include <QInputDialog>

/**
 * @brief MainWindow::MainWindow The View Class
 * @param parent
 */
MainWindow::MainWindow(PreviewWindow& pw, Frames& frames,
                       drawingwindowwidget& dww, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    popUp = new AnimationPopUp;

    primaryColor = Qt::black;
    secondaryColor = Qt::white;
    eraserColor = QColor(0, 0, 0, 0);

    // Connects for new file
    connect(this, &MainWindow::makeNewFrame, &frames, &Frames::addFrame);

    // Connects for frame buttons
    connect(this, &MainWindow::addNewFrame, &frames, &Frames::addNewFrame);
    connect(this, &MainWindow::deleteFrame, &frames, &Frames::deleteFrame);
    connect(this, &MainWindow::moveCurrFrame, &frames, &Frames::changeFrame);

    // DrawingWindow-related Connects
    connect(&dww, &drawingwindowwidget::colorPixel, &frames, &Frames::updateFrame);
    connect(&dww, &drawingwindowwidget::fillPixel, &frames, &Frames::bucketToolFrame);
    connect(&frames, &Frames::displayFrame, &dww, &drawingwindowwidget::displayCurrentFrame);

    // DELETE THESE
    connect(&dww, &drawingwindowwidget::colorChosen, this, &MainWindow::changePrimaryColor);
    connect(this, &MainWindow::currentColor, &dww, &drawingwindowwidget::setCurrentColor);
    connect(this, &MainWindow::colorPickerPicked, &dww, &drawingwindowwidget::colorPicked);
    connect(this, &MainWindow::startDrawing, &dww, &drawingwindowwidget::startDrawing);
    connect(this, &MainWindow::bucketPicked, &dww, &drawingwindowwidget::bucketPicked);

    // PreviewWindow-related Connects
    connect(&frames, &Frames::displayPreview, &pw, &PreviewWindow::displayPreviewFrame);

    // Frame list-related Connects
    connect(&frames, &Frames::displayInList, this, &MainWindow::displayInList);
    connect(&frames, &Frames::addFrameToList, this, &MainWindow::addFrameToList);
    connect(&frames, &Frames::removeFrameFromList, this, &MainWindow::removeFrameFromList);
    connect(&frames, &Frames::clearFrameList, this, &MainWindow::clearFrameList);

    // Animation preview-related Connects
    connect(&frames, &Frames::displayAnimFrame, popUp, &AnimationPopUp::displayAnimFrame);
    connect(popUp, &AnimationPopUp::playAnim, &frames, &Frames::playAllFrames);
    connect(popUp, &AnimationPopUp::stopAnim, &frames, &Frames::stopPlayingFrames);
    connect(this, &MainWindow::newFps, popUp, &AnimationPopUp::changeFramesPerSecond);

    // File-related Connects
    connect(this, &MainWindow::loadFile, &frames, &Frames::loadFile);
    connect(this, &MainWindow::saveFile, &frames, &Frames::saveFile);
    connect(this, &MainWindow::newFile, &frames, &Frames::newFile);
    connect(this, &MainWindow::saveAndNewFile, &frames, &Frames::saveAndNewFile);

    emit currentColor(primaryColor);

    // Pop up input dialogs grabbing the width and height from the user
    bool ok;
    int width = QInputDialog::getInt(this, tr("Width of Sprite Project"),
                                 tr("Width:"), 25, 1, 128, 1, &ok);
    int height = QInputDialog::getInt(this, tr("Height of Sprite Project"),
                                 tr("Height:"), 25, 1, 128, 1, &ok);

    // Make new frame of that width and height
    if (ok) {
        emit makeNewFrame(width, height);
    }

    this->layout()->addWidget(&dww);
    this->layout()->addWidget(&pw);

    ui->editDrawingWindow->setVisible(false);
    ui->brushButton->setEnabled(true);
    ui->framesListWidget->setIconSize(QSize(frameItemHeight, frameItemHeight));
    ui->fpsSpinBox->setValue(popUp->getFPS());
}

MainWindow::~MainWindow() {
    delete ui;
    delete popUp;
}

/// File Menu Methods

///
/// \brief Handles New file button press
///
void MainWindow::on_actionNew_triggered()
{
    QString filename = "";
    QMessageBox msgBox;
    msgBox.setText("Opening a new file will erase all progress.");
    msgBox.setInformativeText("Do you want to save your changes?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();

    // Dialogs to grab width & height from user
    bool ok;
    int width = QInputDialog::getInt(this, tr("Width of Sprite Project"),
                                 tr("Width:"), 25, 1, 128, 1, &ok);
    int height = QInputDialog::getInt(this, tr("Height of Sprite Project"),
                                 tr("Height:"), 25, 1, 128, 1, &ok);

    switch (ret) {
      case QMessageBox::Save: {
        // Make QString of file name with QFileDialog
        filename = QFileDialog::getSaveFileName(this,
                                                tr("Save Project"),
                                                "",
                                                tr("Sprite Project (*.ssp)"));
          emit saveAndNewFile(filename, width, height);
          break;
      }
      case QMessageBox::Discard:
          emit newFile(width, height);
          break;
      case QMessageBox::Cancel:
          // Cancel was clicked
          break;
      default:
          // Should never be reached
          break;
    }
}

///
/// \brief Handles Save file button press
///
void MainWindow::on_actionSave_triggered()
{
    // Make QString of file name with QFileDialog
    QString filename = QFileDialog::getSaveFileName(this,
                                                    tr("Save Project"),
                                                    "",
                                                    tr("Sprite Project (*.ssp)"));
    emit saveFile(filename);
}

///
/// \brief Handles Open file button press
///
void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open Sprite Project"),
                                                    QDir::homePath(),
                                                    tr("Sprite Project (*.ssp)"));
    emit loadFile(fileName);
}

///
/// \brief Handles Exit file button press
///
void MainWindow::on_actionExit_triggered()
{
    this->close();
}

/// End File Menu Methods

/// Animation Popup Methods

///
/// \brief Handles Play button press
///
void MainWindow::on_playPreviewButton_clicked()
{
    popUp->show();
    emit popUp->playAnim(popUp->getFPS());
}

///
/// \brief Handles change in frames per second
/// \param fps - Frames per second
///
void MainWindow::on_fpsSpinBox_valueChanged(int fps)
{
    emit newFps(fps);
}

/// Frame List Methods

///
/// \brief Handles Delete Frame button press
///
void MainWindow::on_deleteFrameButton_clicked()
{
    emit deleteFrame();
}

///
/// \brief Handles Add Frame button press
///
void MainWindow::on_addFrameButton_clicked()
{
    emit addNewFrame();
}

///
/// \brief Adds frame to widget list
/// \param frame - The frame to add
/// \param index - The index to add the frame to
///
void MainWindow::addFrameToList(QPixmap *frame, int index) {
    QListWidgetItem* item = new QListWidgetItem();
    QPixmap scaledFrame = frame->scaledToHeight(frameItemHeight);
    item->setIcon(QIcon(scaledFrame));
    ui->framesListWidget->insertItem(index, item);
}

///
/// \brief Adds frame to widget list
/// \param index - The index of the frame to remove
///
void MainWindow::removeFrameFromList(int index) {
    // Remove item from frame list widget
    QListWidgetItem* item = ui->framesListWidget->takeItem(index);
    // Clear up memory
    delete item;
}

///
/// \brief Displays frame in widget list
/// \param frame - The frame to display
/// \param index - The index of the frame
///
void MainWindow::displayInList(QPixmap *frame, int index) {
    QListWidgetItem* currItem = ui->framesListWidget->item(index);
    QPixmap scaledFrame = frame->scaledToHeight(frameItemHeight);
    currItem->setIcon(QIcon(scaledFrame));
}

///
/// \brief Clears the frame widget list
///
void MainWindow::clearFrameList() {
    ui->framesListWidget->clear();
}

///
/// \brief Handles frame up button press
///
void MainWindow::on_frameUpButton_clicked()
{
    emit moveCurrFrame(false);
}

///
/// \brief Handles frame down button press
///
void MainWindow::on_frameDownButton_clicked()
{
    emit moveCurrFrame(true);
}

/// Drawing Window Methods

///
/// \brief Displays frame in drawing window
/// \param frame - Frame to display
///
void MainWindow::displayFrame(QImage* frame) {
    ui->editDrawingWindow->setPixmap(QPixmap::fromImage(*frame));
    ui->editDrawingWindow->show();
}

/// Toolbar Methods

///
/// \brief Handles Brush button press
///
void MainWindow::on_brushButton_clicked()
{
    emit colorPickerPicked(false);
    emit bucketPicked(false);
    emit currentColor(primaryColor);
    selectButton(Tools::brush);
}

///
/// \brief Handles Eraser button press
///
void MainWindow::on_eraserButton_clicked()
{
    emit colorPickerPicked(false);
    emit bucketPicked(false);
    emit currentColor(eraserColor);
    selectButton(Tools::eraser);
}

///
/// \brief Handles Bucket button press
///
void MainWindow::on_bucketButton_clicked()
{
    emit colorPickerPicked(false);
    emit bucketPicked(true);
    selectButton(Tools::bucket);
}

///
/// \brief Handles Color Picker button press
///
void MainWindow::on_colorPickerButton_clicked()
{
    emit colorPickerPicked(true);
    emit bucketPicked(false);
    selectButton(Tools::colorPicker);
}

///
/// \brief Selects the given tool in the toolbar (and unselects other tools)
///
void MainWindow::selectButton(Tools tool) {
    // Tools unselected by default
    bool brushChecked = false, eraserChecked = false, pickerChecked = false, bucketChecked = false;

    // Get selected tool
    switch (tool) {
        case Tools::brush:
            brushChecked = true;
            break;
        case Tools::eraser:
            eraserChecked = true;
            break;
        case Tools::colorPicker:
            pickerChecked = true;
            break;
        case Tools::bucket:
            bucketChecked = true;
            break;
    }

    // Select tool in UI
    ui->brushButton->setChecked(brushChecked);
    ui->eraserButton->setChecked(eraserChecked);
    ui->colorPickerButton->setChecked(pickerChecked);
    ui->bucketButton->setChecked(bucketChecked);
}

///
/// \brief Handles Primary Color press
///
void MainWindow::on_primaryColorButton_clicked()
{
    primaryColor = QColorDialog::getColor(primaryColor, this, "Primary Color", QColorDialog::ShowAlphaChannel);
    ui->primaryColorButton->setStyleSheet("background-color: " + primaryColor.name() + ";border-style: none;");
    emit currentColor(primaryColor);
}

///
/// \brief Handles Secondary Color press
///
void MainWindow::on_secondaryColorButton_clicked()
{
    secondaryColor = QColorDialog::getColor(secondaryColor, this, "Secondary Color", QColorDialog::ShowAlphaChannel);
    ui->secondaryColorButton->setStyleSheet("background-color: " + secondaryColor.name() + ";border-style: none;");
}

///
/// \brief Handles Swap Colors button press
///
void MainWindow::on_swapColorButton_clicked()
{
    std::swap(primaryColor, secondaryColor);
    ui->primaryColorButton->setStyleSheet("background-color: " + primaryColor.name() + ";border-style: none;");
    ui->secondaryColorButton->setStyleSheet("background-color: " + secondaryColor.name() + ";border-style: none;");
    emit currentColor(primaryColor);
}

///
/// \brief Displays primary color in DrawingWindow
/// \param color - Color to display
///
void MainWindow::changePrimaryColor(QColor color) {
    primaryColor = color;
    ui->primaryColorButton->setStyleSheet("background-color: " + primaryColor.name() + ";border-style: none;");
    emit currentColor(primaryColor);
    selectButton(Tools::brush);
}

