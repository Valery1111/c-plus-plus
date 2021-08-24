#include <iostream>

class Another
{
private:
    int m_nID;

public:
    /*
    Another(int nID)
    {
        std::cout << "Constructing Another " << nID << '\n';
        m_nID = nID;
    }
    */
    ~Another()
    {
        std::cout << "Destructing Another " << m_nID << '\n';
    }

    int getID() { return m_nID; }
};

int main()
{
    // Выделяем объект класса Another из стека
    Another object;
    std::cout << object.getID() << '\n';

    // Выделяем объект класса Another динамически из кучи


    return 0;
} // объект object выходит из области видимости здесь
