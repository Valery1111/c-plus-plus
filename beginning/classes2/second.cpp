#include <iostream>

using namespace std;

class ArrayInt
{
private:
    int m_length;
    int *m_array;

public:
    ArrayInt()
    {
        m_length = 0;
        m_array = nullptr;
    }

    ArrayInt(int length)
    {
        m_length = length;
        m_array = new int[length];
    }

    ~ArrayInt()
    {
        delete[] m_array ;
    }

    void reallocate(int newlength)
    {
        delete[] m_array;
        m_array = new int[newlength];
    }

    void insertBefore(int value, int index)
    {
        int *arr = new int[m_length+1];

        for (int i=0; i < index; ++i)
            arr[i] = m_array[i];

        arr[index] = value;

        for (int j=index; j < m_length; ++j)
            arr[j+1] = m_array[j];

        delete[] m_array;
        m_array = arr;
        ++m_length;
    }

    int& operator[](int index)
    {
        return m_array[index];
    }
};

int main()
{
    // Объявляем массив с 10 элементами
    ArrayInt array(10);

    // Заполняем массив числами от 1 до 10
    for (int i=0; i<10; i++)
        array[i] = i+1;

    array.insertBefore(15, 4);

    for (int j=0; j<array.getLength(); j++)
        std::cout << array[j] << " ";

    return 0;
}
