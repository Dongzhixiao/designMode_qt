#include "user.h"
#include "dataaccess.h"

//#define use_SQLServer
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
    User *user = new User();
    Department *department = new Department();


    IUser *iu = DataAccess::CreatUser();
    IDepartment *id = DataAccess::CreatDepartment();

    id->Insert(*department);
    iu->getUser(1);
    iu->Insert(*user);

    return 0;
}

