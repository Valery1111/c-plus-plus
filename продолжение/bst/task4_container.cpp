#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include <algorithm>

using namespace std;

typedef map<string, string> Map;

struct record
{
    string name;
    string phone;

    record() {}
    record(const string &n, const string &p) : name(n), phone(p) {}
    friend ostream& operator <<(ostream &strm, const record &r)
    {
        return strm << "[" << r.name << "," << r.phone << "]";
    }
};

class phonebook
{
private:
    Map book;
public:
    void add(const record &val)
    {
        book[val.name] = val.phone;
    }
    void remove(const string &name)
    {
        book.erase(name);
    }

    friend class ordered_non_unique;
    friend class random_access;
    friend class hashed_non_unique;
};

class ordered_non_unique
{
private:
    phonebook *pbook;
    Map::iterator it;
public:
    ordered_non_unique(phonebook &b) :
            it(b.book.begin())
    {
        pbook = &b;
    }
    pair<bool, record> get_next_record()
    {
        bool status;
        record result;
        if (it != pbook->book.end())
        {
            result.name = it->first;
            result.phone = it->second;
            ++it;
            status = true;
        }
        else
        {
            status = false;
        }

        return pair<bool, record>(status, result);
    }
};
class random_access
{
private:
    phonebook *pbook;
public:
    random_access(phonebook &b)
    {
        pbook = &b;
    }
    record get_random_record()
    {
        Map::iterator it = pbook->book.begin();
        advance(it, rand() % pbook->book.size());
        return record(it->first, it->second);
    }
};
class hashed_non_unique
{
private:
    phonebook *pbook;
public:
    hashed_non_unique(phonebook &b)
    {
        pbook = &b;
    }
    string get(const string &name)
    {
        return pbook->book[name];
    }
};

int main()
{
    srand(time(nullptr));

    // создание телефонного справочника
    phonebook myPBook;

    // вставка элементов в контейнер
    myPBook.add({"name0", "89800000000"});
    myPBook.add({"name1", "89801111111"});
    myPBook.add({"name4", "89804444444"});
    myPBook.add({"name3", "89803333333"});
    myPBook.add({"name5", "89805555555"});
    myPBook.add({"name2", "89802222222"});

    // удаление элемента из контейнера
    myPBook.remove("name0");

    // вывод элементов в отсортированном по полю name порядке на экран
    ordered_non_unique b(myPBook);
    cout << "**sorted**" << endl;
    while (true)
    {
        auto r = b.get_next_record();
        if (r.first)
            cout << r.second << endl;
        else
            break;
    }

    // выовод 10 случайных элементов
    random_access c(myPBook);
    cout << "**random**" << endl;
    for (int i = 0; i < 10; i++)
    {
        auto r = c.get_random_record();
        cout << r << endl;
    }

    // поиск записей за минимальное время
    hashed_non_unique h(myPBook);
    cout << "**search**" << endl;
    cout << h.get("name2") << endl;
    cout << h.get("name5") << endl;
    cout << h.get("name0") << endl;

    return 0;
}
