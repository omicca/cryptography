#include <iostream>
#include "funtions.h"

int main()
{
    std::vector primes = soe(150000000);

    // Define a set of witnesses.
    // For n < 4,759,123,141, the following set {2, 7, 61} is sufficient for deterministic results.
    std::vector<long long> witnesses = {2, 7, 61};

    // Vector to store results
    std::vector<bool> results;
    results.reserve(primes.size()); // Reserve space to optimize performance

    // Iterate through each number and test for primality
    for (const auto& n : primes) {
        bool prime = is_prime(n, witnesses);
        results.push_back(prime);
    }

    std::cout << primes.size() << " and " << results.size() << std::endl;

    return 0;
}
