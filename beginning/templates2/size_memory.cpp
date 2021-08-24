#include <iostream>
#include <string>
using namespace std;

template <typename T>
int siz(T arg) {  return sizeof(arg); }

template <typename T, typename... Types>
int siz(T firstArg, Types... args)
{
    return sizeof(firstArg) + siz(args...);
}

int main()
{
    cout << siz(2, "ter") << endl;
    return 0;
}
