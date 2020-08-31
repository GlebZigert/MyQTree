#include "id.h"


int ID::s_nextID=1;

int ID::getNextID()
{
    return ++s_nextID;
}

void ID::set_zero()
{
    s_nextID=0;
}
