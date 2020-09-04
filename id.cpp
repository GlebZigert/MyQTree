#include "id.h"


int ID::s_nextID=1;
int ID::s_nextID_real=1;

int ID::getNextID()
{
    return ++s_nextID;
}

void ID::set_zero()
{
    s_nextID=0;
}


int ID::getNextID_real()
{
    return ++s_nextID_real;
}

void ID::set_zero_real()
{
    s_nextID_real=0;
}

