#ifndef SINGLETON_H
#define SINGLETON_H

#include <QPointer>
#include <QMutex>

class Singleton: public QObject
{
public:
    static Singleton * GetInstance()
    {
        if(_instance == nullptr)
        {
            QMutexLocker locker(&_m);     // 这里相当于调用了_m.lock()
            _instance = new Singleton;
        }
        return _instance;
    }     //退出这个函数的时候，析构locker的时候就相当于调用了_m.unlock()
private:
    Singleton(){}
    Singleton(const Singleton &){}
    Singleton & operator=(const Singleton &){}
    static QPointer<Singleton> _instance;   //使用QPointer管理该指针是为了外界如果删除了该实例的内容可以保证指针_instance置为0
    static QMutex _m;    //QMutex是为了保证线程安全，即保证该类在多线程的情况下也只能创建一个实例
};

QPointer<Singleton> Singleton::_instance = nullptr;
QMutex Singleton::_m;   //
#endif // SINGLETON_H
