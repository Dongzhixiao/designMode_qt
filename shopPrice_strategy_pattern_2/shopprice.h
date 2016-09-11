#ifndef SHOPPRICE_H
#define SHOPPRICE_H

#include <QWidget>

namespace Ui {
class shopPrice;
}

class shopPrice : public QWidget
{
    Q_OBJECT

public:
    explicit shopPrice(QWidget *parent = 0);
    ~shopPrice();

private slots:
    void line_changed(const QString &);
    void com_changed(const QString &);

private:
    Ui::shopPrice *ui;
};

#endif // SHOPPRICE_H
