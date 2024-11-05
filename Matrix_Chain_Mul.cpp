#include<bits/stdc++.h>
using namespace std;
int MatrixChainOrder(int d[], int n)
{

    int c[n+1][n+1];

    int i, j, k, L, q;

    for (i = 1; i <= n; i++)
        c[i][i] = 0;

    for (L = 1; L < n; L++)
    {

        for (i = 1; i <= n - L ; i++)
        {
            j = i + L ;
            c[i][j] = INT_MAX;
            for (k = i; k < j ; k++)
            {
                q = c[i][k] + c[k + 1][j] + d[i - 1] * d[k] * d[j];
                if (q < c[i][j])
                    c[i][j] = q;
            }

        }
    }

    return c[1][n];
}
int main()
{
    int n,i;
    cout<<"Enter number of matrices:\n";
    cin>>n;
    int d[n+1];

    cout<<"Enter dimensions: \n";

    for(i=0; i<=n; i++)
    {
        cout<<"d"<<i<<" :: ";
        cin>>d[i];
    }
    cout<<"Minimum number of multiplications is "<<MatrixChainOrder(d, n);

    return 0;
}
