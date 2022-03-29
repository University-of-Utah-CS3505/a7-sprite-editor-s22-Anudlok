#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QObject>

class Toolbar : public QObject
{
    Q_OBJECT
public:
    explicit Toolbar(QObject *parent = nullptr);
    enum Tools {
        brush,
        eraser,
        bucket,
        colorPicker,
        select
    };
    void switchTool(Tools);
    Tools getTool();
private:
    Tools currTool;
};

#endif // TOOLBAR_H
