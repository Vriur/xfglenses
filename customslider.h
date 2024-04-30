#ifndef CUSTOMSLIDER_H
#define CUSTOMSLIDER_H

#include <QWidget>

namespace Ui {
class CustomSlider;
}

class CustomSlider : public QWidget
{
    Q_OBJECT

public:
    explicit CustomSlider(QWidget *parent = nullptr);
    ~CustomSlider();

private slots:


private:
    Ui::CustomSlider *ui;
};

#endif // CUSTOMSLIDER_H
