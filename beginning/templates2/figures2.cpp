#include <iostream>
#include <sstream>
#include <cmath>
#include <utility>
using namespace std;

template<typename Der>
class Figure
{
public:
    double areaD() { self()->area(); }
    double perimeterD() { self()->perimeter(); }
    void printD()
    {
        self()->print();
    }

private:
    Der* self()
    {
        return static_cast<Der*>(this);
    }
};

class Ellipse : public Figure<Ellipse>
{
friend class Figure<Ellipse>;

private:
    double a, b;
public:
    Ellipse(double first = 0, double second = 0) : a(first), b(second)
    {
    }
    double area()
    {
        return a * b * M_PI;
    }
    double perimeter()
    {
        return (4 * a * b * M_PI + (a-b)) / (a + b);
    }
    void print()
    {
        cout << "Ellipse, ";
        cout << "a = " << a << ", ";
        cout << "b = " << b << ", ";
        cout << "perimeter " << perimeter() << ", ";
        cout << "area " << area() << endl;
    }
};


class Polygon : public Figure<Polygon>
{
friend class Figure<Polygon>;

protected:
    int n;
    pair<double, double> *points;
public:
    Polygon(double numVertices, string pointStr)
    {
        n = numVertices;
        points = new pair<double, double>[n];
        stringstream ss;
        ss << pointStr;
        for (int i = 0; i<n; i++)
        {
            ss >> points[i].first;
            ss >> points[i].second;
        }
    }
    double area()
    {
        double s;
        for (int i = 0; i<(n-1); i++)
        {
            s += points[i].first * points[i+1].second - points[i+1].first * points[i].second;
        }
        s += points[n-1].first * points[0].second - points[0].first * points[n-1].second;
        return abs(s/2);
    }
    double perimeter()
    {
        double p;
        for (int i = 0; i<(n-1); i++)
        {
            p += sqrt((points[i].first - points[i+1].first) * (points[i].first - points[i+1].first) \
                + (points[i].second - points[i+1].second) * (points[i].second - points[i+1].second));
        }
        p += sqrt((points[n-1].first - points[0].first) * (points[n-1].first - points[0].first) \
                + (points[n-1].second - points[0].second) * (points[n-1].second - points[0].second));
        return p;
    }
    void print()
    {
        cout << "Polygon ";
        cout << "n = " << n << ", ";
        cout << "perimeter " << perimeter() << ", ";
        cout << "area " << area() << endl;
    }

};


int main()
{
    return 0;
}
