// proba.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <thread>
#include <vector>
#include <algorithm>
#include <functional>
#include <chrono>
#include <numeric>

using namespace std;
using namespace chrono;


static int rrand(int range_min, int range_max)
{
    return rand() % (range_max - range_min + 1) + range_min;
}

void chislopi(unsigned n, unsigned  side, unsigned qside, unsigned   &cnt)
{
    for (int i = 0; i < n; ++i)
    {
        unsigned x = rrand(0, side);
        unsigned y = rrand(0, side);

        if ((x * x + y * y) < qside) ++cnt;
    }
    
}

int main()
{
    auto start = high_resolution_clock::now();

    srand((unsigned)time(0));

    unsigned NUMBER = 300000;
    unsigned   cnt = 0;
    unsigned  side = 1000;
    unsigned qside = side * side;
    unsigned n = unsigned int(NUMBER / 4);
    vector<unsigned int> cnti{ 0, 0, 0, 0 };
    
    
    std::vector<std::thread> threads;
    for (unsigned i = 0; i <4; ++i) {
       
        threads.push_back(std::thread(chislopi, n, side, qside, ref(cnti[i])));
        
    }
    std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));
    cnt = std::accumulate(cnti.begin(), cnti.end(), 0);
    //chislopi(n, side, qside, ref(cnt));

    std::cout << double(cnt * 4) / NUMBER << "\n";

    auto end = high_resolution_clock::now();
    auto elapsed_ns = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "time is " << elapsed_ns.count() << " mcs\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
