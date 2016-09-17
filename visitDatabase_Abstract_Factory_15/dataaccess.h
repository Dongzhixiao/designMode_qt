#ifndef DATAACCESS_H
#define DATAACCESS_H

#include "user.h"
#include <QString>

#define use_reflect   //如果不使用反射，注释掉这句话

#ifdef use_reflect
#include "objectfactory.h"
ObjectFactory::registerClass<SqlServerUser>();
ObjectFactory::registerClass<AccessUser>();
ObjectFactory::registerClass<SqlServerDepartment>();
ObjectFactory::registerClass<AccessDepartment>();
class DataAccess
{
public:
    static IUser* CreatUser()
    {
        IUser* result = nullptr;
        if(_db == "Sqlserver")
            result = new SqlServerUser();
        else if(_db == "Access")
            result = new AccessUser();
        return result;
    }
    static IDepartment* CreatDepartment()
    {
        IDepartment* result = nullptr;
        if(_db == "Sqlserver")
            result = new SqlServerDepartment();
        else if(_db == "Access")
            result = new AccessDepartment();
        return result;
    }

private:
    static const QString _db;  //注意：静态非整型数据成员，必须定义为const，且在类外初始化
};


//const QString DataAccess::_db = QString::fromUtf8("Sqlserver");
const QString DataAccess::_db = QString::fromUtf8("Access");   //把上面那句话取消注释，本行加上注释，就是使用sql服务的相关操作
#else
class DataAccess
{
public:
    static IUser* CreatUser()
    {
        IUser* result = nullptr;
        if(_db == "Sqlserver")
            result = new SqlServerUser();
        else if(_db == "Access")
            result = new AccessUser();
        return result;
    }
    static IDepartment* CreatDepartment()
    {
        IDepartment* result = nullptr;
        if(_db == "Sqlserver")
            result = new SqlServerDepartment();
        else if(_db == "Access")
            result = new AccessDepartment();
        return result;
    }

private:
    static const QString _db;  //注意：静态非整型数据成员，必须定义为const，且在类外初始化
};

//const QString DataAccess::_db = QString::fromUtf8("Sqlserver");
const QString DataAccess::_db = QString::fromUtf8("Access");   //把上面那句话取消注释，本行加上注释，就是使用sql服务的相关操作
#endif

#endif // DATAACCESS_H
