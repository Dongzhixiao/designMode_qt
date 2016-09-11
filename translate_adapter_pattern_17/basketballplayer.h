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
protected:
    QString _name;
};
class Forwards:public Player
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
class Center:public Player
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
class Guards:public Player
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
class Translator:public Player   //相当于适配器
{
public:
    Translator(QString name):Player(name){fc = new ForeignCenter();fc->setName(name);}
    Translator(const Translator &) = delete;    //直接删了，防止浅拷贝
    Translator & operator =(const Translator &) = delete;  //直接删了，防止浅拷贝
    ~Translator(){delete fc;}
    void Attack() override
    {
        fc->TranslateAttack();
    }
    void Defense() override
    {
        fc->TranslateDefense();
    }
private:
    ForeignCenter *fc;
};

#endif // BASKETBALLPLAYER

