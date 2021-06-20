#include "heavypoint.h"

HeavyPoint::HeavyPoint()
{

}


ObjectItem *HeavyPoint::getHeavyPoint(ObjectDirector *director, HeavyPointBuilder *heavyPointBuilder, QPointF *point) {
    if (pObjectHeavyPoint == nullptr)
    {
        pObjectHeavyPoint = director->CreateHeavyPoint(heavyPointBuilder, *point);
        pObjectHeavyPoint->SetPixmapPath(QCoreApplication::applicationDirPath().left(QCoreApplication::applicationDirPath().indexOf("build") - 1) + "/GravityGame/planets/Blackhole.png");
    } else {
        if (point && (pObjectHeavyPoint->pos() != *point))
            pObjectHeavyPoint->setPos(*point);
    }
    return pObjectHeavyPoint;
}
