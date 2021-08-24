#include <iostream>
#include <cmath>
using namespace std;


template<typename T, typename... Type>
auto uuff(T (*func)(Type...), Type... args)
{
    return func(args...);
}
