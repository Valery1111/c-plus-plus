#include <iostream>
using namespace std;

void me(int *A, int first, int last)
{
    int middle, start, final, j;
    int *mas = new int[100];
    middle = (first + last) / 2;
    start = first;
    final = middle + 1;
    for(j = first; j <= last; j++)
        if ((start <= middle) && ((final > last) || (A[start] < A[final])))
        {
            mas[j] = A[start];
            start++;
        }
        else
        {
            mas[j] = A[final];
            final++;
        }

    for (j = first; j <= last; j++) A[j] = mas[j];
        delete []mas;
};

void merge(int *A, int first, int last)
{
    if (first < last)
{
    merge(A, first, (first + last) / 2);
    merge(A, (first + last) / 2+1, last);
    me(A, first, last);
}
};

int main()
{
    setlocale(LC_ALL, "rus");
    int i, n;
    int *A=new int[100];
    cout<<"Размер массива: "; cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> A[i];
    }
    merge(A, 1, n);
    cout << "Упорядоченный массив: ";
    for (i = 1; i <= n; i++) cout << A[i] << " ";
    delete []A;
}
