#include <QDebug>
#include "singleton.h"

int main()
{
    Singleton* s1 = Singleton::GetInstance();
    Singleton* s2 = Singleton::GetInstance();

    if(s1 == s2)
    {
        qDebug()<<"两个对象具有相同的实例";
    }
    return 0;
}
