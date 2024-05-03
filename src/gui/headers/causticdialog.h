#ifndef CAUSTICDIALOG_H
#define CAUSTICDIALOG_H

#include <QDialog>

namespace Ui {
class CausticDialog;
}

class CausticDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CausticDialog(QWidget *parent = nullptr);
    ~CausticDialog();

private:
    Ui::CausticDialog *ui;
};

#endif // CAUSTICDIALOG_H
