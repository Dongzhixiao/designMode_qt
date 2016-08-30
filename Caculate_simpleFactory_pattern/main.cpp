#include "sign.h"
#include "signfactory.h"
#include <QCoreApplication>
#include <QDebug>

int main (int argc, char * argv[])
{
    QCoreApplication app(argc,argv);

    Signfactory sf;
    Sign *s = sf.createSign("/");
    s->setA(1);s->setB(1);
    try{
        qDebug()<<s->getResult();
    }
    catch(...)
    {}
    return app.exec();
}
