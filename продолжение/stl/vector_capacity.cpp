#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

int main()
{
    default_random_engine gen; //генератор случайных чисел
    //равномерное распределение от 0 до 10.0
    uniform_real_distribution<double> dist(0.0,10.0);
    auto begin = std::chrono::steady_clock::now();
    vector<double> v1;
    cout << "v1 - > size: " << v1.size() << "; capacity: " << v1.capacity() << endl;
    //1. Определим, как меняется емкость вектора при добавлении элементов

    //TODO: в цикле от 0 до N (N пусть, к примеру, равно 30 или какому-нибудь другому числу)
    //TODO: добавляем случайное число в вектор
    /*TODO: смотрим размер вектора (функция size) и емкость (функция capacity)
            определяем, в какие моменты вектор увеличивает емкость и во вколько раз */
    for (int i=0; i<30; i++)
    {
        	v1.push_back(dist(gen));
        	cout << "add " << i << " elem" << endl;
        	cout << "size: " << v1.size() << "; capacity: " << v1.capacity() << endl;
    }
    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "Отчет: Емкость увеличивается в 2 раза, \
    		 когда размер вектора становится больше исходной емкости" << endl;
    cout << "The time: " << elapsed_ms.count() << " ns\n";
    cout << " " << endl;
    cout << "v2" << endl;

    vector<int> v2;
    cout << "size: " << v2.size() << "; capacity: " << v2.capacity() << endl;
    /*2. Определим, как меняется емкость вектора при добавлении элементов, если установлена
         начальная емкость */

    // TODO: задаем начальную емкость вектора (функция reserve)
    v2.reserve(29);
    cout << "After reserve -> size: " << v2.size() << "; capacity: " << v2.capacity() << endl;
    /* TODO: в цикле добавляем элементы так же, как и в предыдущем пункте,
             определяем, как меняется емкость */
    for (int i=0; i<30; i++)
        {
            	v2.push_back(dist(gen));
            	cout << "add " << i << " elem" << endl;
            	cout << "size: " << v2.size() << "; capacity: " << v2.capacity() << endl;
        }
    auto theend = std::chrono::steady_clock::now();
    auto elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(theend - end);
    cout << "The time: " << elapsed_ns.count() << " ns\n";
    cout << "Отчет: Емкость увеличивается также в 2 раза, \
        		 когда размер вектора становится больше исходной емкости" << endl;
    cout << "Второй вариант быстрее ";
}
