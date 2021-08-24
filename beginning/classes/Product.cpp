#include <iostream>

class Product
{
private:
    std::string m_id;
    double m_c;
    double m_u;

public:
    Product(std::string id="nth", double c=0, double u=0)
    {
        m_id = id;
        m_c = c;
        m_u = u;
    }

    double money()
    {
        return m_c * m_u;
    }
};

int main()
{
    Product first("hleb" );
    //Product second;
    std::cout << first.money();
    return 0;
}
