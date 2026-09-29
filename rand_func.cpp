#include "rand_func.h"
#include <cstdlib>

int flipCoin()
{
    return rand() % 2;
}

int rollD6()
{
    return rand() % 6 + 1;
}

int rollD10()
{
    return rand() % 10 + 1;
}