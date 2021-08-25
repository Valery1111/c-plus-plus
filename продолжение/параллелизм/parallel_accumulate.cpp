// parallel_acum.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <math.h>

#include <algorithm>
#include <future>
#include <iostream>
#include <numeric>
#include <thread>
#include <vector>
#include <chrono>

using namespace std;

using namespace chrono;


template<typename Iterator, typename T>
struct accumulate_block {
	void operator()(Iterator first, Iterator last, T& result) {
		result = std::accumulate(first, last, result);
	}
};


template<typename Iterator, typename T>
T parallel_accumulate(Iterator first, Iterator last, T init, unsigned long const num_threads) {
	unsigned long const length = std::distance(first, last);
	if (!length)
		return init;
		
	unsigned long const block_size = length / num_threads;

	std::vector<T> results(num_threads);
	std::vector<std::thread> threads(num_threads - 1);

	Iterator block_start = first;
	for (unsigned long i = 0; i < (num_threads - 1); ++i) {
		Iterator block_end = block_start;
		std::advance(block_end, block_size);
		threads[i] = std::thread(accumulate_block<Iterator, T>(), block_start, block_end, std::ref(results[i]));
		block_start = block_end;
	}

	accumulate_block<Iterator, T>() (block_start, last, results[num_threads - 1]);

	std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));
	return
		std::accumulate(results.begin(), results.end(), init);
};

int main(void)
{
	std::vector < int > v(100);

	std::iota(v.begin(), v.end(), 1);
	
	float x;
	HDC hDC = GetDC(GetConsoleWindow());
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	SelectObject(hDC, Pen);
	MoveToEx(hDC, 10, 0, NULL);
	LineTo(hDC, 10, 260);
	MoveToEx(hDC, 0, 250, NULL);
	LineTo(hDC, 200, 250);

	auto s = high_resolution_clock::now();
	parallel_accumulate(v.begin(), v.end(), 0, 1);
	auto e = high_resolution_clock::now();
	auto oldtime = std::chrono::duration_cast<std::chrono::microseconds>(e - s);
	//cout << ", M=" << 1 << " is " << oldtime.count() << " mcs\n";

	for (unsigned long i=2; i<15; i++)
	{
		auto start = high_resolution_clock::now();
		parallel_accumulate(v.begin(), v.end(), 0, i);
		auto end = high_resolution_clock::now();
		auto elapsed_ns = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
		//cout << ", M=" << i << " is " << elapsed_ns.count() << " mcs\n";
		MoveToEx(hDC, 10 * (i-1) + 10, -0.2 * oldtime.count() + 250, NULL);//10 - scale
		LineTo(hDC, 10 * i + 10, -0.2 * elapsed_ns.count() + 250);
		oldtime = elapsed_ns;
	}
	
	//std::cout << parallel_accumulate(v.begin(), v.end(), 0, 2) << std::endl;
	//system("pause");

	std::cin.clear();
	std::cin.ignore(32767, '\n');
	std::cin.get();
	return 0;
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
