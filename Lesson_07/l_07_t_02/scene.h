#ifndef SCENE_H
#define SCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QTransform>
#include "shape.h"

class scene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit scene(QObject *parent = nullptr);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;

private:
    shape* graphicsItem;
    shape::Geometry currentGeometry;

};

#endif // SCENE_H
