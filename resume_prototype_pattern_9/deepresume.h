#ifndef DEEPRESUME
#define DEEPRESUME
#include <QString>
#include <QtDebug>

//#define use_shearedPtr  //如果不想使用智能指针，注释掉这一行即可

class WorkExperience
{
public:
    explicit WorkExperience(QString ta,QString c):_timeArea(ta),_company(c){}
    QString getTimeArea(){return _timeArea;}
    QString getCompney() {return _company;}
private:
    QString _timeArea;
    QString _company;
};

class DeepResume
{
public:
    explicit DeepResume(QString name):_name(name){}
    DeepResume(const DeepResume & r) //自己实现拷贝构造函数,注意第二行实现的深拷贝！！
    //注意：拷贝构造函数可以调用引用参数对象的私有成员！！
    //因为拷贝构造函数是放在本身这个类里的，而类中的函数可以访问这个类的对象的所有成员，当然包括私有成员了。
    {   _name = r._name;_sex=r._sex;_age=r._age;
#ifdef use_shearedPtr
        _we = QSharedPointer<WorkExperience>(new WorkExperience(*r._we));
#else
        _we = new WorkExperience(*r._we);
#endif
    }
#ifndef use_shearedPtr
    DeepResume & operator =(const DeepResume &) = delete;
    ~DeepResume()
    {

        if(_we != nullptr)
        {
            qDebug()<<"删除了构造的工作经验";
            delete _we;
            _we = nullptr;
        }
    }
#endif
    void setPersonalInf(QString sex, QString age)
    {
        _sex = sex;
        _age = age;
    }
    void setWorkExperience(WorkExperience *we)
    {
#ifdef use_shearedPtr
        _we = QSharedPointer<WorkExperience>(we);
#else
        _we = we;
#endif
    }
    void display()
    {
        qDebug() << _name<<","<<_sex<<","<<_age;
        qDebug() <<"工作经历："<<_we->getTimeArea()<<_we->getCompney();
    }
    DeepResume* clone() {return new DeepResume(*this);}  //这里返回使用默认拷贝构造函数的结果，因此每个值都拷贝了，有指针，因此深拷贝才行！
private:
    QString _name;
    QString _sex;
    QString _age;
#ifdef use_shearedPtr
    QSharedPointer<WorkExperience> _we;
#else
    WorkExperience *_we;
#endif
};

#endif // DEEPRESUME

