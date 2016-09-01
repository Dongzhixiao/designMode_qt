#ifndef CACULATE_H
#define CACULATE_H

#include <QWidget>

namespace Ui {
class caculate;
}

class caculate : public QWidget
{
    Q_OBJECT

public:
    explicit caculate(QWidget *parent = 0);
    ~caculate();

private slots:
    void on_pushButton_clicked();

private:
    Ui::caculate *ui;
};

#endif // CACULATE_H
