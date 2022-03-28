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


/**
 * @brief MainWindow::MainWindow The View Class
 * @param parent
 */
MainWindow::MainWindow(Frames& frames, drawingwindow& dw, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&frames, &Frames::displayFrame, &dw, &drawingwindow::displayCurrentFrame);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateCurrFrameLeft(int currFrameIndex, std::vector<QImage> frames){
    //QGraphicsScene scene = new QGraphicsScene(this);
    QPixmap nextImage;
    if(currFrameIndex > 0){
        nextImage = QPixmap::fromImage(frames.at(currFrameIndex--));
    } else {
       nextImage = QPixmap::fromImage(frames.at(currFrameIndex));
    }
    QIcon icon(nextImage);
    emit icon;
}

void MainWindow::updateCurrFrameRight(int currFrameIndex, std::vector<QImage> frames){
    //QGraphicsScene scene = new QGraphicsScene(this);
    QPixmap nextImage;
    if(currFrameIndex < frames.size() -1){
        nextImage = QPixmap::fromImage(frames.at(currFrameIndex++));
    } else {
       nextImage = QPixmap::fromImage(frames.at(currFrameIndex));
    }
    QIcon icon(nextImage);
    emit icon;
}

void MainWindow::prevFrameViewChanged(const QIcon &icon)
{ //SLOT FOR GUI
    QGraphicsScene scene = new QGraphicsScene(this);
    //ok so i still need to find a way to get the pixmap from this icon and put it into the GUI
    ui->prevFrameView->setScene(&scene);

}


void MainWindow::currFrameViewChanged(const QIcon &icon)
{ //SLOT FOR GUI
    QGraphicsScene scene = new QGraphicsScene(this);
    //ok so i still need to find a way to get the pixmap from this icon and put it into the GUI
    ui->prevFrameView->setScene(&scene);
}


void MainWindow::nextFrameViewChanged(const QIcon &icon)
{ //SLOT FOR GUI
    QGraphicsScene scene = new QGraphicsScene(this);
    //ok so i still need to find a way to get the pixmap from this icon and put it into the GUI
    ui->prevFrameView->setScene(&scene);
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

