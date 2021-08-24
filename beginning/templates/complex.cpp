#include <iostream>
#include <math.h>
using namespace std;

template <class T>
class Complex
{
private:
    T re, im;


public:

    Complex (T r=0.0, T i=0.0)
    {
        re = r;
        im = i;
    }

    Complex (Complex &c)
    {
        re = c.re;
        im = c.im;
    }

    float modul()
    {
        return sqrt(re * re + im * im);
    }
};

int main()
{
    Complex <int> one(1, 1);
    cout << one.modul();
    return 0;
}
