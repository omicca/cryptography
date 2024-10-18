#include <iostream>
#include "funtions.h"

int main()
{
    std::vector primes = soe(1500000);

    for (int prime : primes) {
        std::cout << prime << std::endl;
    }

    return 0;
}
