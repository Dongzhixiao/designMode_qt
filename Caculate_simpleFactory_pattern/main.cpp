#include "sign.h"
#include "signfactory.h"
#include "caculate.h"
#include <QApplication>
#include <QDebug>

int main (int argc, char * argv[])
{
    QApplication app(argc,argv);

    Signfactory sf;
    Sign *s = sf.createSign("/");
    s->setA(1);s->setB(0);
    try{
        qDebug()<<s->getResult();
    }
    catch(...)
    {}
    delete s;

    caculate * c = new caculate;
    c->show();

    return app.exec();
}
