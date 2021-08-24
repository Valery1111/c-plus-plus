
#include <iostream>
#include "factorial.h"
using namespace std;


constexpr bool isPrime(unsigned int p)
{
    for (unsigned int d = 2; d < p/2; ++d)
    {
        if (p%d == 0)
        {
            return false;
        }
    }
    return p>1;
}

constexpr int nextPrime(int k)
{
    return isPrime(k)?k:nextPrime(k + 1);
}

constexpr int getPrimeLoop(int i, int k)
{
    return (i == 0)?k:getPrimeLoop(i - 1, nextPrime(k + 1));
}

constexpr int getPrime(int i)
{
    return getPrimeLoop(i, 2);
}

int main()
{
    cout << getPrime(4);
    return 0;
}
