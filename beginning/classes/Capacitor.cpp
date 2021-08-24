#include <iostream>

class Capacitor
{
private:
    double m_c;
    double m_u;

public:
    Capacitor(double c=0, double u=0)
    {
        m_c = c;
        m_u = u;
    }

    double energy()
    {
        return 0.5 * m_c * m_u * m_u;
    }
};

int main()
{
    //Capacitor first( 12, 1 );
    Capacitor second;
    std::cout << second.energy();
    return 0;
}
