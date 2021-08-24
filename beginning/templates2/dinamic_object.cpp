#include <iostream>
using namespace std;

template<typename T>
auto adress(T arg)
{
    T *ptr = new T(arg);
    return(ptr);
}

template<typename T, typename... Types>
auto adress(T first, Types... args)
{
    adress(first);
    adress(args...);
}

int main()
{
    cout << adress(5.1) << endl;
}
