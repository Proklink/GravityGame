#include "iobjectbuilder.h"

IObjectBuilder::IObjectBuilder() : item(nullptr)
{

}

ObjectItem* IObjectBuilder::GetObject()
{
    ObjectItem *timeItem = item;
    item = nullptr;
    return timeItem;
}
