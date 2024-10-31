#include<iostream>
#include "functions.h"

int main()
{
    PrimalityGen g1;

    bool res = g1.miller_rabin(47, 2);

    std::cout << res << std::endl;

    return 0;
}