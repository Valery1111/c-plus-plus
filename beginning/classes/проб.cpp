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
    // �������� ������ ������ Another �� �����
    Another object;
    std::cout << object.getID() << '\n';

    // �������� ������ ������ Another ����������� �� ����


    return 0;
} // ������ object ������� �� ������� ��������� �����
