#include <iostream>
#include <random>
#include <chrono>
#include <vector>
#include <deque>
#include <list>
#include <array>
#include <iterator>
#include <algorithm>

using namespace std;
using namespace chrono;

// шаблон функции для измерения времени сортировки контейнера
template<typename T>
auto measureSortingTime(T container)
{
    auto start = high_resolution_clock::now();
    //TODO: отсортировать контейнер (чтобы работало для vector, array и deque)
    /* VARIANT ONE
    for (int i = 0; i < 10000 - 1; i++) {
            for (int j = 0; j < 10000 - i - 1; j++) {
                if (container[j] > container[j + 1]) {
                    // меняем элементы местами
                    auto temp = container[j];
                    container[j] = container[j + 1];
                    container[j + 1] = temp;
                }
            }
        }
    */
    sort(container.begin(),container.end());
    //TODO: вычислить время сортировки и вернуть
    auto end = high_resolution_clock::now();
    auto elapsed_ns = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    cout << "The time for " << typeid(container).name() << " is " << elapsed_ns.count() << " ms\n";
}

// специализация шаблона для list
template<>
auto measureSortingTime(list<int> container)
{
    auto start = high_resolution_clock::now();
    //TODO: отсортировать list
    container.sort();
    //TODO: вычислить время сортивки и вернуть
    auto end = high_resolution_clock::now();
    auto elapsed_ns = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    cout << "The time for " << typeid(container).name() << " is " << elapsed_ns.count() << " ms\n";
}


int main()
{
    default_random_engine generator; //генератор случайных чисел
    uniform_int_distribution<int> distribution(0,10000); //равномерное распределение от 0 до 1000
    auto gen = [&distribution, &generator](){
                   return distribution(generator); // лямбда-функция, которая генерирует случайное число
               };
    //можно поэспериментировать с разными размерами контейнеров
    vector<int> v(100000);
    // заполнение вектора случайными числами
    generate(v.begin(), v.end(), gen);
    array<int, 100000> a;
    deque<int> d(100000);
    list<int> l(100000);
    // нам нужно, чтобы все контейнеры были запонены одинаковыми даннными
    // поэтому скопируем данные из вектора в другие контейнеры
    copy (v.begin(), v.end(), a.begin()); //копирование элементов вектора v в массив a
    copy (v.begin(), v.end(), d.begin());
    copy (v.begin(), v.end(), l.begin());
    //sort(v.begin(), v.end()); // сортировка у vector, array и deque
    //l.sort() // сортировка у list

    /* TODO: выполнить функцию measureSortingTime для vector, array и deque
             и определить, какой из контейнеров сортируется быстрее */
    measureSortingTime(v);
    measureSortingTime(a);
    measureSortingTime(d);
    measureSortingTime(l);

    return 0;
}
