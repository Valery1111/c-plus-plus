#include <iostream>

int main()
{
    int x = 5;
    int y = 9;
    x = x + y;
    y = x - y;
    x = x - y;
    std::cout << "x:" << x << "; y:" << y << std::endl;
    return 0;
}
