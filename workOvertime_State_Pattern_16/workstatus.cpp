#include "workstatus.h"

Work::Work()
{_state = QSharedPointer<State>(new ForenoonState());}

void Work::writeProgram()
{_state->writeProgram(*this);}
