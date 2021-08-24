#include <iostream>
#include <stdlib.h>
using namespace std;
#define base 10

int length(long A)
{
    int count = 1;
    while (A != 0)
    {
        A /= base;
        ++count;
    }
    return count;
};

int max(int x, int y)
{
    if (x > y)
        return x;
    return y;
};

long multiply(long a, long b)
{
    int n, a_l, b_l;
    long res, a1, a2, b1, b2, prod1, prod2, prod3;
    a_l = length(a);
    b_l = length(b);
    n = max(length(a), length(b));

    if (n == 1) return a * b;

    a1 = (a - a % (base ^ (a_l / 2))) / (base ^ (a_l - a_l / 2));
    a2 = a % (base ^ (a_l / 2));

    b1 = (b - b % (base ^ (b_l / 2))) / (base ^ (b_l - b_l / 2));
    b2 = b % (base ^ (b_l / 2));

    prod1 = multiply(a1, b1);
    prod2 = multiply(a2, b2);
    prod3 = multiply(a1 + a2, b1 + b2);
    res = prod1 * (10 ^ n) + (prod3 - prod1 - prod2)*base ^ (n / 2) + prod2;

    return res;
}

int main()
{
    long X, Y, res1, res2;
    cout << "enter first" << endl;
    cin >> X;
    cout << "enter second" << endl;
    cin >> Y;
    res1 = X*Y;
    cout << res1 << "\n";
    res2 = multiply(X, Y);
    cout << res2;
    cin.get();
    return 0;
}
