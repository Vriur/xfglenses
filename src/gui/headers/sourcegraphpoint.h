#ifndef SOURCEGRAPHPOINT_H
#define SOURCEGRAPHPOINT_H

#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>
#include <QPainter>

class SourceGraphPoint : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    SourceGraphPoint();
    ~SourceGraphPoint();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:
    void updateSourcePosition(double x, double y);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // SOURCEGRAPHPOINT_H
