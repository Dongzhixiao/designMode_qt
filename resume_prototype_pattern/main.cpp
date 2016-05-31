#include "resume.h"
#include "deepresume.h"
#include <QtDebug>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    //浅拷贝的原型模式
    Resume *xd=new Resume("小东");
    xd->setPersonalExperience("2015-2016","恒通");
    xd->setPersonalInf("male","27");
    Resume xdd(*xd);
    xdd.display();
    xd->display();
    //深拷贝的原型模式
    DeepResume *xc = new DeepResume("小崔");
    xc->setPersonalInf("male","28");
    xc->setWorkExperience(new WorkExperience("2000-2001","电力"));
    DeepResume xcc(*xc);
    delete xc;   //因为使用了深拷贝，因此这里就算删除了xc，下面的函数依然可以正常运行，调用里面的WorkExperience类
    xcc.display();
    //xc->display();
    return 0;
}
