#ifndef STORAGEVARIABLE_H
#define STORAGEVARIABLE_H

#include <QPoint>
#include <QString>

const int cSceneWidth = 800;
const int cSceneHeight = 800;


struct ObjectParametrs
{
    float mass;
    float radious;
    float xSpeed;
    float ySpeed;
    QPointF position;
};

#endif // STORAGEVARIABLE_H
