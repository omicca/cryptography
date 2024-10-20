#include <iostream>
#include "funtions.h"

int main()
{
    std::vector primes = soe(150000000);

    std::vector<long long> witnesses = {2, 7, 61};

    std::vector<bool> results;
    results.reserve(primes.size()); 

    for (const auto& n : primes) {
        bool prime = is_prime(n, witnesses);
        results.push_back(prime);
    }

    std::cout << primes.size() << " and " << results.size() << std::endl;

    return 0;
}
