#include "rsa.h"
#include "functions.h"

int rsa(int p, int q)
{
    //mod calc
    int n = p * q;

    //totient
    const int t = (p - 1) * (q - 1);

    for (int e = t - 1; 1 < e && e < t; e--)
    {
        if (gcd(e, t) == 1)
        {

        }
    }

}