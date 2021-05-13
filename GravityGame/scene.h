#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPointF>
#include "objectitem.h"
#include "StorageVariable.h"
#include <QDebug>

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Scene(QObject *parent = nullptr);
public slots:
    void SlotSetParametrsToItem(ObjectParametrs _objectParametrs);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *_event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *_event) override;
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *_event) override;
private:
    ObjectItem *pCurrentObjectItem;
signals:
    void SignalSendParams(ObjectParametrs);
    void SignalPress(QPointF);
    void SignalRelease();
    void SignalStopTimer();
    void SignalStartTimer();
};

#endif // SCENE_H
