#ifndef TRACKDIALOG_H
#define TRACKDIALOG_H

#include "../../logic/headers/simulationparameters.h"

#include <QDialog>

namespace Ui {
class TrackDialog;
}

class TrackDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TrackDialog(QWidget *parent, SimulationParameters &simulationParameters);
    ~TrackDialog();

private slots:
    void on_DoneBtn_clicked();

private:
    Ui::TrackDialog *ui;
};

#endif // TRACKDIALOG_H
