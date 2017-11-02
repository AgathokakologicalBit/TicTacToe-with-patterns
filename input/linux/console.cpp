// Copyright 2017 Ermishin Michael


#ifdef __linux__

#include <cstdlib>
#include "../console.h"


void Console::clear()
{
    system("clear");
}

#endif
