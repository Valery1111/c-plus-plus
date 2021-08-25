#include <iostream>
#include <vector>
#include <random>
#include <unordered_set>
#include <algorithm>

using namespace std;

unsigned int RSHash(const char *str, unsigned int length)
{
    unsigned int b = 378551;
    unsigned int a = 63689;
    unsigned int hash = 0;
    unsigned int i = 0;

    for (i = 0; i < length; ++str, ++i)
    {
        hash = hash * a + (*str);
        a = a * b;
    }

    return hash;
}

unsigned int JSHash(const char *str, unsigned int length)
{
    unsigned int hash = 1315423911;
    unsigned int i = 0;

    for (i = 0; i < length; ++str, ++i)
    {
        hash ^= ((hash << 5) + (*str) + (hash >> 2));
    }

    return hash;
}

unsigned int PJWHash(const char *str, unsigned int length)
{
    const unsigned int BitsInUnsignedInt = (unsigned int) (sizeof(unsigned int)
            * 8);
    const unsigned int ThreeQuarters = (unsigned int) ((BitsInUnsignedInt * 3)
            / 4);
    const unsigned int OneEighth = (unsigned int) (BitsInUnsignedInt / 8);
    const unsigned int HighBits = (unsigned int) (0xFFFFFFFF)
            << (BitsInUnsignedInt - OneEighth);
    unsigned int hash = 0;
    unsigned int test = 0;
    unsigned int i = 0;

    for (i = 0; i < length; ++str, ++i)
    {
        hash = (hash << OneEighth) + (*str);

        if ((test = hash & HighBits) != 0)
        {
            hash = ((hash ^ (test >> ThreeQuarters)) & (~HighBits));
        }
    }

    return hash;
}

unsigned int ELFHash(const char *str, unsigned int length)
{
    unsigned int hash = 0;
    unsigned int x = 0;
    unsigned int i = 0;

    for (i = 0; i < length; ++str, ++i)
    {
        hash = (hash << 4) + (*str);

        if ((x = hash & 0xF0000000L) != 0)
        {
            hash ^= (x >> 24);
        }

        hash &= ~x;
    }

    return hash;
}

unsigned int BKDRHash(const char *str, unsigned int length)
{
    unsigned int seed = 131; /* 31 131 1313 13131 131313 etc.. */
    unsigned int hash = 0;
    unsigned int i = 0;

    for (i = 0; i < length; ++str, ++i)
    {
        hash = (hash * seed) + (*str);
    }

    return hash;
}

unsigned int SDBMHash(const char *str, unsigned int length)
{
    unsigned int hash = 0;
    unsigned int i = 0;

    for (i = 0; i < length; ++str, ++i)
    {
        hash = (*str) + (hash << 6) + (hash << 16) - hash;
    }

    return hash;
}

unsigned int DJBHash(const char *str, unsigned int length)
{
    unsigned int hash = 5381;
    unsigned int i = 0;

    for (i = 0; i < length; ++str, ++i)
    {
        hash = ((hash << 5) + hash) + (*str);
    }

    return hash;
}

unsigned int DEKHash(const char *str, unsigned int length)
{
    unsigned int hash = length;
    unsigned int i = 0;

    for (i = 0; i < length; ++str, ++i)
    {
        hash = ((hash << 5) ^ (hash >> 27)) ^ (*str);
    }

    return hash;
}

unsigned int APHash(const char *str, unsigned int length)
{
    unsigned int hash = 0xAAAAAAAA;
    unsigned int i = 0;

    for (i = 0; i < length; ++str, ++i)
    {
        hash ^= ((i & 1) == 0) ?
                ((hash << 7) ^ (*str) * (hash >> 3)) :
                (~((hash << 11) + ((*str) ^ (hash >> 5))));
    }

    return hash;
}

void random_string(char *randomStr, size_t length)
{
    auto randchar = []() -> char
    {
        const char charset[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[ rand() % max_index ];
    };
    generate_n(randomStr, length, randchar);
}

void addHashIfNeeded(unordered_set<int> &hf_set, unsigned int hash, int &collisions)
{
    if (hf_set.find(hash) != hf_set.end())
        ++collisions;
    else
        hf_set.insert(hash);
}

int main()
{
    default_random_engine gen;
    uniform_int_distribution<int> dist(3, 10);
    vector<unordered_set<int>> v(9); // вектор из 9 unordered_set
    // каждый из unordered_set для соответствующей хэш-функции
    array<int, 9> collisions; // массив из 9 элементов для подсчета коллизий
    collisions.fill(0); // заполнение массива нулями
    char *randomStr;
    int length;
    int N = 326797; // N можно выбрать любое

    cout << "processing..." << endl;
    for (int i = 0; i < N; i++)
    {
        length = dist(gen);
        randomStr = new char[length];
        random_string(randomStr, length);

        addHashIfNeeded(v[0],   RSHash(randomStr, length), collisions[0]);
        addHashIfNeeded(v[1],   JSHash(randomStr, length), collisions[1]);
        addHashIfNeeded(v[2],  PJWHash(randomStr, length), collisions[2]);
        addHashIfNeeded(v[3],  ELFHash(randomStr, length), collisions[3]);
        addHashIfNeeded(v[4], BKDRHash(randomStr, length), collisions[4]);
        addHashIfNeeded(v[5], SDBMHash(randomStr, length), collisions[5]);
        addHashIfNeeded(v[6],  DJBHash(randomStr, length), collisions[6]);
        addHashIfNeeded(v[7],  DEKHash(randomStr, length), collisions[7]);
        addHashIfNeeded(v[8],   APHash(randomStr, length), collisions[8]);

    }
    cout << "rs:   " << collisions[0] << endl;
    cout << "js:   " << collisions[1] << endl;
    cout << "pjw:  " << collisions[2] << endl;
    cout << "elf:  " << collisions[3] << endl;
    cout << "bkdr: " << collisions[4] << endl;
    cout << "sdbm: " << collisions[5] << endl;
    cout << "djb:  " << collisions[6] << endl;
    cout << "dek:  " << collisions[7] << endl;
    cout << "ap:   " << collisions[8] << endl;

    /*
     * rs:   5489
     * js:   16624
     * pjw:  32651
     * elf:  32651
     * bkdr: 5485
     * sdbm: 5484
     * djb:  16596
     * dek:  16468
     * ap:   5488
     *
     * Вывод: наиболее эффективные функции: rs, bkdr, sdbm, ap;
     *        менее эффективные: js, djb, dek;
     *        наименее эффективные: pjw, elf;
     * Можно отметить, что для различных тестов фукнций pjw и elf, количество колизий совпадало.
     */

    return 0;
}
