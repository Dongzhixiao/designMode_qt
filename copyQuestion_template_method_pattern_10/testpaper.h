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
    virtual ~TestPaper(){}
protected:
    QString virtual Answer1()=0;
    QString virtual Answer2()=0;
};

class TestPaper1 final:public TestPaper
{
public:
    QString Answer1() override
    {
        return "A";
    }
    QString Answer2() override
    {
        return "B";
    }
};

class TestPaper2:public TestPaper
{
public:
    QString Answer1() override
    {
        return "C";
    }
    QString Answer2() override
    {
        return "D";
    }
};
#endif // TESTPAPER

