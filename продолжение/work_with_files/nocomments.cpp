#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // для использования функции exit()

int main()
{
	using namespace std;

	ifstream inf("input.txt", ifstream::binary);

	// Если мы не можем открыть файл для чтения его содержимого,
	if (!inf)
	{
		// то выводим следующую ошибку и выполняем функцию exit()
		cerr << "Uh oh, file could not be opened for reading!" << endl;
		exit(1);
	}

	int n;
	cin >> n;
	int s = (n - 1) * 6;
	string strData;

	inf.seekg(s); // перемещаемся к 6-му символу первой строки
	// Получаем остальную часть строки и выводим её на экран
	getline(inf, strData);
	cout << strData << endl;

	return 0;
}
