#ifndef OBJECTDIRECTOR_H
#define OBJECTDIRECTOR_H

#include "planetbuilder.h"
#include "heavypointbuilder.h"
#include "objectitem.h"

class ObjectDirector final
{
public:
    explicit ObjectDirector();
public:
    ObjectItem* CreatePlanet(IObjectBuilder *builder);
    ObjectItem* CreateHeavyPoint(IObjectBuilder *builder, const QPointF& _point);
};

#endif // OBJECTDIRECTOR_H
