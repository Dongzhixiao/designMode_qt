//#define use_origin

#include "sign.h"
#include "signfactory.h"
#include "caculate.h"
#include <QApplication>
#include <QDebug>


#ifdef use_origin
#include <memory>
#endif

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

#ifdef use_origin
    std::shared_ptr<caculate> c(new caculate);
#else
    QSharedPointer<caculate> c(new caculate);
#endif
    c->show();

    return app.exec();
}
