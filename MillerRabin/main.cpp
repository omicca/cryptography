#include <iostream>
#include "funtions.h"

int main()
{
    //gather all primes to a certain limit
    std::vector primes = soe(100);

    //witnesses (a) for miller_rabin
    std::vector<long long> witnesses = {2, 7, 61};

    std::vector<PrimeInfo> results;
    results.reserve(primes.size());

    for (const auto& n : primes) {
        bool prime = is_prime(n, witnesses);
        results.push_back(PrimeInfo{n, prime});
    }

    for (PrimeInfo n : results) {
        std::cout << "Number: " << n.number << " | Probably prime: " << n.is_prime << "\n";
    }

    return 0;
}
