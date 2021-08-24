#include <iostream>
#include <deque>
using namespace std;

template <class T>
class Queue
{
private:
    deque<T> arr;

public:
    void push(const T  );
    void pop();
    T first();
    void printQueue();
};

template <class T>
void Queue<T>::push(const T value) { arr.push_back(value); }

template <class T>
void Queue<T>::pop() { arr.pop_front(); }

template <class T>
T Queue<T>::first() { return arr.front(); }

template <class T>
void Queue<T>::printQueue()
{
    for (int i = 0; i<arr.size(); i++)
        cout << arr[i] << endl;
}

template <>
class Queue<string>
{

private:
    deque<string> arstr;

public:
    void push(const string &value)
    {
        string v = value;
        arstr.push_back(v);
    }
    void pop() { arstr.pop_front(); }
    string first()
    {
        string f = arstr.front();
        return f;
    }
    void printQueue()
    {
        for (int i = 0; i<arstr.size(); i++)
            cout << arstr[i] << endl;
    }
};


int main()
{
    Queue<string> ones;
    int ct = 0;
    while(ct++ != 4)
    {
        string temp;
        cin >> temp;
        ones.push(temp);
    }
    ones.printQueue();
    return 0;
}
