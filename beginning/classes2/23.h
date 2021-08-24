#ifndef 23_H_INCLUDED
#define 23_H_INCLUDED


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

};



#endif // 23_H_INCLUDED
