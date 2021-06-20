#include "heavypointbuilder.h"
#include <limits>

HeavyPointBuilder::HeavyPointBuilder()
{}

void HeavyPointBuilder::BuildStartSpeed()
{
    item->SetObjectXSpeed(0);
    item->SetObjectYSpeed(0);
}

void HeavyPointBuilder::BuildStartMass()
{
    item->SetObjectMass(10000);
}

void HeavyPointBuilder::BuildStartColor()
{
    item->SetColor(Qt::black);
}

void HeavyPointBuilder::BuildStartRadious()
{
    item->SetObjectRadious(5);
}

void HeavyPointBuilder::BuildStartPosition(const QPointF& _point)
{
    item->setPos(_point);
}

void HeavyPointBuilder::CreateObject()
{
    if (item == nullptr)
    {
        item = new ObjectItem;
    }
}
