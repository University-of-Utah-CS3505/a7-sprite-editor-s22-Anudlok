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
#include <QTimer>

Frames::Frames(QObject *parent)
    : QObject{parent}
{

}

void Frames::setWidthAndHeight(int _width, int _height) {
    width = _width;
    height = _height;
}

void Frames::updateView() {
    if (currentFrame > 0) {
        emit displayFrame(&(frameList[currentFrame]), &(frameList[currentFrame - 1]), width, height);
    }
    else {
        emit displayFrame(&(frameList[currentFrame]), &(frameList[currentFrame]), width, height);
    }
    emit displayPreview(&(frameList[currentFrame]));
}

void Frames::updateViewFrameList() {
    QPixmap pxMap = QPixmap::fromImage(frameList[currentFrame]);
    emit displayInList(&pxMap, currentFrame);
}

void Frames::addToFrameList() {
    QPixmap pxMap = QPixmap::fromImage(frameList[currentFrame]);
    emit addFrameToList(&pxMap, currentFrame);
}

void Frames::removeFromFrameList(int deletedFrame) {
    emit removeFrameFromList(deletedFrame);
}

//void Frames::clearFrame() {
//    frameList[currentFrame].fill(QColor(0, 0, 0, 0));

//    updateView();
//    updateViewFrameList();
//}

void Frames::addFrame(int _width, int _height){
    setWidthAndHeight(_width, _height);
    addNewFrame();
}

void Frames::addNewFrame() {
    QImage image = QImage(width, height, QImage::Format_ARGB32);
    image.fill(QColor(0, 0, 0, 0));
    frameList.insert(currentFrame + 1, image);
    currentFrame += 1;

    updateView();
    addToFrameList();
}

void Frames::deleteFrame() {
    int deleteFrameIndex = currentFrame;

    // If deleted frame is last frame, change frame displayed
    if (currentFrame == frameList.size() - 1) {
        currentFrame--;
    }

    frameList.removeAt(deleteFrameIndex);
    removeFromFrameList(deleteFrameIndex);

    // Frame list should never be empty
    if (frameList.empty()) {
        addNewFrame();
    }
    else {
        updateView();
    }
}

void Frames::updateFrame(QColor color, int row, int column) {
    frameList[currentFrame].setPixelColor(row, column, color);
    updateView();
    updateViewFrameList();
}

void Frames::bucketToolFrame(QColor color, int row, int column) {
    QColor colorToChange = frameList[currentFrame].pixelColor(row, column);
    QVector<QPair<int, int>> list;
    list.append({row, column});
    frameList[currentFrame].setPixelColor(row, column, color);

    QPair<int, int> currentPair;
    while (list.length() > 0) {
        currentPair = list.takeFirst();
        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                if ((i != j) && (j == 0 || i == 0)) {
                    int rowToAdd = currentPair.first + i;
                    int columnToAdd = currentPair.second + j;
                    if ((rowToAdd >= 0 && rowToAdd < width) && (columnToAdd >= 0 && columnToAdd < height)) {
                        if (frameList[currentFrame].pixelColor(rowToAdd, columnToAdd) == colorToChange
                            && frameList[currentFrame].pixelColor(rowToAdd, columnToAdd) != color) {
                            frameList[currentFrame].setPixelColor(rowToAdd, columnToAdd, color);
                            QPair<int, int> newPair(rowToAdd, columnToAdd);
                            list.push_front(newPair);
                        }
                    }
                }
            }
        }

    }
    updateView();
    updateViewFrameList();
}

void Frames::changeFrame(bool upOrDown) {
    if (upOrDown) {
       if(currentFrame < frameList.size()-1){
            currentFrame += 1;
       }
    }
    else {
        if(currentFrame > 0){
            currentFrame -= 1;
        }
    }
    updateView();
}

void Frames::playAllFrames(int framesPerSecond) {
   animFrame = 0;
   interval = 1000 / framesPerSecond;
   animPlaying = true;
   playNextFrame();
}

void Frames::playNextFrame() {
    emit displayAnimFrame(&(frameList[animFrame]));
    animFrame = (animFrame + 1) % frameList.size();
    if (animPlaying)
        QTimer::singleShot(interval, this, &Frames::playNextFrame);
}

void Frames::stopPlayingFrames() {
    animPlaying = false;
}

void Frames::saveFile(QString fileName) {
    int counter = 0;
    // Make a QFile with that
    QFile file(fileName);
                QJsonArray rows;

    // Create the JSON objects
     QJsonObject projectObj;
     projectObj["height"] = height;
     projectObj["width"] = width;
     projectObj["numberOfFrames"] = frameList.size();

     // Make a frames object
     QJsonObject listOfFrames;
     // Iterate through vector of frames
     for(QVector<QImage>::iterator iter = frameList.begin(); iter != frameList.end(); iter++) {
         QJsonArray frame;
         // Iterate through the rows
        for(int row = 0; row < width; row++) {
            rows = QJsonArray();
             // Iterate through the pixels in each row
             for (int pixel = 0; pixel < height; pixel++) {
                 QJsonArray RGBAColors;
                 //Grab the color of the pixel and put it inside a array
                QRgb rgbas = iter->pixel(QPoint(pixel, row));
                QColor color(rgbas);

                RGBAColors.push_back(color.red());
                RGBAColors.push_back(color.green());
                RGBAColors.push_back(color.blue());
                RGBAColors.push_back(color.alpha());
                rows.push_back(RGBAColors);
             }
           frame.push_back(rows);
         }

        QString str = QString::number(counter);
        str.prepend("frame");

        listOfFrames.insert(str, frame);

        counter++;
     }

     // Add the frames object into the project object
     projectObj.insert("frames", listOfFrames);

    // Write the object
     QJsonDocument document;
     document.setObject(projectObj);
     QByteArray bytes = document.toJson( QJsonDocument::Indented);
     QFile writeFile(fileName);
     if(writeFile.open( QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
     {
         QTextStream iStream(&writeFile);
         iStream << bytes;
         file.close();
     }

    file.close();
}

void Frames::loadFile(QString fileName) {
    if (fileName.isEmpty()) {
        return;
    }
    else {
        frameList.clear();
        emit clearFrameList();

        currentFrame = -1;

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

            // Add frame to model
            frameList.push_back(image);

            // Add current frame to frame list in view
            currentFrame++;
            addToFrameList();
        }

        // Set current frame to first frame
        currentFrame = 0;

        updateView();

        file.close();
    }
}

 void Frames::newFile(int width, int height) {
     currentFrame = -1;
     frameList.clear();
     emit clearFrameList();

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
