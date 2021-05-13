#include "objectdirector.h"

ObjectDirector::ObjectDirector()
{}

ObjectItem* ObjectDirector::CreatePlanet(IObjectBuilder *builder)
{
    builder->CreateObject();
    builder->BuildStartColor();
    builder->BuildStartMass();
    builder->BuildStartRadious();
    builder->BuildStartSpeed();
    builder->BuildStartPosition();

    return builder->GetObject();
}

ObjectItem* ObjectDirector::CreateHeavyPoint(IObjectBuilder *builder, const QPointF& _point)
{
    builder->CreateObject();
    builder->BuildStartColor();
    builder->BuildStartMass();
    builder->BuildStartRadious();
    builder->BuildStartSpeed();
    builder->BuildStartPosition(_point);

    return builder->GetObject();
}
