#ifndef MOBILE_H
#define MOBILE_H

#include <QDebug>

class HandsetSoft   //手机软件抽象类
{
public:
    virtual void Run() = 0;
    virtual ~HandsetSoft(){}
};

class HandsetGame final : public HandsetSoft   //手机游戏
{
public:
    void Run() override
    {
        qDebug()<<"运行手机游戏";
    }
};

class HandsetAddressList final : public HandsetSoft
{
public:
    void Run() override
    {
        qDebug()<<"运行手机通讯录";
    }
};

class HandsetMP3 final : public HandsetSoft
{
public:
    void Run() override
    {
        qDebug()<<"运行手机MP3播放";
    }
};

class HandsetBrand   //手机品牌抽象类
{
public:
    virtual void Run() = 0;
    void setHandsetSoft(HandsetSoft * soft)
    {
        _soft = QSharedPointer<HandsetSoft>(soft);
    }
    virtual ~HandsetBrand(){}
protected:
    QSharedPointer<HandsetSoft> _soft;
};

class HandsetBrandN final : public HandsetBrand
{
public:
    void Run() override
    {
        qDebug()<<"N类型的手机：";
        _soft->Run();
    }
};

class HandsetBrandM final : public HandsetBrand
{
public:
    void Run() override
    {
        qDebug()<<"M类型的手机：";
        _soft->Run();
    }
};

class HandsetBrandS final : public HandsetBrand
{
public:
    void Run() override
    {
        qDebug()<<"S类型的手机：";
        _soft->Run();
    }
};

#endif // MOBILE_H
