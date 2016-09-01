#include "shopprice.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    shopPrice *sp = new shopPrice();
    sp->show();

    return app.exec();
}
