#include <iostream>
#include <cmath>

int main()
{
    double x;
    std::cin >> x;
    std::cout << "sin:" << sin(x) << std::endl;
    std::cout << "cos:" << cos(x) << std::endl;
    std::cout << "exp:" << exp(x) << std::endl;
    std::cout << "ceil:" << ceil( x ) << std::endl;
    std::cout << "floor:" << floor( x ) << std::endl;
    return 0;
}
