#ifndef MANAGER_H
#define MANAGER_H

#include <QString>
#include <QSharedPointer>
#include <QDebug>

class Request
{
public:
    QString getRequestType() const {return _requestType;}
    void setRequestType(QString requestType){_requestType = requestType;}
    QString getRequestContent() const {return _requestContent;}
    void setRequestContent(QString requestContent){_requestContent = requestContent;}
    int getNumber() const {return _number;}
    void setNumber(int number){_number = number;}
private:
    QString _requestType;
    QString _requestContent;
    int _number;
};

class Manager
{
public:
    explicit Manager(QString name)
    {
        _name = name;
    }
    void setSuperior(Manager* superior)
    {
        _superior = QSharedPointer<Manager>(superior);
    }
    virtual void RequestApplications(const Request &) = 0;
    virtual ~Manager(){}
protected:
    QString _name;
    QSharedPointer<Manager> _superior;
};

class CommonManager final : public Manager   //经理类
{
public:
    explicit CommonManager(QString name):Manager(name){}
    void RequestApplications(const Request & request) override
    //注意，函数的参数如果有const实例，则函数里面调用该实例的方法必须是const函数
    {
        if(request.getRequestType() == "请假" && request.getNumber()<=2)
        {
            qDebug()<<_name<<request.getRequestContent()<<request.getNumber()<<"被批准";
        }
        else
        {
            if(_superior!=nullptr)
                _superior->RequestApplications(request);
        }
    }
};

class Majordomo final : public Manager   //总监类
{
public:
    explicit Majordomo(QString name):Manager(name){}
    void RequestApplications(const Request & request) override
    {
        if(request.getRequestType() == "请假" && request.getNumber()<=5)
        {
            qDebug()<<_name<<request.getRequestContent()<<request.getNumber()<<"被批准";
        }
        else
        {
            if(_superior!=nullptr)
                _superior->RequestApplications(request);
        }
    }
};

class GeneralManager final : public Manager   //总经理类
{
public:
    explicit GeneralManager(QString name):Manager(name){}
    void RequestApplications(const Request & request) override
    {
        if(request.getRequestType() == "请假" && request.getNumber()<=500)
        {
            qDebug()<<_name<<request.getRequestContent()<<request.getNumber()<<"被批准";
        }
        else if(request.getRequestType() == "加薪" && request.getNumber()<=500)
        {
           qDebug()<<_name<<request.getRequestContent()<<request.getNumber()<<"被批准";
        }
        else if(request.getRequestType() == "加薪" && request.getNumber()>500)
        {
            qDebug()<<_name<<request.getRequestContent()<<request.getNumber()<<"再说吧";
        }
    }
};

#endif // MANAGER_H
