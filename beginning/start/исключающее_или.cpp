#include <iostream>

int main()
{
	int x, y;
	std::cin >> x >> y;
	std::cout << !(!(!x && y) && !(x && !y)) << std::endl;
	return 0;
}
