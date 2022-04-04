#include <QMessageBox>
#include <vector>
#include <QFile>
#include <QFileDialog>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QRgb>
#include <QImage>
#include <QVector>
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QColorDialog>
#include <QInputDialog>


/**
 * @brief MainWindow::MainWindow The View Class
 * @param parent
 */
MainWindow::MainWindow(PreviewWindow& pw, Frames& frames, drawingwindow& dw,
                       drawingwindowwidget& dww, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    popUp = new AnimationPopUp;

    primaryColor = Qt::black;
    secondaryColor = Qt::white;
    eraser = QColor(0, 0, 0, 0);


    connect(&frames, &Frames::displayFrame, &dww, &drawingwindowwidget::displayCurrentFrame);
    connect(this, &MainWindow::makeNewFrame, &frames, &Frames::addFrame);
    connect(this, &MainWindow::addNewFrame, &frames, &Frames::addNewFrame);
    connect(&dww, &drawingwindowwidget::colorPixel, &frames, &Frames::updateFrame);
    connect(this, &MainWindow::currentColor, &dww, &drawingwindowwidget::setCurrentColor);
    connect(this, &MainWindow::colorPickerPicked, &dww, &drawingwindowwidget::colorPicked);
    connect(&dww, &drawingwindowwidget::colorChosen, this, &MainWindow::changePrimaryColor);
    connect(this, &MainWindow::startDrawing, &dww, &drawingwindowwidget::startDrawing);
    connect(this, &MainWindow::clearScreen, &frames, &Frames::clearFrame);
    connect(&frames, &Frames::displayPreview, &pw, &PreviewWindow::displayPreviewFrame);
    connect(this, &MainWindow::requestFrame, &pw, &PreviewWindow::requestForWindow);
    //connect(&pw, &PreviewWindow::sendWindow, this, &MainWindow::addToFrames);
    connect(this, &MainWindow::deleteFrame, &frames, &Frames::deleteFrame);
    connect(this, &MainWindow::currentFrameChanged, &frames, &Frames::addFrameWithFrame);
    connect(this, &MainWindow::moveCurrFrame, &frames, &Frames::changeFrame);

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

    // Reset Drawing Window with the height and width already in the project
    connect(this, &MainWindow::resetWindow, &frames, &Frames::resetWindow);

    emit currentColor(primaryColor);

    // This code block pops up a input dialog grabbing the width and height from the user
    bool ok;
    int width = QInputDialog::getInt(this, tr("Width of Sprite Project"),
                                 tr("Width:"), 25, 1, 400, 1, &ok);
    int height = QInputDialog::getInt(this, tr("Height of Sprite Project"),
                                 tr("Height:"), 25, 1, 400, 1, &ok);
    if (ok) {
            emit makeNewFrame(width, height);
    }

    this->layout()->addWidget(&dww);
    this->layout()->addWidget(&pw);

    ui->editDrawingWindow->setVisible(false);
    ui->brushButton->setEnabled(true);
}


MainWindow::~MainWindow()
{
    delete ui;
    delete popUp;
}

/// File Menu Methods
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

    // This code block pops up a input dialog grabbing the width and height from the user
    bool ok;
    int width = QInputDialog::getInt(this, tr("Width of Sprite Project"),
                                 tr("Width:"), 25, 1, 400, 1, &ok);
    int height = QInputDialog::getInt(this, tr("Height of Sprite Project"),
                                 tr("Height:"), 25, 1, 400, 1, &ok);

    switch (ret) {
      case QMessageBox::Save: {
        // Make a QString of file name using QFile Dialog
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
          // should never be reached
          break;
    }
}


void MainWindow::on_actionSave_triggered()
{
    // Make a QString of file name using QFile Dialog
    QString filename = QFileDialog::getSaveFileName(this,
                                                    tr("Save Project"),
                                                    "",
                                                    tr("Sprite Project (*.ssp)"));
    emit saveFile(filename);
}


void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open Sprite Project"),
                                                    QDir::homePath(),
                                                    tr("Sprite Project (*.ssp)"));
    emit loadFile(fileName);
}


void MainWindow::on_actionExit_triggered()
{
        this->close();
}


/// End File Menu Methods
void MainWindow::on_playPreviewButton_clicked()
{
    popUp->show();
    emit popUp->playAnim(24);
}
/**
void MainWindow::on_framesListWidget_itemActivated(QListWidgetItem *item)
{
    //comment for future debugging, possible error bc idk what i'm doing tbh
    ui->framesListWidget->addItem(item);
    //goes through each frame in the frames list and adds it to list widget
    for(QListWidgetItem item : widgetList){
        ui->framesListWidget->addItem(&item);
    }
}
**/

void MainWindow::on_deleteFrameButton_clicked()
{
    emit deleteFrame();
//    widgetList.erase(widgetList.begin() + currFrame);
//    if (currFrame > 0) {
//        currFrame--;
//    }
}


void MainWindow::on_addFrameButton_clicked()
{
    emit addNewFrame();
    QListWidgetItem item;
    ui->framesListWidget->addItem(&item);

   // ui->framesListWidget->addItem(&item);
    //ui->framesListWidget->addItem()
    //get the current frame pixmap
    //make a QListWidgetItem
    //add item to QList
}

void MainWindow::displayInList(QPixmap *frame, int index){
    QListWidgetItem currItem = *(ui->framesListWidget->item(index));
    QIcon icon(*frame);
    currItem.setIcon(icon);
}

void MainWindow::on_frameLeftButton_clicked()
{
   // currFrame = (currFrame-1) % widgetList.size();
    emit moveCurrFrame(false);
}


void MainWindow::on_frameRightButton_clicked()
{
  //  currFrame = (currFrame + 1) % widgetList.size();
    emit moveCurrFrame(true);
}


void MainWindow::on_btnTest_clicked()
{
    emit resetWindow();
    emit startDrawing();
}

void MainWindow::displayFrame(QImage* frame) {
    ui->editDrawingWindow->setPixmap(QPixmap::fromImage(*frame));
    ui->editDrawingWindow->show();
}

void MainWindow::on_brushButton_clicked()
{
    emit colorPickerPicked(false);
    emit currentColor(primaryColor);
    selectButton(Toolbar::Tools::brush);
}


void MainWindow::on_eraserButton_clicked()
{
    emit colorPickerPicked(false);
    emit currentColor(eraser);
    selectButton(Toolbar::Tools::eraser);
}


void MainWindow::on_bucketButton_clicked()
{
    emit colorPickerPicked(false);
    selectButton(Toolbar::Tools::bucket);
}


void MainWindow::on_colorPickerButton_clicked()
{
    emit colorPickerPicked(true);
    selectButton(Toolbar::Tools::colorPicker);
}


void MainWindow::on_selectButton_clicked()
{
    emit colorPickerPicked(false);
    selectButton(Toolbar::Tools::select);
}

void MainWindow::selectButton(Toolbar::Tools tool) {
    toolbar.switchTool(tool);

    bool brushChecked = false, eraserChecked = false, pickerChecked = false, bucketChecked = false, selectChecked = false;

    switch (tool) {
        case Toolbar::Tools::brush:
            brushChecked = true;
            break;
        case Toolbar::Tools::eraser:
            eraserChecked = true;
            break;
        case Toolbar::Tools::colorPicker:
            pickerChecked = true;
            break;
        case Toolbar::Tools::bucket:
            bucketChecked = true;
            break;
        case Toolbar::Tools::select:
            selectChecked = true;
            break;
    }

    ui->brushButton->setChecked(brushChecked);
    ui->eraserButton->setChecked(eraserChecked);
    ui->colorPickerButton->setChecked(pickerChecked);
    ui->bucketButton->setChecked(bucketChecked);
    ui->selectButton->setChecked(selectChecked);
}

void MainWindow::on_primaryColorButton_clicked()
{
    primaryColor = QColorDialog::getColor(primaryColor, this, "Primary Color", QColorDialog::ShowAlphaChannel);
    ui->primaryColorButton->setStyleSheet("background-color: " + primaryColor.name() + ";border-style: none;");
    emit currentColor(primaryColor);
}

void MainWindow::on_secondaryColorButton_clicked()
{
    secondaryColor = QColorDialog::getColor(secondaryColor, this, "Secondary Color", QColorDialog::ShowAlphaChannel);
    ui->secondaryColorButton->setStyleSheet("background-color: " + secondaryColor.name() + ";border-style: none;");
}

void MainWindow::on_swapColorButton_clicked()
{
    std::swap(primaryColor, secondaryColor);
    ui->primaryColorButton->setStyleSheet("background-color: " + primaryColor.name() + ";border-style: none;");
    ui->secondaryColorButton->setStyleSheet("background-color: " + secondaryColor.name() + ";border-style: none;");
    emit currentColor(primaryColor);
}

void MainWindow::changePrimaryColor(QColor color) {
    primaryColor = color;
    ui->primaryColorButton->setStyleSheet("background-color: " + primaryColor.name() + ";border-style: none;");
    emit currentColor(primaryColor);
    selectButton(Toolbar::Tools::brush);
}

void MainWindow::on_btnClear_clicked()
{
    emit clearScreen();
}



void MainWindow::on_fpsSpinBox_valueChanged(int fps)
{
    emit newFps(fps);
}

