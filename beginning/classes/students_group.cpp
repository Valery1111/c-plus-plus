#include <iostream>
#include <vector>

using namespace std;

class Student
{
private:
    string m_name;
    string m_secondname;
    double m_b;

public:
    Student(string name="nbd", string secondname="nbd", double b=0)
    {
        m_name = name;
        m_secondname = secondname;
        m_b = b;
    }

    double GetB() { return m_b; }
};

class Group
{
public:
    vector<Student> v;

    Group add(Student &s)
    {
        v.push_back(s);
    }

    double avscore()
    {
        double score = 0;
        for (Student n : v)
        {
            score += n.GetB();
        }
        return score/2;
    }

    ~Group()
    {
        v.clear ();
    }
};

int main()
{
    Student first("Gleb", "Hleb", 3 );
    Student second("Glen", "leb", 2 );
    Group Kucha;
    Kucha.add(first);
    Kucha.add(second);
    cout << Kucha.avscore();
    return 0;
}
