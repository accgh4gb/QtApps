#ifndef FIRSTSCENE_H
#define FIRSTSCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QTransform>
#include "shape.h"

class FirstScene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit FirstScene(QObject *parent = nullptr);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;

private:
    shape* graphicsItem;
    shape::Geometry currentGeometry;

};

#endif // FIRSTSCENE_H
