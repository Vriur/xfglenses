#ifndef OBIPCELL_H
#define OBIPCELL_H

#include <map>
#include <QDialog>

using std::pair;

namespace Ui {
class OBIPCell;
}

class OBIPCell : public QDialog
{
    Q_OBJECT

public:
    explicit OBIPCell(QWidget *parent, pair<double, double> *image, int index);
    ~OBIPCell();
    void setIndex(int index);
    int getIndex();
    
signals:
    void updateX(double x, int index);
    void updateY(double y, int index);
    void deleteThisCell(int index);

private slots:
    void on_XSpBox_valueChanged(double arg1);

    void on_YSpBox_valueChanged(double arg1);

    void on_DeleteBtn_clicked();

private:
    Ui::OBIPCell *ui;
    int index;
};

#endif // OBIPCELL_H
