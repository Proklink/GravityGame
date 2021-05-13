#ifndef PLANETBUILDER_H
#define PLANETBUILDER_H

#include "iobjectbuilder.h"

class PlanetBuilder final : public IObjectBuilder
{
public:
    explicit PlanetBuilder();
    ~PlanetBuilder() override = default;
public:
    void BuildStartSpeed() override;
    void BuildStartMass() override;
    void BuildStartColor() override;
    void BuildStartRadious() override;
    void BuildStartPosition() override;
    void CreateObject() override;
};

#endif // PLANETBUILDER_H
