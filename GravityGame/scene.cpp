#include "scene.h"

Scene::Scene(QObject *parent)
    : QGraphicsScene(parent)
{

}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *_event)
{
    emit SignalPress(_event->scenePos());
}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *_event)
{
    Q_UNUSED(_event)
    emit SignalRelease();
}

void Scene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *_event)
{
    if (itemAt(_event->scenePos(), QTransform()) != nullptr)
    {
        pCurrentObjectItem = (ObjectItem*)itemAt(_event->scenePos(), QTransform());
        ObjectParametrs objectParams;
        objectParams.mass = pCurrentObjectItem->GetObjectMass();
        objectParams.radious = pCurrentObjectItem->GetObjectRadious();
        objectParams.xSpeed = pCurrentObjectItem->GetObjectXSpeed();
        objectParams.ySpeed = pCurrentObjectItem->GetObjectYSpeed();
        objectParams.position = _event->scenePos();

        emit SignalStopTimer();
        emit SignalSendParams(objectParams);
    }
}

void Scene::SlotSetParametrsToItem(ObjectParametrs _objectParametrs)
{
    pCurrentObjectItem->SetObjectMass(_objectParametrs.mass);
    pCurrentObjectItem->SetObjectRadious(_objectParametrs.radious);
    pCurrentObjectItem->SetObjectXSpeed(_objectParametrs.xSpeed);
    pCurrentObjectItem->SetObjectYSpeed(_objectParametrs.ySpeed);

    emit SignalStartTimer();
}
