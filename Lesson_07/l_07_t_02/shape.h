#ifndef SHAPE_H
#define SHAPE_H

#include <QObject>
#include <QGraphicsItem>
#include <QBrush>
#include <QCursor>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>

class shape : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)

public:
    enum Geometry {RECTANGLE, ELLIPS, STAR};
    explicit shape(QObject *parent = nullptr);
    void setGeometry(Geometry geom);
    QPointF getBoundingRectCenter();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;

private:
    bool rotate = false;
    int x, y;
    Geometry geometry;
    QPoint bpoint;
    QBrush brush;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // SHAPE_H
