#ifndef WIDGET_H
#define WIDGET_H

#include <QGraphicsScene>
#include <QMouseEvent>
#include "itemsettingsdialog.h"
#include "StorageVariable.h"
#include "objectitem.h"
#include "objectdirector.h"
#include "planetbuilder.h"
#include "gamelogic.h"
#include "scene.h"
#include "StorageVariable.h"
#include "proxyimage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    void CreatePlanetClicked();
    void DeleteButtonClicked();
    void CreateItemSettingsDialog(ObjectParametrs);
    void BackgroundClicked();
private:
    void Init();
private:
    Ui::Widget *ui;
    ObjectItem *obj;
    Scene *scene;
    GameLogic *gameLogic;
    ItemSettingsDialog *itemSettingsDialog;

    AbstractImage *background;
    QString picPath;
    int ImageNumber = 5;
    int backgroundImageConuter = 0;
signals:
    void SignalPauseClicked();
    void SignalDeleteItems();
};
#endif // WIDGET_H
