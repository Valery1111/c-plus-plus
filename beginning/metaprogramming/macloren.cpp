#include <iostream>
#include "factorial.h"
using namespace std;

template<unsigned N>
struct exp_series
{
    static constexpr double value = 1 / double(factorial<N>::value) + exp_series<N - 1>::value;
};
template<>
struct exp_series<0>
{
    static const unsigned value = 1;
};
int main()
{
    constexpr double e = exp_series<3>::value;
    cout << e;

    return 0;
}
