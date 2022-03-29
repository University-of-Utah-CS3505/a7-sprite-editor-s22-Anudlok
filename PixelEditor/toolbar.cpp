#include "toolbar.h"
#include <QtDebug>

Toolbar::Toolbar(QObject *parent) : QObject{parent}, currTool{brush}
{

}

void Toolbar::switchTool(Tools tool) {
    currTool = tool;
    qDebug() << currTool;
}
