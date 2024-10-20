#ifndef FUNTIONS_H
#define FUNTIONS_H
#include <vector>

struct PrimeInfo
{
    int number;
    bool is_prime;
};

std::vector<int> soe(int limit);
bool miller_rabin(long long n, long long a);
long long powmod(long long base, long long exponent, long long modulus);
bool is_prime(long long n, const std::vector<long long>& witnesses);

#endif
