#include "proxyimage.h"

ProxyImage::ProxyImage(QString path)
{
    this->path = path;
}

QImage *ProxyImage::getImage() {

    if (!realImage)
        realImage = new Image(path);

    return realImage->getImage();
}

ProxyImage::~ProxyImage() {
    delete realImage;
}
