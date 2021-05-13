#ifndef ABSTRACTIMAGE_H
#define ABSTRACTIMAGE_H

#include <QImage>

class AbstractImage {
protected:
    QImage *image;
public:

    virtual ~AbstractImage();
    virtual QImage *getImage() = 0;
};


#endif // ABSTRACTIMAGE_H
