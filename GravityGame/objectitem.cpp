#include "objectitem.h"
#include <QDebug>


ObjectItem::ObjectItem(QObject *parent)
    : QObject(parent),
      QGraphicsItem()
{
    Init();
}

void ObjectItem::Init()
{
    QRandomGenerator generator(time(NULL));
    pixmapPath = picPath + QString::number(generator.generate() % 5 + 1) + ".png";
}

void ObjectItem::SetPixmapPath(QString path) {
    pixmapPath = path;
}

void ObjectItem::AddSpeed(float _vx, float _vy)
{
    xSpeed += _vx;
    ySpeed += _vy;
}

void ObjectItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(QBrush(objectColor));
    painter->drawEllipse(QRectF(0, 0, objectRadious * 2, objectRadious * 2));

    QPixmap *px = new QPixmap(pixmapPath);
    painter->drawPixmap(QRectF(0, 0, objectRadious * 2, objectRadious * 2).toRect(), *px);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF ObjectItem::boundingRect() const
{
    int boundingSize = 2 * objectRadious;
    return QRectF(0,0, boundingSize, boundingSize);
}

ObjectItem::~ObjectItem()
{}

