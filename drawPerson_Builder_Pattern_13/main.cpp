#include "drawit.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
    PersonDirector *pd = new PersonDirector("thin");

    DrawIt *d = pd->creatPersonDraw();
    d->show();
    delete pd;
    pd = NULL;
    return a.exec();
}
