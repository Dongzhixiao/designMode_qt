#include "workstatus.h"

Work::Work()
{_state = new ForenoonState();}

void Work::writeProgram()
{_state->writeProgram(*this);}
