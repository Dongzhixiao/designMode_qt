#ifndef LEIFENGFACTORY
#define LEIFENGFACTORY
#include "leifeng.h"

class LeiFenngInterface
{
public:
    virtual LeiFeng *CreateLeiFeng()=0;
};
class UndergraduateFactory:public LeiFenngInterface
{
public:
    LeiFeng *CreateLeiFeng() override
    {
        return new Undergraduate();
    }
};
class VolunteerFactory:public LeiFenngInterface
{
public:
    LeiFeng *CreateLeiFeng() override
    {
        return new Volunteer();
    }
};

#endif // LEIFENGFACTORY

