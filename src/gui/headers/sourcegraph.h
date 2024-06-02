#ifndef SOURCEGRAPH_H
#define SOURCEGRAPH_H

#include "sourcegraphpoint.h"

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QTimeLine>
#include <QGraphicsItemAnimation>

namespace Ui {
class SourceGraph;
}

class SourceGraph : public QWidget
{
    Q_OBJECT

public:
    explicit SourceGraph(QWidget *parent = nullptr);
    ~SourceGraph();
    void trackAnimation(QTimeLine *timer, double initialX, double initialY, double finalX, double finalY);
    void updateSourceXCoordinate(double x);
    void updateSourceYCoordinate(double y);
    double convertionToSceneCoordinates(double value);
    double convertionToValue(double sceneCoordinate);

signals:
    void updateSourceCoordinates(double x, double y);

public slots:
    void updateSourcePosition(double x, double y);

private slots:
    void endTrackAnimation();

private:
    Ui::SourceGraph *ui;
    QGraphicsLineItem *vLine;
    QGraphicsLineItem *hLine;
    SourceGraphPoint *source;
    double sourceXCoordinate;
    double sourceYCoordinate;
};

#endif // SOURCEGRAPH_H
