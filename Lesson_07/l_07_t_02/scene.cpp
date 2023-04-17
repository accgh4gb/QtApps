#include "scene.h"

scene::scene(QObject *parent) : QGraphicsScene(parent)
{
    this->setSceneRect(0,0,800,600);
    currentGeometry = shape::Geometry::RECTANGLE;
}

void scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton && !this->itemAt(event->scenePos(), {}))
    {
        graphicsItem = new shape(this);
        graphicsItem->setGeometry(currentGeometry);
        graphicsItem->setPos(event->scenePos() - graphicsItem->getBoundingRectCenter());
        this->addItem(graphicsItem);

        this->update();

        if (currentGeometry == shape::Geometry::STAR)
        {
            currentGeometry = shape::Geometry::RECTANGLE;
        }
        else if (currentGeometry == shape::Geometry::RECTANGLE)
        {
            currentGeometry = shape::Geometry::ELLIPS;
        }
        else
        {
            currentGeometry = shape::Geometry::STAR;
        }
    }

    if (event->button() == Qt::RightButton && this->itemAt(event->scenePos(), {}))
    {
        QGraphicsItem* pCurrentItem = this->itemAt(event->scenePos(),{});
        this->removeItem(pCurrentItem);
    }

    QGraphicsScene::mousePressEvent(event);
}
