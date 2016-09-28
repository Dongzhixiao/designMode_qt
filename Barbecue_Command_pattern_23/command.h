#ifndef COMMAND_H
#define COMMAND_H

#include <QDebug>

class Barbecuer
{
public:
    void BakeMutton()
    {
        qDebug()<<"拷羊肉串";
    }
    void BakeChickenWing()
    {
        qDebug()<<"拷鸡翅";
    }
};

class Command
{
public:
    Command(Barbecuer* receiver)
    {

    }

protected:
    Barbecuer* _receiver;
};



#endif // COMMAND_H
