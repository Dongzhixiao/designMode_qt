#define use_reflect   //如果不使用反射，注释掉这句话
#define use_SQLServer   //如果使用AccessServer,注释掉这句话

#include "user.h"
#include "dataaccess.h"

//下面注释掉的main函数是在不使用简单工厂模式改进抽象工厂模式的情况下的方式
//int main(int argc, char *argv[])
//{
//    Q_UNUSED(argc); Q_UNUSED(argv);
//    User *user = new User();
//    Department *department = new Department();
//#ifdef use_SQLServer
//    IFactory *factory = new SqlServerFactory();
//#else
//    IFactory *factory = new  AccessFactory();
//#endif
//    IUser *iu = factory->CreateUser();
//    IDepartment *id = factory->CreateDepartment();

//    id->Insert(*department);
//    iu->getUser(1);
//    iu->Insert(*user);

//    return 0;
//}


int main(int argc, char *argv[])
{
    Q_UNUSED(argc); Q_UNUSED(argv);
#ifdef use_reflect
    RegisterMetaType();
#endif
    User *user = new User();
    Department *department = new Department();

    IUser *iu = DataAccess::CreatUser();
    IDepartment *id = DataAccess::CreatDepartment();

    id->Insert(*department);
    iu->getUser(1);
    iu->Insert(*user);

    return 0;
}
