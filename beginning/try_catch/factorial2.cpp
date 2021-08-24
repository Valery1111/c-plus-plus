#include <iostream>
using namespace std;

long double f(int x)
{
    if(x < 0)
        throw "Can not take factorial of negative number";
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

    try
    {
        int d = f(x);
        cout << "x! = " << f(x) << endl;
    }
    catch (const char* exception) // обработка исключений типа const char*
    {
        std::cerr << "Error: " << exception << std::endl;
    }
    return 0;
}
