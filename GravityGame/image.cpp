#include "image.h"

Image::Image(QString path)
{
    image = new QImage(path);
}

Image::~Image() {
    delete image;
}

QImage *Image::getImage() {
    return image;
}
