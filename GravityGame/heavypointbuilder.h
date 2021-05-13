#ifndef HEAVYPOINTBUILDER_H
#define HEAVYPOINTBUILDER_H

#include "iobjectbuilder.h"

class HeavyPointBuilder : public IObjectBuilder
{
public:
    explicit HeavyPointBuilder();
    ~HeavyPointBuilder() override = default;
public:
    void BuildStartSpeed() override;
    void BuildStartMass() override;
    void BuildStartColor() override;
    void BuildStartRadious() override;
    void BuildStartPosition(const QPointF& _point) override;
    void CreateObject() override;
};

#endif // HEAVYPOINTBUILDER_H
