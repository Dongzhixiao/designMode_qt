#include "user.h"

int main(int argc, char *argv[])
{
    User *user = new User();
    Department *department = new Department();

    IFactory *factory = new SqlServerFactory(); //或者new AccessFactory();

    IUser *iu = factory->CreateUser();
    IDepartment *id = factory->CreateDepartment();

    id->Insert(*department);
    //iu->getUser(1);  //这个函数返回值有问题，以后学习是注意
    iu->Insert(*user);

    return 0;
}
