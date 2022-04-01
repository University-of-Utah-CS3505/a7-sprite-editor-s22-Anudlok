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


/**
 * @brief MainWindow::MainWindow The View Class
 * @param parent
 */
MainWindow::MainWindow(AnimationPopUp& aw ,PreviewWindow& pw, Frames& frames, drawingwindow& dw,
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
    connect(&dww, &drawingwindowwidget::colorPixel, &frames, &Frames::updateFrame);
    connect(this, &MainWindow::currentColor, &dww, &drawingwindowwidget::setCurrentColor);
    connect(this, &MainWindow::colorPickerPicked, &dww, &drawingwindowwidget::colorPicked);
    connect(&dww, &drawingwindowwidget::colorChosen, this, &MainWindow::changePrimaryColor);
    connect(this, &MainWindow::startDrawing, &dww, &drawingwindowwidget::startDrawing);
    connect(this, &MainWindow::clearScreen, &frames, &Frames::clearFrame);
    connect(&frames, &Frames::displayPreview, &pw, &PreviewWindow::displayPreviewFrame);
    connect(this, &MainWindow::animateFrames, &aw, &AnimationPopUp::playPreviewClick);
    connect(this, &MainWindow::requestFrame, &pw, &PreviewWindow::requestForWindow);
    connect(&pw, &PreviewWindow::sendWindow, this, &MainWindow::addToFrames);
    connect(this, &MainWindow::deleteFrameAt, &frames, &Frames::deleteFrameAt);
    connect(this, &MainWindow::currentFrameChanged, &frames, &Frames::addFrameWithFrame);
    connect(this, &MainWindow::moveCurrFrame, &frames, &Frames::changeFrame);


    emit currentColor(primaryColor);

    this->layout()->addWidget(&dww);
    this->layout()->addWidget(&pw);

    ui->editDrawingWindow->setVisible(false);
    ui->brushButton->setEnabled(true);
    ui->sbWidth->setValue(1);
    ui->sbHeight->setValue(1);
    ui->btnClear->setEnabled(false);
}


MainWindow::~MainWindow()
{
    delete ui;
    delete popUp;
}

/// File Menu Methods

void MainWindow::saveFile() {
    // Make a QString of file name using QFile Dialog
    QString filename = QFileDialog::getSaveFileName(this,
                                                    tr("Save Project"), QDir::homePath(), ".SSP Files (*.ssp)");

    // Make a QFile with that
    QFile file(filename);

     QJsonObject obj;
  //   obj["height"] = height;
  //   obj["width"] = width;
  //   obj["numberOfFrames"] = vector list . size;
     QJsonArray frames;

     // Build up array of rows which have arrays of pixels which have arrays of rgba 0-255

     obj["frames"] = frames;


    // Use ReadWrite of the file to grab info from the current framesList of the project and write that

    file.close();
}

void MainWindow::loadFile(QString fileName){
    if (fileName.isEmpty()) {
        return;
    }
    else {
        // Make a new file
        QFile file(fileName);

        // If there is a error reading in the file, pop up a window
        if(!file.open(QIODevice::ReadOnly)) {
            QMessageBox::information(0, "Error reading file.", file.errorString());
        }

        QByteArray array = file.readAll();
        QJsonDocument doc(QJsonDocument::fromJson(array));

        int height = doc["height"].toInt();
        int width = doc["width"].toInt();
        int maxFrames = doc["numberOfFrames"].toInt();
        QJsonArray listOfFrames = doc["frames"].toArray();
        std::vector<QImage> allFrames;

        // Iterate through list of frames
        for(int frame = 0; frame < maxFrames; frame++) {
            // Create a frame
            QImage image (height, width, QImage::Format_RGB32);

            // Create a array of rows for each frame
            QJsonArray rows = listOfFrames[frame].toArray();

            // Iterate through the rows
            for(int row = 0; row < rows.size(); row++) {
                // Create a array of RGBA values for each pixel
                QJsonArray pixels = rows[row].toArray();

                // Iterate through the pixels in each row
                for (int pixel = 0; pixel < pixels.size(); pixel++) {
                    // Create a rgba of the array within a pixel
                    QJsonArray RGBAColors = pixels[pixel].toArray();
                    QRgb value = qRgba(RGBAColors[0].toInt(), RGBAColors[1].toInt(), RGBAColors[2].toInt(), RGBAColors[3].toInt());

                    image.setPixel(pixel, row, value);
                }

            }
            //Make a frames object by calling in the height and width and numberOfFrames then call the addFrame method on that object

            allFrames.push_back(image);

            //put all the frames in the wiidgetList
            QPixmap framePixMap = QPixmap::fromImage(image);
            QIcon frameIcon(framePixMap);
            QListWidgetItem item;
            item.setIcon(frameIcon);
            widgetList.push_back(item);
        }

        file.close();
    }
}

void MainWindow::newFile(){

    // Make a pop up of height and width every time a new project is open
}


void MainWindow::on_actionNew_triggered()
{
    QMessageBox msgBox;
    msgBox.setText("Opening a new file will erase all progress.");
    msgBox.setInformativeText("Do you want to save your changes?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();

    switch (ret) {
      case QMessageBox::Save:
          saveFile();
          break;
      case QMessageBox::Discard:
          newFile();
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
    saveFile();
}


void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Sprite Project"), tr("Sprite Project (*.ssp)"));

    loadFile(fileName);
}


void MainWindow::on_actionExit_triggered()
{
        this->close();
}

/// End File Menu Methods


void MainWindow::on_framesListWidget_itemActivated(QListWidgetItem *item)
{
    //comment for future debugging, possible error bc idk what i'm doing tbh
    ui->framesListWidget->addItem(item);
    //goes through each frame in the frames list and adds it to list widget
    for(QListWidgetItem item : widgetList){
        ui->framesListWidget->addItem(&item);
    }
}

void MainWindow::on_deleteFrameButton_clicked()
{
    emit deleteFrameAt(currFrame);
    widgetList.erase(widgetList.begin() + currFrame);
    currFrame--;
}


void MainWindow::on_addFrameButton_clicked()
{
    emit requestFrame();
}

void MainWindow::addToFrames(QPixmap *frame){
    QIcon frameIcon(*frame);
    QListWidgetItem item;
    QImage clickedFrame;

    item.setIcon(frameIcon);
    widgetList.push_back(item);
    currFrame++;
    clickedFrame = frame->toImage();
    emit currentFrameChanged(clickedFrame);
}

void MainWindow::on_frameLeftButton_clicked()
{
    if(currFrame > 0){
        currFrame--;
        emit moveCurrFrame(false);
    }
}


void MainWindow::on_frameRightButton_clicked()
{
    if(currFrame < widgetList.size()-1){
        currFrame++;
        emit moveCurrFrame(true);
    }
}


void MainWindow::on_btnTest_clicked()
{
    int width = ui->sbWidth->value();
    int height = ui->sbHeight->value();

    emit makeNewFrame(width, height);
    emit requestFrame();
    emit startDrawing();
    ui->btnClear->setEnabled(true);
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


void MainWindow::on_playPreviewButton_clicked()
{
    popUp->show();
    emit animateFrames(widgetList);
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


