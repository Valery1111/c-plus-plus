#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <random>

using namespace std;

void dropDup(std::vector<int>& v)
{
    for( auto base = v.begin(); base != v.end(); ++base )
    {
        for( auto it = base + 1; it != v.end(); )
        {
            if( *base == *it )
            {
                it = v.erase(it);
            }
            else
            {
                ++it;
            }
        }
    }
}

bool isEven (int elem) {return elem % 2 == 0;}

bool simple(int n){
	if (n == 1) return 0;
    for(int i=2;i<= n/2;i++)
    	if( (n%i)==0 )
    		return 0;
    return 1;
}

int minuszero(int i) {
	return (i < 0 ? 0 : i);
}

vector<int> operator-(const vector<int>&a, const vector<int>&b)
{
    if (a.size() != b.size())
        throw("a.size() != b.size()"); // Или как-то иначе обработать разные размеры
    vector<int> c(a.size());
    for(size_t i = 0; i < a.size(); ++i)
        c[i] = a[i] - b[i];
    return c;
}

int main(int argc, char **argv)
{
	//task1
    vector<int> p1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int buffer;
    while (cin >> buffer) {
    	p1.push_back(buffer);
    }
    random_shuffle(p1.begin(), p1.end());
    cout << "p1: ";
    for (auto const &element: p1)
         cout << element << ' ';
    cout << endl;
    dropDup(p1);
    cout << "p1/duplicates: ";
    for (auto const &element: p1)
         cout << element << ' ';
    cout << endl;

    //task2
    cout << "the number of even elements from p1: " << count_if(p1.begin(), p1.end(), isEven) << endl;
    cout << "minimum from p1: " << *min_element(p1.begin(), p1.end()) << endl;
    cout << "maximum from p1: " << *max_element(p1.begin(), p1.end()) << endl;
    std::vector<int>::iterator prosto = p1.begin();
    cout << "prosti chisla:" << endl;
    while ((prosto = find_if(prosto, p1.end(), simple)) != p1.end())
    {
        cout << "elem№" << prosto - p1.begin() << " is " << *prosto << endl;
        prosto++;
    }
    transform (p1.begin(), p1.end(), p1.begin(), p1.begin(), multiplies<int>());
    cout << "p1 after multiplies: ";
    for (auto const &element: p1)
        cout << element << ' ';
    cout << endl;

    //task3
    vector<int> p2;
    cout << "p2: ";

    default_random_engine gen; //генератор случайных чисел
    //равномерное распределение от 0 до 2000
    uniform_int_distribution<int> dist(-200, 200);
    for (int i=0; i<int(p1.size()); i++)
    {
        	p2.push_back(dist(gen));
    }
    //generate_n (back_inserter(p2), int(p1.size()), rand);
    for (auto const &element: p2)
        cout << element << ' ';
    cout << endl;
    cout << "sum in p2: " << accumulate(p2.begin(), p2.end(), 0) << endl;
    fill_n(p2.begin(), 4, 1);
    auto p3 = p1 - p2;
    //vector<int> p3;
    //set_difference(p1.begin(), p1.end(), p2.begin(), p2.end(), inserter(p3, p3.begin()));
    cout << "p3: ";
    for (auto const &element: p3)
            cout << element << ' ';
    cout << endl;

    //task4
    replace_if(p3.begin(), p3.end(), [](int i){return (i < 0 ? true : false);}, int(0));
    //transform (p3.begin(), p3.end(), p3.begin(), minuszero);
    std::vector<int>::iterator index = remove(p3.begin(), p3.end(), int(0));
    p3.erase(p3.begin() + distance(p3.begin(), index), p3.end());
    reverse (p3.begin(),p3.end());
    cout << "p3: ";
    for (auto const &element: p3)
            cout << element << ' ';
    cout << endl << "top 3:  ";
    nth_element(p3.begin(),p3.end()-3, p3.end());
    copy(p3.end()-3, p3.end(), ostream_iterator<int>(cout," "));
    return 0;
}
