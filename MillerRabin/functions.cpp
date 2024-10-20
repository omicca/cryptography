#include "funtions.h"
#include <cmath>
#include <iostream>


long long powmod(long long base, long long exponent, long long modulus) {
    if (modulus == 1) return 0;
    long long result = 1;
    base %= modulus;
    while (exponent > 0) {
        if (exponent & 1)
            result = (__int128(result) * base) % modulus;
        exponent >>= 1;
        base = (__int128(base) * base) % modulus;
    }
    return result;
}


bool miller_rabin(long long n, long long a) {
    if (n % a == 0)
        return false;

    long long d = n - 1;
    int s = 0;
    while (d % 2 == 0) {
        d /= 2;
        s += 1;
    }

    long long x = powmod(a, d, n);
    if (x == 1 || x == n - 1)
        return true;

    for (int r = 1; r < s; ++r) {
        x = (__int128(x) * x) % n;
        if (x == n - 1)
            return true;
    }

    return false;
}

bool is_prime(long long n, const std::vector<long long>& witnesses) {
    if (n < 2)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0)
        return false;

    for (long long a : witnesses) {
        if (a >= n)
            continue;
        if (!miller_rabin(n, a))
            return false;
    }
    return true;
}

// Finds primes in range using SoE from 100,000,000
std::vector<int> soe(int n)
{
    std::cout << "Finding primes between 100m-150m... \n";
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
        if (primes[i]) //Course specific test of i > 100000000
        {
            prime_list.push_back(i);
        }
    }

    return prime_list;
}

