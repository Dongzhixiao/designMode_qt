#ifndef USER
#define USER
#include <QString>
#include <QtDebug>

class User
{
public:
    User() = default;
    int getID(){return _id;}
    void setID(int id){_id = id;}
    QString getName(){return _name;}
    void setName(QString name){_name = name;}
private:
    int _id;
    QString _name;
};

class IUser:public QObject
{
    Q_OBJECT
public:
    virtual void Insert(User user) = 0;
    virtual User* getUser(int id) = 0;
};
class SqlServerUser final: public IUser
{
    Q_OBJECT
public:
    Q_INVOKABLE SqlServerUser() = default;
    void Insert(User user) override
    {
        Q_UNUSED(user);
        qDebug() <<"在SQL Server中给User表增加一条记录";
    }
    User* getUser(int id) override
    {
        Q_UNUSED(id);
        qDebug() <<"在SQL Server中根据id得到User表一条记录";
        return NULL;  //这里为了做例子，所以没有真正返回业务需要的指针，只是返回空指针做示范
    }
};
class AccessUser final: public IUser
{
    Q_OBJECT
public:
    void Insert(User user) override
    {
        Q_UNUSED(user);
        qDebug() <<"在Access中给User表增加一条记录";
    }
    User* getUser(int id) override
    {
        Q_UNUSED(id);
        qDebug() <<"在Access中根据id得到User表一条记录";
        return nullptr;   //这里为了做例子，所以没有真正返回业务需要的指针，只是返回空指针做示范
    }
};

class Department
{
private:
    QString _departmentName;
};

class IDepartment:public QObject
{
    Q_OBJECT
public:
    virtual void Insert(Department department) = 0;
};
class SqlServerDepartment:public IDepartment
{
    Q_OBJECT
public:
    void Insert(Department department) override
    {
        Q_UNUSED(department);
        qDebug() <<"在SQL Server中给Department表增加一条记录";
    }
};
class AccessDepartment:public IDepartment
{
    Q_OBJECT
public:
    void Insert(Department department) override
    {
        Q_UNUSED(department);
        qDebug() <<"在Access中给Department表增加一条记录";
    }
};

class IFactory
{
public:
    virtual IUser* CreateUser() = 0;

    virtual IDepartment *CreateDepartment() = 0;
};
class SqlServerFactory: public IFactory
{
public:
    IUser* CreateUser() override
    {
        return new SqlServerUser();
    }

    IDepartment* CreateDepartment() override
    {
        return new SqlServerDepartment();
    }
};
class AccessFactory: public IFactory
{
public:
    IUser* CreateUser() override
    {
        return new AccessUser();
    }

    IDepartment* CreateDepartment() override
    {
        return new AccessDepartment();
    }
};
#endif // USER

