#ifndef LIGHTCURVEDIALOG_H
#define LIGHTCURVEDIALOG_H

#include <QDialog>

namespace Ui {
class LightCurveDialog;
}

class LightCurveDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LightCurveDialog(QWidget *parent = nullptr);
    ~LightCurveDialog();

private:
    Ui::LightCurveDialog *ui;
};

#endif // LIGHTCURVEDIALOG_H
