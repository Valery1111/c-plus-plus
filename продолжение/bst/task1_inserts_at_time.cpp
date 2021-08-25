#include <iostream>
#include <set>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

int main()
{
    srand(time(nullptr));
    int N;
    clock_t cstart, cend;
    double millis;

    cin >> N;
    set<int> tset;

    cstart = clock();

    for (int i = 0; i < N; ++i)
    {
        tset.insert(rand() % 1000);
    }

    cend = clock();
    millis = 1000.0 * (cend - cstart) / CLOCKS_PER_SEC;
    cout << "inserting " << N << " numbers in set: " << millis
            << " milliseconds\n";

    vector<int> vec;

    cstart = clock();

    for (int i = 0; i < N; ++i)
    {
        vec.push_back(rand() % 1000);
    }
    sort(vec.begin(), vec.end());

    cend = clock();
    millis = 1000.0 * (cend - cstart) / CLOCKS_PER_SEC;
    cout << "inserting " << N << " numbers in vector and sorting: " << millis
            << " milliseconds\n";
    /*
     * 1000000
     * inserting 1000000 numbers in set: 560.33 milliseconds
     * inserting 1000000 numbers in vector and sorting: 560.828 milliseconds
     *
     * 1234567
     * inserting 1234567 numbers in set: 676.379 milliseconds
     * inserting 1234567 numbers in vector and sorting: 687.696 milliseconds
     *
     * 7654321
     * inserting 7654321 numbers in set: 4302.45 milliseconds
     * inserting 7654321 numbers in vector and sorting: 5347.31 milliseconds
     *
     * Вывод: добавление N элементов в std::set производится быстрее.
     */

    return 0;
}

