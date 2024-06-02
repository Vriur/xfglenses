#include "../headers/sourcegraphpoint.h"

SourceGraphPoint::SourceGraphPoint()
{
    setFlags(QGraphicsItem::ItemIsMovable);
    setAcceptHoverEvents(true);
}

SourceGraphPoint::~SourceGraphPoint() {
    delete this;
}

QRectF SourceGraphPoint::boundingRect() const{
    return QRectF(196, 196, 8, 8);
}

void SourceGraphPoint::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QRectF rectangle = boundingRect();
    QBrush brush(Qt::gray);

    painter->setBrush(brush);
    painter->drawEllipse(rectangle);
}

void SourceGraphPoint::mousePressEvent(QGraphicsSceneMouseEvent *event){
    QGraphicsItem::mousePressEvent(event);
    update();
    event->accept();
}

void SourceGraphPoint::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    QGraphicsItem::mouseMoveEvent(event);

    emit this->updateSourcePosition(event->scenePos().x(), event->scenePos().y());
}

void SourceGraphPoint::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    QGraphicsItem::mouseReleaseEvent(event);

    if(event->scenePos().x() < 0.0 || event->scenePos().x() > 402.0 || event->scenePos().y() < 0.0 || event->scenePos().y() > 402.0){
        this->setX(0);
        this->setY(0);
        emit this->updateSourcePosition(200, 200);
    }

    update();
}
