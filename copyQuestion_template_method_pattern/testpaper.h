#ifndef TESTPAPER
#define TESTPAPER
#include <QString>
#include <QtDebug>

class TestPaper
{
public:
    TestPaper(){}
    void question1()
    {
        qDebug()<<"第一题"<<"答案"<<Answer1();
    }
    void question2()
    {
        qDebug()<<"第一题"<<"答案"<<Answer2();
    }
protected:
    QString virtual Answer1()=0;
    QString virtual Answer2()=0;
};

class TestPaper1:public TestPaper
{
public:
    QString Answer1()
    {
        return "A";
    }
    QString Answer2()
    {
        return "B";
    }
};

class TestPaper2:public TestPaper
{
public:
    QString Answer1()
    {
        return "C";
    }
    QString Answer2()
    {
        return "D";
    }
};
#endif // TESTPAPER

