
#include <iostream>

using namespace std;

template<unsigned N>
struct factorial
{
    static const unsigned value = N * factorial<N - 1>::value;
};
template<>
struct factorial<0>
{
    static const unsigned value = 1;

};

template<unsigned N, unsigned K>
struct C
{
    static const unsigned value = factorial<N>::value / factorial<K>::value / factorial<N-K>::value;
};

int main()
{
    const unsigned i = C<6, 3>::value;
    cout << i;

    return 0;
}
