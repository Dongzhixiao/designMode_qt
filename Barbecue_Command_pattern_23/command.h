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

class Command   //抽象命令类
{
public:
    explicit Command(Barbecuer* receiver)
    {
        _receiver = QSharedPointer<Barbecuer>(receiver);
    }
    virtual void ExcuteCommand() = 0;
    virtual ~Command(){}
protected:
    QSharedPointer<Barbecuer> _receiver;
};

class BakeMuttonCommand final : public Command
{
public:
    explicit BakeMuttonCommand(Barbecuer* receiver):Command(receiver){}
    void ExcuteCommand() override {_receiver->BakeMutton();}
};

class BakeChickenWingCommand final : public Command
{
public:
    explicit BakeChickenWingCommand(Barbecuer* receiver):Command(receiver){}
    void ExcuteCommand() override {_receiver->BakeChickenWing();}
};

class Waiter
{
public:
    void SetOrder(Command * command)
    {
        _command = QSharedPointer<Command>(command);
    }
    void Notify()
    {
        _command->ExcuteCommand();
    }
private:
    QSharedPointer<Command> _command;
};

#endif // COMMAND_H
