#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <QObject>
#include <QList>
#include <QTimer>
#include <QGraphicsScene>
#include "StorageVariable.h"
#include "heavypoint.h"
#include "objectdirector.h"
#include "planetbuilder.h"

class GameLogic final : public QObject
{
    Q_OBJECT
public:
    explicit GameLogic(QObject *parent = nullptr);
    ~GameLogic();
public:
    void Update();
    void DeleteItems();
public:
    QTimer *GetTimer() { return timer; }
    ObjectItem* AddItem();
public slots:
    void SlotAddHeavyItem(QPointF _point);
    void SlotDeleteHeavyItem();
private:
    void Init();
private:
    void UpdateObjectsPositions();
    void UpdateObjectsSpeeds();
    void CollisionWithSceneFrames(const QPointF& point, int index);
    void generatePixPath(QRandomGenerator *generator);
    void impulses(float *vx, float *vy, ObjectItem *obj1, ObjectItem *obj2);
private:
    QList<ObjectItem *> objects;
    ObjectDirector *director;
    PlanetBuilder *planetBuilder;
    HeavyPointBuilder *heavyPointBuilder;
    //ObjectItem *pObjectHeavyPoint;
    QTimer *timer;
    QRandomGenerator generator;
};

#endif // GAMELOGIC_H
