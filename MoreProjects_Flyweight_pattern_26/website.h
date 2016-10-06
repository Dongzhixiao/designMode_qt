#ifndef WEBSITE_H
#define WEBSITE_H

#include <QString>
#include <QDebug>
#include <QMap>
#include <QSharedPointer>

class User
{
public:
    User(QString name):_name(name){}
    QString GetName() {return _name;}
private:
    QString _name;
};

class WebSite   //抽象网站类
{
public:
    virtual void Use(User user){Q_UNUSED(user);}
    virtual ~WebSite() = default;
};

class ConcreteWebSite final : public WebSite   //具体网站类
{
public:
    explicit ConcreteWebSite(QString name):_name(name){}
    void Use(User user) override
    {
        qDebug()<<"网站分类："<<_name<<"用户："<<user.GetName();
    }
private:
    QString _name;
};

class WebSiteFactory
{
public:
    WebSite* GetWebSiteCategory(QString key)
    {
        if(!_flyweights.contains(key))
        {
            _flyweights.insert(key,QSharedPointer<ConcreteWebSite>(new ConcreteWebSite(key)));
        }
        return _flyweights[key].data();
    }
    int GetWebSiteCount()
    {
        return _flyweights.count();
    }
private:
    QMap<QString,QSharedPointer<ConcreteWebSite>> _flyweights;
};

#endif // WEBSITE_H
