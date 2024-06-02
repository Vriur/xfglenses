#ifndef TRACKDIALOG_H
#define TRACKDIALOG_H

#include "../../logic/headers/simulationparameters.h"

#include <QDialog>
#include <QTimeLine>

namespace Ui {
class TrackDialog;
}

class TrackDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TrackDialog(QWidget *parent, SimulationParameters &simulationParameters);
    ~TrackDialog();

signals:
    void startAnimation(QTimeLine *timer, double initialX, double initialY, double finalX, double finalY);

public slots:
    void endTrackAnimation();

private slots:
    void on_DoneBtn_clicked();

    void on_AnimateBtn_clicked();

private:
    Ui::TrackDialog *ui;
};

#endif // TRACKDIALOG_H
