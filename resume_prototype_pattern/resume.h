#ifndef RESUME
#define RESUME
#include <QString>
#include <QtDebug>

class Resume
{
public:
    explicit Resume(QString name):_name(name){}
//    Resume(const Resume & r) //也可以自己实现拷贝构造函数
//    {_name = r._name;_sex=r._sex;_age=r._age;_timeArea=r._timeArea;_company=r._company;}
    void setPersonalInf(QString sex, QString age)
    {
        _sex = sex;
        _age = age;
    }
    void setPersonalExperience(QString timeArea, QString company)
    {
        _timeArea = timeArea;
        _company = company;
    }
    void display()
    {
        qDebug() << _name<<","<<_sex<<","<<_age;
        qDebug() <<"工作经历："<<_timeArea <<_company;
    }
    Resume* clone() {return new Resume(*this);}  //这里返回使用默认拷贝构造函数的结果，因此每个值都拷贝了，没有指针，因此浅拷贝就行！
private:
    QString _name;
    QString _sex;
    QString _age;
    QString _timeArea;
    QString _company;
};

#endif // RESUME

