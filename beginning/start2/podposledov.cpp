#include <stdio.h>
#include <iostream>
#define Y 9
#define X 7
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int L[Y][X];

int main()
{
    char a[Y+1];
    char b[X+1];
    int i, j, n, m;
    int yes = 0;
    cin >> a;
    cin >> b;
    n = Y;
    m = X;
    for( j = 0; j < m ; j++ )
    {
       if( b[j] == a[0] )
       {
           yes = 1;
       }

       L[0][j] = yes;
    }
    yes = 0;
    for(i = 0; i < n; i++)
    {
       if( a[i] == b[0] ) yes = 1;
       L[i][0] = yes;
    }

    for(i = 1; i < n; i++)
    {
       for(j = 1; j < m ; j++)
       {

          if( a[i] == b[j] )
             L[i][j] = L[i-1][j-1] + 1;
          else
             L[i][j] = max( L[i-1][j], L[i][j-1] );
       }
    }
/*
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf( "%d ",  L[i][j]);
        }
        printf("\n");
    }
*/
    vector<char> LCS ;
    int x_i = m-1;
    int y_i = n-1;
    while (x_i >= 0 && y_i >= 0)
    {
        if (b[x_i] == a[y_i])
        {
            LCS.push_back(b[x_i]);
            //cout << b[x_i];
            x_i = x_i-1;
            y_i = y_i-1;
        }

        else if (L[y_i][x_i-1] > L[y_i-1][x_i])
        {
            //cout << L[y_i][x_i-1] << endl;
            //cout << L[y_i-1][x_i] << endl;
            x_i -= 1;
        }
        else y_i -= 1;
    }
    reverse(LCS.begin(),LCS.end());
    for(int n : LCS) {
        cout << char(n);
    }

    return 0;
}
