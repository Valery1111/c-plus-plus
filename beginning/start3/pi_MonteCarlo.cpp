#include <ctime>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

bool IsPointInCircle(double R, double x, double y)
{
    return ((x*x + y*y) < R*R);
}

int main()
{
    int Npoints = (int)1E5;
    int Nincircle = 0;
    srand(time(0));
    for(int i = 0; i < Npoints; i++)
    {
        if
        (
            IsPointInCircle
            (
                1.0,
                (rand()%(4*Npoints) - 2*Npoints)/(2.0*Npoints),
                (rand()%(4*Npoints) - 2*Npoints)/(2.0*Npoints)
            )
        )
            Nincircle++;
    }
    cout<<"Calc  Value of PI : "<<setprecision(5)<<Nincircle*4.0/Npoints<<endl;
    cout<<"Check Value of PI : "<<setprecision(7)<<asin(1.0)*2.0<<endl;
    return 0;
}
