#include <unordered_set>
#include <random>
#include <string>
#include <iostream>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

// from boost (functional/hash):
// see http://www.boost.org/doc/libs/1_35_0/doc/html/hash/combine.html
template <typename T>
inline void hash_combine (size_t& seed, const T& val)
{
    seed ^= hash<T>()(val) + 0x9e3779b9 + (seed<<6) + (seed>>2);
}

// auxiliary generic functions to create a hash value using a seed
template <typename T>
inline void hash_val (size_t& seed, const T& val)
{
    hash_combine(seed,val);
}
template <typename T, typename... Types>
inline void hash_val (size_t& seed,
                      const T& val, const Types&... args)
{
    hash_combine(seed,val);
    hash_val(seed,args...);
}

// auxiliary generic function to create a hash value out of a heterogeneous list of arguments
template <typename... Types>
inline size_t hash_val (const Types&... args)
{
    size_t seed = 0;
    hash_val (seed, args...);
    return seed;
}

// PRINT_ELEMENTS()
// - prints optional string optstr followed by
// - all elements of the collection coll
// - in one line, separated by spaces
template <typename T>
inline void PRINT_ELEMENTS (const T& coll,
                            const string& optstr="")
{
    cout << optstr;
    for (const auto&  elem : coll) {
        cout << elem << ' ';
    }
    cout << endl;
}

using namespace std;

class Customer {
  private:
    string fname;
    string lname;
    long   no;
  public:
    Customer (const string& fn, const string& ln, long n)
      : fname(fn), lname(ln), no(n) {}
    friend ostream& operator << (ostream& strm, const Customer& c) {
        return strm << "[" << c.fname << "," << c.lname << ","
                           << c.no << "]";
    }
    friend class CustomerHash;
    friend class CustomerEqual;
};

class CustomerHash
{
  public:
    size_t operator() (const Customer& c) const {
        return hash_val(c.fname,c.lname,c.no);
    }
};

class CustomerEqual
{
  public:
    bool operator() (const Customer& c1, const Customer& c2) const {
        return c1.no == c2.no;
    }
};

string random_string( size_t length )
{
    auto randchar = []() -> char
    {
        const char charset[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[ rand() % max_index ];
    };
    string str(length,0);
    generate_n( str.begin(), length, randchar );
    return str;
}

int main()
{
    default_random_engine gen;
    uniform_int_distribution<int> dist(3,10);
    uniform_int_distribution<int> distNum(100000,999999);
    CustomerHash chash;
    size_t hashNum;
    int lengthFname;
    int lengthLname;
    int number;
    string fname;
    string lname;

    const string fileName = "task2_table.csv";
    ofstream fout(fileName, ofstream::out);
    unordered_set<size_t> hfSet;
    int collisionCount = 0;

    int N;
    cin >> N;

    cout << "processing..." << endl;

    for (int i = 0; i < N; ++i) {
        lengthFname = dist(gen);
        lengthLname = dist(gen);
        number = distNum(gen);
        fname = random_string(lengthFname);
        lname = random_string(lengthLname);
        Customer customer(fname, lname, number);

        hashNum = chash(customer);

        if(hfSet.find(hashNum) != hfSet.end())
            ++collisionCount;
        else
            hfSet.insert(hashNum);

        fout << i << ";" << collisionCount << "\n";
    }

    fout.close();
    cout << "see result in " << fileName << endl;
    cout << "max collision count: " << collisionCount << endl;

    /*
     * 7654321
     * processing...
     * see result in task2_table.csv
     * max collision count: 0
     *
     * Вывод: коллизии отсутствуют, нет необходимости строить
     * график зависимости числа коллизий от количества экземпляров.
     */

    return 0;
}
