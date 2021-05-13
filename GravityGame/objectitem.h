#ifndef OBJECTITEM_H
#define OBJECTITEM_H

#include <QGraphicsItem>
#include <QObject>
#include <QPainter>
#include <QRandomGenerator>
#include <QGraphicsSceneMouseEvent>
#include "StorageVariable.h"
#include <QCoreApplication>

class ObjectItem : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit ObjectItem(QObject *parent = nullptr);
    virtual ~ObjectItem();
public:
    float GetObjectMass() const { return objectMass; };
    float GetObjectXSpeed() const { return xSpeed; };
    float GetObjectYSpeed() const { return ySpeed; };
    float GetObjectRadious() const { return objectRadious; };
public:
    void SetObjectMass(float _objectMass) { objectMass = _objectMass; };
    void SetObjectXSpeed(float _xSpeed) { xSpeed = _xSpeed; };
    void SetObjectYSpeed(float _ySpeed) { ySpeed = _ySpeed; };
    void SetObjectRadious(float _objectRadious) { objectRadious = _objectRadious; };
    void SetColor(QColor _color) { objectColor = _color; };
public:
    void AddSpeed(float _vx, float _vy);
protected slots:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
private:
    void Init();
private:
    QColor objectColor;
    float objectMass;
    float xSpeed;
    float ySpeed;
    float objectRadious;

    QString pixmapPath;
    QString picPath = QCoreApplication::applicationDirPath().left(QCoreApplication::applicationDirPath().indexOf("build") - 1) + "/GravityGame/planet";
};

#endif // OBJECTITEM_H
