#ifndef OBIPDIALOG_H
#define OBIPDIALOG_H

#include <QDialog>

namespace Ui {
class OBIPDialog;
}

class OBIPDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OBIPDialog(QWidget *parent = nullptr);
    ~OBIPDialog();

private:
    Ui::OBIPDialog *ui;
};

#endif // OBIPDIALOG_H
