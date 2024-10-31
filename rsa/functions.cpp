#include "functions.h"

long long PrimalityGen::powmod(long long base, long long exponent, long long modulus) {
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

bool PrimalityGen::miller_rabin(long long n, long long a) {
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

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}