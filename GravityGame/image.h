#ifndef IMAGE_H
#define IMAGE_H

#include "AbstractImage.h"

class Image : public AbstractImage
{
public:
    Image(QString path);
    virtual ~Image();
    virtual QImage *getImage();


};

#endif // IMAGE_H
