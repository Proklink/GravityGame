#include "gamelogic.h"
#include <cmath>
#include <QTransform>
#include <QDebug>

GameLogic::GameLogic(QObject *parent)
    : QObject(parent)
{
    Init();
}

void GameLogic::Init()
{
    planetBuilder = new PlanetBuilder;
    heavyPointBuilder = new HeavyPointBuilder;

    timer = new QTimer;
    connect(timer, &QTimer::timeout, this, &GameLogic::Update);
    timer->start(10);
}

void GameLogic::Update()
{
    UpdateObjectsSpeeds();
    UpdateObjectsPositions();
};

void GameLogic::impulses(float *vx, float *vy, ObjectItem *obj1, ObjectItem *obj2) {
    float yso1 = obj1->GetObjectYSpeed();
    float xso1 = obj1->GetObjectXSpeed();
    float yso2 = obj2->GetObjectYSpeed();
    float xso2 = obj2->GetObjectXSpeed();

    float massObj1 = obj1->GetObjectMass();
    float massObj2 = obj2->GetObjectMass();
    float speedObj1 = sqrt(xso1 * xso1 + yso1 * yso1);
    float speedObj2 = sqrt(xso2 * xso2 + yso2 * yso2);
    float tempSpeed1 = 0, tempSpeed2 = 0;
    float tSpeedObj1 = 0, tSpeedObj2 = 0;

    if (xso1 < 0)
        speedObj1 *= -1;
    if (xso2 < 0)
        speedObj2 *= -1;

    float relMass = massObj2 / massObj1;

    float A = relMass - 1;
    float B = -2 * (relMass * speedObj2 + speedObj1);
    float C = speedObj2 * speedObj2 * (relMass + 1) + 2 * speedObj2 * speedObj1;

    float d = B * B - 4 * A * C; // Рассчитываем дискриминант
    if (d > 0) // Условие при дискриминанте больше нуля
    {
      tempSpeed1 = ((-B) + sqrt(d)) / (2 * A);
      tempSpeed2 = ((-B) - sqrt(d)) / (2 * A);

    tSpeedObj2 = std::fmaxf(tempSpeed1, tempSpeed2);
    if (tSpeedObj2 < 0) {
        qDebug() << " fmaxf < 0";
        tSpeedObj2 = 0;
    }

    }
    if (d == 0) // Условие для дискриминанта равного нулю
    {
      tempSpeed1 = -(B / (2 * A));
      if (tempSpeed1 < 0) {
          tSpeedObj2 = 0;
          qDebug() << "d == 0 ";
      }
    }
    if (d < 0) { // Условие при дискриминанте меньше нуля
      qDebug() << "D < 0, Действительных корней уравнения не существует";
      tSpeedObj2 = 0;
    }

    tSpeedObj1 = speedObj1 + relMass * speedObj2 - relMass * tSpeedObj2;


}

void GameLogic::UpdateObjectsSpeeds()
{
    float distance;
    float deltaX;
    float deltaY;
    float vx;
    float vy;

    for (int i = 0; i < objects.size(); ++i)
    {
        for (int j = 0; j < objects.size(); ++j)
        {
            if (i == j)
                continue;

            deltaX = objects[i]->pos().x() - objects[j]->pos().x();
            deltaY = objects[i]->pos().y() - objects[j]->pos().y();
            distance = sqrt(deltaX * deltaX + deltaY * deltaY);

            if (distance <= objects[i]->GetObjectRadious() + objects[j]->GetObjectRadious())
                continue;
                //impulses(&vx, &vy, objects[i], objects[j]);

            if (distance > 5)
            {
                vx =/* 0.007 * */objects[j]->GetObjectMass() / distance / distance
                        * (objects[j]->pos().x() - objects[i]->pos().x()) / distance;
                vy = /*0.007 * */objects[j]->GetObjectMass() / distance / distance
                        * (objects[j]->pos().y() - objects[i]->pos().y()) / distance;

                if (objects[i]->GetObjectMass() != 10000)
                    objects[i]->AddSpeed(vx, vy);
            }
        }
    }
}


void GameLogic::UpdateObjectsPositions()
{
    for(int i = 0; i < objects.size(); ++i)
    {
        QPointF point = objects[i]->pos();
        point.setX(point.x() + objects[i]->GetObjectXSpeed() / 20);
        point.setY(point.y() + objects[i]->GetObjectYSpeed() / 20);
        objects[i]->setPos(point);

        CollisionWithSceneFrames(point, i);
        if (objects[i]->GetObjectMass() == 10000)
            qDebug() << objects[i]->pos() << "\n";
    }

}

void GameLogic::CollisionWithSceneFrames(const QPointF& point, int index)
{
    if (point.x() >= cSceneWidth || point.x() <= 0)
    {
        objects[index]->SetObjectXSpeed(-objects[index]->GetObjectXSpeed());
    }
    else if (point.y() >= cSceneHeight || point.y() <= 0)
    {
        objects[index]->SetObjectYSpeed(-objects[index]->GetObjectYSpeed());
    }
}

ObjectItem* GameLogic::AddItem()
{
    ObjectItem *object = director->CreatePlanet(planetBuilder);
    objects.append(object);
    return object;
}

void GameLogic::SlotAddHeavyItem(QPointF _point)
{
    objects.append(HeavyPoint::getHeavyPoint(director, heavyPointBuilder, &_point));
}

void GameLogic::SlotDeleteHeavyItem()
{
    qDebug() << "SlotDeleteHeavyItem";
    ObjectItem *pObjectHeavyPoint = HeavyPoint::getHeavyPoint(director, heavyPointBuilder, NULL);

    if (objects.contains(pObjectHeavyPoint))
        objects.removeOne(pObjectHeavyPoint);

}

GameLogic::~GameLogic()
{
    DeleteItems();
};

void GameLogic::DeleteItems()
{
    for(int i = 0; i < objects.size(); ++i)
    {
        delete objects[i];
    }
    objects.clear();
}
