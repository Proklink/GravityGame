#include "planetbuilder.h"
#include <QDebug>

PlanetBuilder::PlanetBuilder()
{}

void PlanetBuilder::BuildStartSpeed()
{    
    int firstRatio = generator.generate() % 2 ? -1 : 1;
    int secondRatio = generator.generate() % 2 ? -1 : 1;

    item->SetObjectXSpeed(firstRatio * static_cast<float>(generator.generate() % 4));
    item->SetObjectYSpeed(secondRatio * static_cast<float>(generator.generate() % 4));
}

void PlanetBuilder::BuildStartMass()
{
    item->SetObjectMass(generator.generate() % 100);
}

void PlanetBuilder::BuildStartColor()
{
    item->SetColor(QColor(generator.generate() % 256,
                          generator.generate() % 256,
                          generator.generate() % 256));
}

void PlanetBuilder::BuildStartRadious()
{
    item->SetObjectRadious(generator.generate() % 20 + 10.0);
}

void PlanetBuilder::BuildStartPosition()
{
    QPointF point(generator.generate() % 500, generator.generate() % 500);
    item->setPos(point);
}

void PlanetBuilder::CreateObject()
{
    if (item == nullptr)
        item = new ObjectItem;
}
