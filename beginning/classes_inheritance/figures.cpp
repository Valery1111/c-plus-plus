#include <iostream>
#include <sstream>
#include <cmath>
#include <utility>
using namespace std;

class Figure
{
public:
    virtual double area() = 0;
    virtual double perimeter() = 0;
    virtual ostream & print(ostream &out) {return out;} ;
    friend ostream & operator << (ostream &out, Figure &f)
    {
        f.print(out);
        return out;
    }
};

class Ellipse : public Figure
{
private:
    double a, b;
public:
    Ellipse(double first = 0, double second = 0) : a(first), b(second)
    {
    }
    virtual double area() override
    {
        return a * b * M_PI;
    }
    virtual double perimeter() override
    {
        return (4 * a * b * M_PI + (a-b)) / (a + b);
    }
    virtual ostream& print(ostream& out)
    {
        out << "Ellipse, ";
        out << "a = " << a << ", ";
        out << "b = " << b << ", ";
        out << "perimeter " << perimeter() << ", ";
        out << "area " << area() << endl;
    }
    friend ostream& operator<<(ostream &out, Ellipse &e)
    {
        e.print(out);
        return out;
    }
};


class Polygon : public Figure
{
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
    virtual double area() override
    {
        double s;
        for (int i = 0; i<(n-1); i++)
        {
            s += points[i].first * points[i+1].second - points[i+1].first * points[i].second;
        }
        s += points[n-1].first * points[0].second - points[0].first * points[n-1].second;
        return abs(s/2);
    }
    virtual double perimeter() override
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
    virtual ostream& print(ostream& out)
    {
        out << "Polygon ";
        out << "n = " << n << ", ";
        out << "perimeter " << perimeter() << ", ";
        out << "area " << area() << endl;
    }
    friend ostream& operator<<(ostream &out, Polygon &p)
    {
        p.print(out);
        return out;
    }
};


class Circle : public Ellipse
{
private:
    double r;
public:
    Circle(double radius = 0) : Ellipse(radius, radius)
    {
        r = radius;
    }
    virtual double area()
    {
        Ellipse::area();
    }
    virtual double perimeter()
    {
        Ellipse::perimeter();
    }
    virtual ostream& print(ostream& out)
    {
        out << "Circle, ";
        out << "R = " << r << ", ";
        out << "perimeter " << perimeter() << ", ";
        out << "area " << area() << endl;
    }
    friend ostream& operator<<(ostream &out, Circle &c)
    {
        c.print(out);
        return out;
    }
};

class Triangle : public Polygon
{
public:
    Triangle(double numVertices, string pointStr) : Polygon(numVertices, pointStr)
    {
    }
    virtual double area()
    {
        Polygon::area();
    }
    virtual double perimeter()
    {
        Polygon::perimeter();
    }
    virtual ostream& print(ostream& out)
    {
        out << "Triangle ";
        out << "perimeter " << perimeter() << ", ";
        out << "area " << area() << endl;
    }
    friend ostream& operator<<(ostream &out, Triangle &p)
    {
        p.print(out);
        return out;
    }
};

int main()
{
    Ellipse e(2, 3);
    Circle c(4);
    Triangle t(3, "0.0 0.0 0.0 1.0 1.0 0.0");
    Figure *figures[] = {&e, &c, &t};
    for (int i = 0; i < 3; i++)
    {
        cout << *figures[i];
    }
    return 0;
}
