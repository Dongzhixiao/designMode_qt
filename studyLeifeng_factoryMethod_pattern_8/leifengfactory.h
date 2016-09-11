#ifndef LEIFENGFACTORY
#define LEIFENGFACTORY
#include "leifeng.h"

class LeiFenngInterface
{
public:
    virtual LeiFeng *CreateLeiFeng() = 0;
    virtual ~LeiFenngInterface(){}
};
class UndergraduateFactory final:public LeiFenngInterface
{
public:
    LeiFeng *CreateLeiFeng() override
    {
        return new Undergraduate();
    }
};
class VolunteerFactory final:public LeiFenngInterface
{
public:
    LeiFeng *CreateLeiFeng() override
    {
        return new Volunteer();
    }
};

#endif // LEIFENGFACTORY

