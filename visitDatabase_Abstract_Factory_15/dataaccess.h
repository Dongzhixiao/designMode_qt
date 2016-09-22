#ifndef DATAACCESS_H
#define DATAACCESS_H

#include "user.h"

#ifdef use_reflect
Q_DECLARE_METATYPE(SqlServerUser)
Q_DECLARE_METATYPE(AccessUser)
Q_DECLARE_METATYPE(SqlServerDepartment)
Q_DECLARE_METATYPE(AccessDepartment)
void RegisterMetaType()
{
    qRegisterMetaType<SqlServerUser>();
    qRegisterMetaType<AccessUser>();
    qRegisterMetaType<SqlServerDepartment>();
    qRegisterMetaType<AccessDepartment>();
}
class DataAccess
{
public:
    static IUser* CreatUser()
    {
        IUser* result = nullptr;
        QString className = _db + "User";
        int id = QMetaType::type(className.toLatin1());
         if (id != QMetaType::UnknownType)
             result = static_cast<IUser*>(QMetaType::create(id));
         else
             qDebug()<<"没有在Qt中注册成功"<<className<<"类";
        return result;
    }
    static IDepartment* CreatDepartment()
    {
        IDepartment* result = nullptr;
        QString className = _db + "Department";
        int id = QMetaType::type(className.toLatin1());
         if (id != QMetaType::UnknownType)
             result = static_cast<IDepartment*>(QMetaType::create(id));
         else
             qDebug()<<"没有在Qt中注册成功"<<className<<"类";
        return result;
    }
private:
    static const QString _db;  //注意：静态非整型数据成员，必须定义为const，且在类外初始化
};

#ifdef use_SQLServer
const QString DataAccess::_db = QString::fromUtf8("SqlServer");
#else
const QString DataAccess::_db = QString::fromUtf8("Access");   //把上面那句话取消注释，本行加上注释，就是使用sql服务的相关操作
#endif

#else
class DataAccess
{
public:
    static IUser* CreatUser()
    {
        IUser* result = nullptr;
        if(_db == "SqlServer")
            result = new SqlServerUser();
        else if(_db == "Access")
            result = new AccessUser();
        return result;
    }
    static IDepartment* CreatDepartment()
    {
        IDepartment* result = nullptr;
        if(_db == "SqlServer")
            result = new SqlServerDepartment();
        else if(_db == "Access")
            result = new AccessDepartment();
        return result;
    }
private:
    static const QString _db;  //注意：静态非整型数据成员，必须定义为const，且在类外初始化
};

#ifdef use_SQLServer
const QString DataAccess::_db = QString::fromUtf8("SqlServer");
#else
const QString DataAccess::_db = QString::fromUtf8("Access");   //把上面那句话取消注释，本行加上注释，就是使用sql服务的相关操作
#endif

#endif

#endif // DATAACCESS_H
