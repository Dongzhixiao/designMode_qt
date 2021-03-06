#ifndef PERSUITGIRL
#define PERSUITGIRL

#include <QString>
#include <QObject>
#include <QtDebug>
//被追求者类
class schoolGirl:public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
public:
    explicit schoolGirl(QObject *parent = 0):_name("undefined"){}
    QString name() const
    {
        return _name;
    }
    void setName(const QString & name)
    {
        _name = name;
    }
signals:
    void nameChanged(const QString & name);
private:
    QString _name;
};
//定义接口：实际对象和代理的公共接口，这样实际对象需要使用的地方都可以用代理完成！
class GiveGiftInterface
{
public:
    virtual void GiveDolls()=0;
    virtual void GiveFlowers()=0;
    virtual void GiveChocolate()=0;
    virtual ~GiveGiftInterface(){}
};
//追求者类如下
class Pursuit final:public GiveGiftInterface
{
public:
    explicit Pursuit(schoolGirl *mm)
    {
        _mm = QSharedPointer<schoolGirl>(mm);
    }
    void GiveDolls() override
    {
        qDebug() <<_mm->name()<<"送你洋娃娃！";
    }
    void GiveFlowers() override
    {
        qDebug() <<_mm->name()<<"送你鲜花！";
    }
    void GiveChocolate() override
    {
        qDebug() <<_mm->name()<<"送你巧克力！";
    }
private:
    QSharedPointer<schoolGirl> _mm;
};
//代理类如下
class Proxy final:public GiveGiftInterface
{
public:
    explicit Proxy(schoolGirl *mm)
    {
        _gg = QSharedPointer<Pursuit>(new Pursuit(mm));
    }
    void GiveDolls() override
    {
        _gg->GiveDolls();
    }
    void GiveFlowers() override
    {
        _gg->GiveFlowers();
    }
    void GiveChocolate() override
    {
        _gg->GiveChocolate();
    }
private:
    QSharedPointer<Pursuit> _gg;
};

#endif // PERSUITGIRL

