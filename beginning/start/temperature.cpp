#include <iostream>

int main()
{
    const double K = 273.15;
    const double F1 = 1.8;
    const double F2 = 32;
    const double R = 0.8;
    double T;
    std::cout << "Enter the temperature in degrees Celsius:" << std::endl;
    std::cin >> T;
    std::cout << "Kelvin scale: " << T+K << " (K)" << std::endl;
    std::cout << "Fahrenheit scale: " << (F1*T + F2) << std::endl;
    std::cout << "Reaumur scale: " << (R*T) << std::endl;
    return 0;
}
