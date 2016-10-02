#ifndef UNITEDNATIONS
#define UNITEDNATIONS

#include <QString>
#include <QDebug>
#include <QSharedPointer>

class Country;
class UnitedNations   //联合国机构
{
public:
    virtual void Declare(QString message, Country* colleague) = 0;
    virtual ~UnitedNations() = default;
};

class Country   //国家类
{
public:
    explicit Country(UnitedNations* mediator){_mediator = QSharedPointer<UnitedNations>(mediator);}
    virtual ~Country() = default;
protected:
    QSharedPointer<UnitedNations> _mediator;
};

class USA final : public Country   //美国类
{
public:
    explicit USA(UnitedNations* mediator):Country(mediator){}
    void Declare(QString message)
    {
        _mediator->Declare(message,this);
    }
    void GetMessage(QString message)
    {
        qDebug()<<"美国获得对方消息："<<message;
    }
};

class Iraq final : public Country   //伊拉克类
{
public:
    explicit Iraq(UnitedNations* mediator):Country(mediator){}
    void Declare(QString message)
    {
        _mediator->Declare(message,this);
    }
    void GetMessage(QString message)
    {
        qDebug()<<"伊拉克获得对方消息："<<message;
    }
};

class UnitedNationsSecurityCouncil final : public UnitedNations   //联合国安全理事会类
{
public:
    void setColleague1(USA * value)
    {
        _colleague1 = QSharedPointer<USA>(value);
    }
    void setColleague2(Iraq * value)
    {
        _colleague2 = QSharedPointer<Iraq>(value);
    }
    void Declare(QString message, Country *colleague) override
    {
        if(_colleague1.data() == colleague)
            _colleague2->GetMessage(message);
        else
            _colleague1->GetMessage(message);
    }
private:
    QSharedPointer<USA> _colleague1;
    QSharedPointer<Iraq> _colleague2;
};

#endif // UNITEDNATIONS

