#ifndef PROXYIMAGE_H
#define PROXYIMAGE_H

#include "image.h"

class ProxyImage : public AbstractImage
{
private:
    Image *realImage = NULL;
    QString path;
public:
    ProxyImage(QString path);

    virtual ~ProxyImage();

    virtual QImage *getImage();
};

#endif // PROXYIMAGE_H
