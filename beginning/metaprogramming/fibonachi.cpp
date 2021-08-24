
#include <iostream>

using namespace std;

template<unsigned N>
struct fib
{
    static const unsigned value = fib<N - 2>::value + fib<N - 1>::value;
};
template<>
struct fib<0>
{
    static const unsigned value = 0;
};
template<>
struct fib<1>
{
    static const unsigned value = 0;
};
template<>
struct fib<2>
{
    static const unsigned value = 1;
};

int main()
{
    const unsigned f13 = fib<13>::value;
    cout << f13;

    return 0;
}
