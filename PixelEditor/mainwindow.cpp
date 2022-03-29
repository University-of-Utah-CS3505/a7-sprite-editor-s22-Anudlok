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
#include <QtDebug>


/**
 * @brief MainWindow::MainWindow The View Class
 * @param parent
 */
MainWindow::MainWindow(Frames& frames, drawingwindow& dw, drawingwindowwidget& dww, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&frames, &Frames::displayFrame, &dww, &drawingwindowwidget::displayCurrentFrame);
    connect(this, &MainWindow::makeNewFrame, &frames, &Frames::addFrame);
    connect(&frames, &Frames::widthAndHeight, &dww, &drawingwindowwidget::setWidthAndHeight);
    connect(&dww, &drawingwindowwidget::getWidthAndHeight, &frames, &Frames::getWidthAndHeight);
    this->layout()->addWidget(&dww);
    ui->editDrawingWindow->setVisible(false);
}


MainWindow::~MainWindow()
{
    delete ui;
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

//FrameList View Slots
void MainWindow::on_framesListWidget_itemDoubleClicked(QListWidgetItem *item)
{
   QImage clickedFrame;

   //I need the width and height from the frames class
   int width = 25;
   int height = 25;

   QPixmap framePixMap = item->icon().pixmap(width, height, QIcon::Mode(0),QIcon::State(0));
   clickedFrame = framePixMap.toImage(); //this will compile but the internet says that it
                                         //won't display with the same alpha, whatever that means
   emit currentFrameChanged(&clickedFrame);
}

void MainWindow::on_framesListWidget_itemActivated(QListWidgetItem *item)
{
    //temporary until we can find a way to get the frameslist
    std::vector<QImage> frameslist;

    //goes through each frame in the frames list and adds it to list widget
    for(unsigned int i = 0;i < frameslist.size(); i++){
        QImage frame  = frameslist.at(i);
        QPixmap framePixMap = QPixmap::fromImage(frame);
        QIcon frameIcon(framePixMap);
        QListWidgetItem newWidgetItem;
        newWidgetItem.setIcon(frameIcon);
        ui->framesListWidget->addItem(&newWidgetItem);
    }

}

void MainWindow::on_btnTest_clicked()
{
    emit makeNewFrame();
}

void MainWindow::displayFrame(QImage* frame) {
    ui->editDrawingWindow->setPixmap(QPixmap::fromImage(*frame));
    ui->editDrawingWindow->show();
}

void MainWindow::on_brushButton_clicked()
{
    qDebug() << "help";
    selectButton(Toolbar::Tools::brush);
}


void MainWindow::on_eraserButton_clicked()
{
    selectButton(Toolbar::Tools::eraser);
}


void MainWindow::on_bucketButton_clicked()
{
    selectButton(Toolbar::Tools::bucket);
}


void MainWindow::on_colorPickerButton_clicked()
{
    selectButton(Toolbar::Tools::colorPicker);
}


void MainWindow::on_selectButton_clicked()
{
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

void MainWindow::on_editDrawingWindow_linkActivated(const QString &link)
{

}

