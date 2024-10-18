#include "funtions.h"
#include <cmath>

// Finds primes in range using SoE from 100,000,000
std::vector<int> soe(int n)
{
    std::vector<bool> primes(n + 1, true);
    primes[0] = primes[1] = false;

    //SoE
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (primes[i])
        {
            for (int j = i * i; j <= n; j +=i)
            {
                primes[j] = false;
            }
        }
    }

    std::vector<int> prime_list;
    for (int i = 0; i <= n; ++i)
    {
        if (primes[i])
        {
            prime_list.push_back(i);
        }
    }

    return prime_list;
}