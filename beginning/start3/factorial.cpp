#include <iostream>
using namespace std;

long double f(int x)
{
    if(x < 0)
        return 0;
    if (x == 0)
        return 1;
    else
        return x * f(x - 1);
}

int main()
{
    int x;
    cout << "x: ";
    cin >> x;
    cout << "x! = " << f(x) << endl;
    return 0;
}
