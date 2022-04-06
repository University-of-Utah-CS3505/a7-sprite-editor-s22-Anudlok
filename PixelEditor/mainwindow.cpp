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
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{          
    Frames* frames = new Frames();
    DrawingWindow* dw = new DrawingWindow();
    PreviewWindow* pw = new PreviewWindow();

    // UI configuration at start of application
    this->ui->setupUi(this);

    popUp = new AnimationPopUp;

    primaryColor = Qt::black;
    secondaryColor = Qt::white;
    eraserColor = QColor(0, 0, 0, 0);

    this->layout()->addWidget(dw);
    this->layout()->addWidget(pw);

    ui->editDrawingWindow->setVisible(false);
    ui->brushButton->setEnabled(true);
    ui->framesListWidget->setIconSize(QSize(frameItemHeight, frameItemHeight));
    ui->fpsSpinBox->setValue(popUp->getFPS());
    ui->framesListWidget->setStyleSheet("QListWidget { background: white; }"
                                        "QListWidget::item { border: 3px solid black; "
                                        "background: rgba(0, 0, 0, 30);}"
                                        "QListWidget::item:selected { "
                                        "background: rgba(0, 0, 100, 20)}");

    // Connects for new file
    connect(this, &MainWindow::makeNewFrame, frames, &Frames::addFrameWithSize);

    // Connects for frame buttons
    connect(this, &MainWindow::addFrame, frames, &Frames::addFrame);
    connect(this, &MainWindow::deleteFrame, frames, &Frames::deleteFrame);
    connect(this, &MainWindow::moveCurrFrame, frames, &Frames::changeFrame);
    connect(this, &MainWindow::selectFrame, frames, &Frames::selectFrames);

    // DrawingWindow-related Connects
    connect(dw, &DrawingWindow::colorPixel, frames, &Frames::updateFrame);
    connect(dw, &DrawingWindow::fillPixel, frames, &Frames::bucketToolFrame);
    connect(frames, &Frames::displayFrame, dw, &DrawingWindow::displayCurrentFrame);

    // DELETE THESE
    connect(dw, &DrawingWindow::colorChosen, this, &MainWindow::changePrimaryColor);
    connect(this, &MainWindow::currentColor, dw, &DrawingWindow::setCurrentColor);
    connect(this, &MainWindow::colorPickerPicked, dw, &DrawingWindow::colorPicked);
    connect(this, &MainWindow::startDrawing, dw, &DrawingWindow::startDrawing);
    connect(this, &MainWindow::bucketPicked, dw, &DrawingWindow::bucketPicked);

    // PreviewWindow-related Connects
    connect(frames, &Frames::displayPreview, pw, &PreviewWindow::displayPreviewFrame);

    // Frame list-related Connects
    connect(frames, &Frames::displayInList, this, &MainWindow::displayInList);
    connect(frames, &Frames::addFrameToList, this, &MainWindow::addFrameToList);
    connect(frames, &Frames::removeFrameFromList, this, &MainWindow::removeFrameFromList);
    connect(frames, &Frames::clearFrameList, this, &MainWindow::clearFrameList);

    // Animation preview-related Connects
    connect(frames, &Frames::displayAnimFrame, popUp, &AnimationPopUp::displayAnimFrame);
    connect(popUp, &AnimationPopUp::playAnim, frames, &Frames::playAllFrames);
    connect(popUp, &AnimationPopUp::stopAnim, frames, &Frames::stopPlayingFrames);
    connect(this, &MainWindow::newFps, popUp, &AnimationPopUp::changeFramesPerSecond);

    // File-related Connects
    connect(this, &MainWindow::loadFile, frames, &Frames::loadFile);
    connect(this, &MainWindow::saveFile, frames, &Frames::saveFile);
    connect(this, &MainWindow::newFile, frames, &Frames::newFile);
    connect(this, &MainWindow::saveAndNewFile, frames, &Frames::saveAndNewFile);

    emit currentColor(primaryColor);

    // Pop up input dialogs grabbing the width and height from the user
    bool ok;
    int width = QInputDialog::getInt(this, tr("Size of Sprite Project"),
                                 tr("Width and Height:"), 32, 1, 128, 1, &ok);
    int height = width;

    // Make new frame of that width and height
    if (ok) {
        emit makeNewFrame(width, height);
    }
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
    int width = QInputDialog::getInt(this, tr("Size of Sprite Project"),
                                 tr("Width and Height:"), 32, 1, 128, 1, &ok);
    int height = width;

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

    QString filename = "";
    QMessageBox msgBox;
    msgBox.setText("You have unsaved changes.");
    msgBox.setInformativeText("Do you want to save your changes before opening another project?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();

    switch (ret) {
      case QMessageBox::Save: {
        // Make QString of file name with QFileDialog
        filename = QFileDialog::getSaveFileName(this,
                                                tr("Save Project"),
                                                "",
                                                tr("Sprite Project (*.ssp)"));
          emit saveFile(filename);

          QString fileName = QFileDialog::getOpenFileName(this,
                                                        tr("Open Sprite Project"),
                                                        QDir::homePath(),
                                                        tr("Sprite Project (*.ssp)"));
          emit loadFile(fileName);
          break;
      }
      case QMessageBox::Cancel:
          // Cancel was clicked
          break;
      default:
          // Should never be reached
          break;
    }
}

///
/// \brief Handles Exit file button press
///
void MainWindow::on_actionExit_triggered()
{

    QString filename = "";
    QMessageBox msgBox;
    msgBox.setText("You have unsaved changes.");
    msgBox.setInformativeText("Do you want to save your changes before exiting?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();

    switch (ret) {
      case QMessageBox::Save: {
        // Make QString of file name with QFileDialog
        filename = QFileDialog::getSaveFileName(this,
                                                tr("Save Project"),
                                                "",
                                                tr("Sprite Project (*.ssp)"));
          emit saveFile(filename);

          this->close();
          break;
      }
      case QMessageBox::Cancel:
          // Cancel was clicked
          break;
      default:
          // Should never be reached
          break;
    }
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
    emit addFrame();
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
    ui->framesListWidget->setCurrentItem(item);
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
    QListWidgetItem *current = ui->framesListWidget->currentItem();
    int nextIndex = ui->framesListWidget->row(current) - 1;
    if (nextIndex > -1) {
        QListWidgetItem *next = ui->framesListWidget->item(nextIndex);
        ui->framesListWidget->setCurrentItem(next);
    }
    emit moveCurrFrame(false);
}

///
/// \brief Handles frame down button press
///
void MainWindow::on_frameDownButton_clicked()
{
    QListWidgetItem *current = ui->framesListWidget->currentItem();
    int nextIndex = ui->framesListWidget->row(current) + 1;
    if (nextIndex < ui->framesListWidget->count()) {
        QListWidgetItem *next = ui->framesListWidget->item(nextIndex);
        ui->framesListWidget->setCurrentItem(next);
    }
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


void MainWindow::on_actionCredits_triggered()
{
    QMessageBox msgBox;
    msgBox.setText("<h1>Credits:</h1>");
    msgBox.setInformativeText("<h2>Design and programming:</h2><br>"
                              "Anna Timofeyenko<br>"
                              "Gabby Culley<br>"
                              "Gaby Torres<br>"
                              "Raynard Christian<br>"
                              "<br>"
                              "<h2>Icons</h2> (by <a target=\"_blank\" href=\"https://icons8.com/\">Icons8</a>):<br>"
                              "<a target=\"_blank\" href=\"https://icons8.com/icon/11815/add-file\">Add File icon by Icons8</a><br>"
                              "<a target=\"_blank\" href=\"https://icons8.com/icon/13279/save\">Save icon icon by Icons8</a><br>"
                              "<a target=\"_blank\" href=\"https://icons8.com/icon/12941/paint\">Opened Folder icon by Icons8</a><br>"
                              "<a target=\"_blank\" href=\"https://icons8.com/icon/13903/close-window\">Close Window icon by Icons8</a><br>"
                              "<a target=\"_blank\" href=\"https://icons8.com/icon/12941/paint\">Paint icon by Icons8</a><br>"
                              "<a target=\"_blank\" href=\"https://icons8.com/icon/18705/erase\">Erase icon by Icons8</a><br>"
                              "<a target=\"_blank\" href=\"https://icons8.com/icon/12937/fill-color\">Fill Color icon by Icons8</a><br>"
                              "<a target=\"_blank\" href=\"https://icons8.com/icon/11888/color-dropper\">Color Dropper icon by Icons8</a><br>"
                              "<a target=\"_blank\" href=\"https://icons8.com/icon/19041/curved-arrow\">Curved Arrow icon by Icons8</a><br>"
                              "<a target=\"_blank\" href=\"https://icons8.com/icon/63671/circled-play\">Circled Play icon by Icons8</a><br>"
                              "<a target=\"_blank\" href=\"https://icons8.com/icon/11816/add-image\">Add Image icon by Icons8</a><br>"
                              "<a target=\"_blank\" href=\"https://icons8.com/icon/13066/remove-image\">Remove Image icon by Icons8</a><br>"
                              "<a target=\"_blank\" href=\"https://icons8.com/icon/19162/sort-up\">Sort Up icon by Icons8</a><br>"
                              "<a target=\"_blank\" href=\"https://icons8.com/icon/19161/sort-down\">Sort Down icon by Icons8</a><br>");
    msgBox.exec();
}


void MainWindow::on_framesListWidget_itemPressed(QListWidgetItem *item)
{
    int index = ui->framesListWidget->row(item);
    emit selectFrame(index);
}

