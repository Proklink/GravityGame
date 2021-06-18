#include "widget.h"

#include <QApplication>
#include "heavypoint.h"

ObjectItem *HeavyPoint::pObjectHeavyPoint = nullptr;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qRegisterMetaType<ObjectParametrs>("ObjectParametrs");

    Widget w;
    w.show();
    return a.exec();
}
