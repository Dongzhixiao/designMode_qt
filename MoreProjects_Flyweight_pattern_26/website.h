#ifndef WEBSITE_H
#define WEBSITE_H

class WebSite
{
public:
    virtual void Use() = 0;
};

class ConcreteWebSite final : public WebSite
{

};

#endif // WEBSITE_H
