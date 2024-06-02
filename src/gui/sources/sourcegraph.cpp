#include "../headers/sourcegraph.h"
#include "ui_sourcegraph.h"

#include <QDebug>

SourceGraph::SourceGraph(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SourceGraph)
{
    ui->setupUi(this);

    this->source = new SourceGraphPoint();

    QGraphicsScene *scene = new QGraphicsScene(0, 0, 400, 400, this);
    this->ui->graphicsView->setScene(scene);

    QPen outlinePen(Qt::black);
    QBrush oP(Qt::gray);
    outlinePen.setWidth(0);

    this->vLine = scene->addLine(200, 0, 200, 400, outlinePen);
    this->hLine = scene->addLine(0, 200, 400, 200, outlinePen);
    scene->addItem(this->source);

    connect(source, SIGNAL(updateSourcePosition(double, double)), this, SLOT(updateSourcePosition(double, double)));
}

SourceGraph::~SourceGraph()
{
    delete ui;
}

void SourceGraph::trackAnimation(QTimeLine *timer, double initialX, double initialY, double finalX, double finalY)
{
    QGraphicsItemAnimation *sourceAnimation = new QGraphicsItemAnimation;
    sourceAnimation->setItem(this->source);
    sourceAnimation->setTimeLine(timer);

    QGraphicsItemAnimation *hLineAnimation = new QGraphicsItemAnimation;
    hLineAnimation->setItem(this->hLine);
    hLineAnimation->setTimeLine(timer);

    QGraphicsItemAnimation *vLineAnimation = new QGraphicsItemAnimation;
    vLineAnimation->setItem(this->vLine);
    vLineAnimation->setTimeLine(timer);

    double initialXSceneCoordinate = convertionToSceneCoordinates(initialX);
    double initialYSceneCoordinate = convertionToSceneCoordinates(-initialY);
    double finalXSceneCoordinate = convertionToSceneCoordinates(finalX);
    double finalYSceneCoordinate = convertionToSceneCoordinates(-finalY);

    double intervalX = finalXSceneCoordinate - initialXSceneCoordinate;
    double intervalY = finalYSceneCoordinate - initialYSceneCoordinate;

    double step = 0.0;
    double updateX = 0.0;
    double updateY = 0.0;
    for(int iterator = 0; iterator <= 100; ++iterator){
        step = iterator / 100.0;
        updateX = initialXSceneCoordinate + (intervalX * step);
        updateY = initialYSceneCoordinate + (intervalY * step);

        sourceAnimation->setPosAt(step, QPointF(updateX, updateY));
        hLineAnimation->setPosAt(step, QPointF(0, updateY));
        vLineAnimation->setPosAt(step, QPointF(updateX, 0));
    }

    timer->start();

    connect(timer, SIGNAL(finished()), this, SLOT(endTrackAnimation()));
}

void SourceGraph::endTrackAnimation(){
    this->source->setX(this->sourceXCoordinate);
    this->source->setY(this->sourceYCoordinate);
    this->vLine->setX(this->sourceXCoordinate);
    this->hLine->setY(this->sourceYCoordinate);
}

void SourceGraph::updateSourcePosition(double x, double y){
    double xConvertionToValues = this->convertionToValue(x);
    double yConvertionToValues = - this->convertionToValue(y);
    emit this->updateSourceCoordinates(xConvertionToValues, yConvertionToValues);
    this->updateSourceXCoordinate(xConvertionToValues);
    this->updateSourceYCoordinate(yConvertionToValues);
}

void SourceGraph::updateSourceXCoordinate(double x){
    double xConvertionToGraph = this->convertionToSceneCoordinates(x);
    this->sourceXCoordinate = xConvertionToGraph;
    this->source->setX(xConvertionToGraph);
    this->vLine->setX(xConvertionToGraph);
}

void SourceGraph::updateSourceYCoordinate(double y){
    double yConvertionToGraph = this->convertionToSceneCoordinates(-y);
    this->sourceYCoordinate = yConvertionToGraph;
    this->source->setY(yConvertionToGraph);
    this->hLine->setY(yConvertionToGraph);
}

double SourceGraph::convertionToSceneCoordinates(double value){
    return (100.00 * (2.00 + (value / 2.00))) - 200;
}

double SourceGraph::convertionToValue(double sceneCoordinate){
    return 2.00 * ((sceneCoordinate / 100.00) - 2.00);
}
