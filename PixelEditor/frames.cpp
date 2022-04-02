#include "frames.h"
#include <QImage>
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

Frames::Frames(QObject *parent)
    : QObject{parent}
{

}

void Frames::setWidthAndHeight(int _width, int _height) {
    width = _width;
    height = _height;
}

void Frames::clearFrame() {
    frameList[currentFrame].fill(QColor(0, 0, 0, 0));
    emit displayFrame(&(frameList[currentFrame]), width, height);
    emit displayPreview(&(frameList[currentFrame]));
}

void Frames::addFrame(int _width, int _height){
    setWidthAndHeight(_width, _height);
    QImage image = QImage(width, height, QImage::Format_ARGB32);
    image.fill(QColor(0, 0, 0, 0));
    frameList.append(image);
    currentFrame += 1;
    emit displayFrame(&(frameList[currentFrame]), width, height);
    emit displayPreview(&(frameList[currentFrame]));
}

void Frames::addFrameWithFrame(QImage frame){
    frameList.append(frame);
    currentFrame += 1;
    emit displayFrame(&(frameList[currentFrame]), width, height);
    emit displayPreview(&(frameList[currentFrame]));
}

void Frames::deleteFrame() {
    int deleteFrameIndex = currentFrame;
    frameList.removeAt(deleteFrameIndex);
}

void Frames::deleteFrameAt(int index){
    frameList.removeAt(index);
}

void Frames::updateFrame(QColor color, int row, int column) {
    frameList[currentFrame].setPixelColor(row, column, color);
    emit displayFrame(&frameList[currentFrame], width, height);
    emit displayPreview(&(frameList[currentFrame]));
}

void Frames::changeFrame(bool upOrDown) {
    if (upOrDown) {
        currentFrame += 1;
    }
    else {
        currentFrame -= 1;
    }
    emit displayFrame(&(frameList[currentFrame]), width, height);
    emit displayPreview(&(frameList[currentFrame]));
}

void Frames::playAllFrames() {

}

void Frames::saveFile(QString fileName) {
    // Make a QFile with that
    QFile file(fileName);

    // Create the JSON objects
     QJsonObject obj;
     obj["height"] = height;
     obj["width"] = width;
     obj["numberOfFrames"] = frameList.size();
     QJsonArray frames;

     // Build up array of rows which have arrays of pixels which have arrays of rgba 0-255
  //   QJsonObject listOfFrames = objectName()["frames"];


     // Iterate through list of frames
  //   foreach(const QJsonValue &frame, listOfFrames) {

   //      // Create a array of rows for each frame
  //       QJsonArray rows = frame.toArray();

         // Iterate through the rows
   //      for(int row = 0; row < rows.size(); row++) {
             // Create a array of RGBA values for each pixel
   //          QJsonArray pixels = rows[row].toArray();

             // Iterate through the pixels in each row
    //         for (int pixel = 0; pixel < pixels.size(); pixel++) {
                 //Grab the color of the pixel and put it inside a array

                 // grab the column and row (pixel, row)


              //   // Create a rgba of the array within a pixel
              //   QJsonArray RGBAColors = pixels[pixel].toArray();
              //   QColor color(RGBAColors[0].toInt(), RGBAColors[1].toInt(), RGBAColors[2].toInt(), RGBAColors[3].toInt());
               //  image.setPixelColor(pixel, row, color);
    //         }

 //        }

     obj["frames"] = frames;


    // Use ReadWrite of the file to grab info from the current framesList of the project and write that

    file.close();
}

void Frames::loadFile(QString fileName) {
    if (fileName.isEmpty()) {
        return;
    }
    else {
        frameList.clear();

        // Make a new file
        QFile file(fileName);

        // If there is a error reading in the file, pop up a window
        if(!file.open(QIODevice::ReadOnly)) {
            QMessageBox::information(0, "Error reading file.", file.errorString());
        }

        QByteArray array = file.readAll();
        QJsonDocument doc(QJsonDocument::fromJson(array));

        height = doc["height"].toInt();
        width = doc["width"].toInt();
        int maxFrames = doc["numberOfFrames"].toInt();
        QJsonObject listOfFrames = doc["frames"].toObject();
        std::vector<QImage> allFrames;

        // Iterate through list of frames
        foreach(const QJsonValue &frame, listOfFrames) {
            // Create a frame
            QImage image (height, width, QImage::Format_RGB32);

            // Create a array of rows for each frame
            QJsonArray rows = frame.toArray();

            // Iterate through the rows
            for(int row = 0; row < rows.size(); row++) {
                // Create a array of RGBA values for each pixel
                QJsonArray pixels = rows[row].toArray();

                // Iterate through the pixels in each row
                for (int pixel = 0; pixel < pixels.size(); pixel++) {
                    // Create a rgba of the array within a pixel
                    QJsonArray RGBAColors = pixels[pixel].toArray();
                    QColor color(RGBAColors[0].toInt(), RGBAColors[1].toInt(), RGBAColors[2].toInt(), RGBAColors[3].toInt());
                    image.setPixelColor(pixel, row, color);
                }

            }
            frameList.push_back(image);

            //put all the frames in the wiidgetList
      //      QPixmap framePixMap = QPixmap::fromImage(image);
      //      QIcon frameIcon(framePixMap);
     //       QListWidgetItem item;
     //       item.setIcon(frameIcon);
    //        widgetList.push_back(item);
        }

        currentFrame = 0;
        emit displayFrame(&(frameList[currentFrame]), width, height);

        file.close();
    }
}

 void Frames::newFile(int width, int height) {
     currentFrame = -1;
     frameList.clear();

     //need pop up and then put the height and width inside addFrame
     addFrame(width, height);
 }

 void Frames::saveAndNewFile(QString filename, int width, int height) {
     saveFile(filename);
     newFile(width, height);
 }

 void Frames::resetWindow() {
      addFrame(width, height);
 }
