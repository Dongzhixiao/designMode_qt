#ifndef BASKETBALLPLAYER
#define BASKETBALLPLAYER
#include <QtDebug>
#include <QString>

class Player
{
public:
    Player(QString name):_name(name){}
    virtual void Attack() = 0;
    virtual void Defense() = 0;
    virtual ~Player() = default;
protected:
    QString _name;
};
class Forwards final:public Player
{
public:
    Forwards(QString name):Player(name){}
    void Attack() override
    {
        qDebug()<<"前锋"<<_name<<"攻击！";
    }
    void Defense() override
    {
        qDebug()<<"前锋"<<_name<<"防守！";
    }
};
class Center final:public Player
{
public:
    Center(QString name):Player(name){}
    void Attack() override
    {
        qDebug()<<"中锋"<<_name<<"攻击！";
    }
    void Defense() override
    {
        qDebug()<<"中锋"<<_name<<"防守！";
    }
};
class Guards final:public Player
{
public:
    Guards(QString name):Player(name){}
    void Attack() override
    {
        qDebug()<<"后卫"<<_name<<"攻击！";
    }
    void Defense() override
    {
        qDebug()<<"后卫"<<_name<<"防守！";
    }
};

class ForeignCenter
{
public:
    ForeignCenter() = default;
    void TranslateAttack()
    {
        qDebug()<<"翻译后：中锋"<<_name<<"攻击！";
    }
    void TranslateDefense()
    {
        qDebug()<<"翻译后：中锋"<<_name<<"防守！";
    }
    void setName(QString name){_name = name;}
    QString getName(){return _name;}
private:
    QString _name;
};
class Translator final:public Player   //相当于适配器
{
public:
    Translator(QString name):Player(name){_fc = QSharedPointer<ForeignCenter>(new ForeignCenter());_fc->setName(name);}
    void Attack() override
    {
        _fc->TranslateAttack();
    }
    void Defense() override
    {
        _fc->TranslateDefense();
    }
private:
    QSharedPointer<ForeignCenter> _fc;
};

#endif // BASKETBALLPLAYER

