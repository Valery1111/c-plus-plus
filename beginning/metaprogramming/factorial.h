#ifndef FACTORIAL_H_INCLUDED
#define FACTORIAL_H_INCLUDED

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

#endif // FACTORIAL_H_INCLUDED
