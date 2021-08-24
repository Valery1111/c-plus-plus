#include <iostream>
#include <vector>

using namespace std;

bool my_binary_search(vector<int>::iterator first, vector<int>::iterator last,
		int val)
{
	auto mid = first + (last - first) / 2;
	while (mid != last && *mid != val)
	{
		if (*mid > val)
			last = mid;
		if (*mid < val)
			first = mid + 1;
		mid = first + (last - first) / 2;
	}
	return mid != last;
}

int main()
{
	vector<int> v;
	for (int i = 0; i < 10; ++i)
		v.push_back(i);

	for (auto it = v.begin(); it != v.end(); ++it)
		cout << *it << " ";
	cout << endl;

	int sought;
	cout << "please, enter the number: " << endl;
	cin >> sought;
	bool result = my_binary_search(v.begin(), v.end(), sought);
	if (result)
		cout << " is in the vector" << endl;
	else
		cout << " is in the vector" << endl;

	return 0;
}

