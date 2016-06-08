#ifndef WORKSTATUS
#define WORKSTATUS
#include <QtDebug>

class State;
class Work
{
public:
    Work();
    int getTime(){return _hour;}
    void setTime(int hour){_hour = hour;}
    bool getFinished(){return _finished;}
    void setFinished(bool finished){_finished = finished;}
    void setState(State * s){_state = s;}
    void writeProgram();
private:
    bool _finished = false;
    int _hour;
    State *_state;
};

class State
{
public:
    virtual void writeProgram(Work w) = 0;
};
//下面逻辑倒着申明类，否则需要前置声明，还要使用指针！也可以实现，以后玩玩！！
class EveningState:public State
{
public:
    void writeProgram(Work w) override
    {
        if(w.getTime() < 21)
        {
            qDebug()<<"当前时间"<<w.getTime()<<"加班哦，疲劳至极！";
        }
        else
        {
            qDebug()<<"当前时间"<<w.getTime()<<"不行了，睡着了！";
        }
    }
};
class AfternoonState:public State
{
public:
    void writeProgram(Work w) override
    {
        if(w.getTime() < 17)
        {
            qDebug()<<"当前时间"<<w.getTime()<<"下午状态还不错，继续努力！";
        }
        else
        {
            w.setState(new EveningState());
            w.writeProgram();
        }
    }
};
class NoonState:public State
{
public:
    void writeProgram(Work w) override
    {
        if(w.getTime() < 13)
        {
            qDebug()<<"当前时间"<<w.getTime()<<"饿了，午饭，犯困，午休！";
        }
        else
        {
            w.setState(new AfternoonState());
            w.writeProgram();
        }
    }
};
class ForenoonState:public State
{
public:
    void writeProgram(Work w) override
    {
        if(w.getTime() < 12)
        {
            qDebug()<<"当前时间"<<w.getTime()<<"上午工作，精神百倍！";
        }
        else
        {
            w.setState(new NoonState());
            w.writeProgram();
        }
    }
};
#endif // WORKSTATUS

