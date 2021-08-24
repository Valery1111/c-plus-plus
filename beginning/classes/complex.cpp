#include <iostream>
#include <math.h>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;


class Complex
{
private:
    double re, im;


public:

    Complex (double r=0.0, double i=0.0)
    {
        re = r;
        im = i;
    }

    Complex (Complex &c)
    {
        re = c.re;
        im = c.im;
    }

    float modul()
    {
        return sqrt(re * re + im * im);
    }

    Complex operator + (Complex &c)
    {
        Complex temp;

        temp.re = re + c.re;
        temp.im = im + c.im;

        return temp;
    }

    Complex operator - (Complex &c)
    {
        Complex temp;

        temp.re = re - c.re;
        temp.im = im - c.im;

        return temp;
    }

    Complex operator * (Complex &c)
    {
        Complex temp;

        temp.re = re*c.re - im*c.im;
        temp.im = re*c.im + c.re*im;

        return temp;
    }

    Complex operator / (Complex &c)
    {
        Complex temp;

        double r = c.re * c.re + c.im * c.im;
        temp.re = (re * c.re + im * c.im) / r;
        temp.im = (im * c.re - re * c.im) / r;

        return temp;
    }

    friend ostream &operator<<(ostream &, const Complex &);
    friend istream &operator>>(istream &, const Complex &);

};

ostream &operator<<(ostream &out, const Complex &c)
{
    out << c.re;
    if( c.im != 0.0)
    {
        if( c.im > 0 )
            out << "+";
        out << c.im << "i";
    }
    return out;
}

istream &operator>>(istream &in, const Complex &c)
{
    in >> c.re >> c.im;

    return in;
}

int main()
{

    Complex value2(1,-1);

    fstream iofile("kom.txt", ios::in | ios::out);

	string first, second, sum;
	getline(iofile, first);
	getline(iofile, second);
	double re, im;
	stringstream myStr;
	myStr << first << endl;
	myStr << second << endl;
	myStr >> re >> im;
	Complex f(re, im);
	myStr >> re >> im;
	Complex s(re, im);
    myStr << f + s << endl;
    myStr >> sum;
    cout << sum << endl;
    ofstream fout;
    fout.open("kom.txt", ios_base::app);
    fout << endl;
    fout << "sum: " << sum;
    fout.close();
	return 0;
}

