#ifndef IOBJECTBUILDER_H
#define IOBJECTBUILDER_H

#include <QRandomGenerator>
#include "objectitem.h"

class IObjectBuilder
{
public:
    explicit IObjectBuilder();
    virtual ~IObjectBuilder() = default;
public:
    virtual void BuildStartSpeed() = 0;
    virtual void BuildStartMass() = 0;
    virtual void BuildStartColor() = 0;
    virtual void BuildStartRadious() = 0;
    virtual void BuildStartPosition() {};
    virtual void BuildStartPosition(const QPointF& _point) {};
    virtual void CreateObject() = 0;
public:
    ObjectItem* GetObject();
protected:
    QRandomGenerator generator;
    ObjectItem *item;
};

#endif // IOBJECTBUILDER_H
