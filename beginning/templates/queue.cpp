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

int main()
{
    Queue<int> ones;
    int ct = 0;
    for(int i = 0; i < 4; i++)
    {
        int temp;
        cin >> temp;
        ones.push(temp);
    }
    ones.printQueue();
    ones.pop();

    ones.printQueue();
    cout << ones.first();
    return 0;
}
