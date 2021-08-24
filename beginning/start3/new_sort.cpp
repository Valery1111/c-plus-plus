#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;


int main()
{
    const char c = '1';

    int n;
	std::cin >> n;
	std::vector<int> srcVec(n);
	for (int& item : srcVec)
	{
		std::cin >> item;
	}


	sort(srcVec.begin(), srcVec.end(),
	          [c] (int a, int b) -> double
	{
		switch(c)
        {
            case '1':
                return a < b;
            case '2':
                return a > b;
            case '3':
                return a <= b;
            case '4':
                return a >= b;
        }
	});

	for (auto a : srcVec) {
        cout << a << " ";
    }
    cout << '\n';
}
