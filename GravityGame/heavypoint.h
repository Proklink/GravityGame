#ifndef HEAVYPOINT_H
#define HEAVYPOINT_H
#include "objectitem.h"
#include "objectdirector.h"

class HeavyPoint : public ObjectItem
{
public:
    static ObjectItem *getHeavyPoint(ObjectDirector *director, HeavyPointBuilder *heavyPointBuilder, QPointF *point);
private:
    HeavyPoint();

    static ObjectItem *pObjectHeavyPoint;
};

#endif // HEAVYPOINT_H
