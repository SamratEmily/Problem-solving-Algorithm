#include<bits/stdc++.h>
using namespace std;
const int r=10,c=10;
char b[r][c];
void print_lcs(char b[r][c],string x,int i,int j)
{
    if(i==0 || j==0) return ;
    if(b[i][j]=='C')
    {
        print_lcs(b,x,i-1,j-1);
        cout<<x[i-1]<<" ";
    }
    else if(b[i][j]=='U')
    {
        print_lcs(b,x,i-1,j);
    }
    else
    {
        print_lcs(b,x,i,j-1);
    }
}

int main()
{
    string x, y;
    cin>>x>>y;
    int m,n,i,j;
    m=x.length();
    n=y.length();
    int c[m+1][n+1];

    for(i=0; i<=m; i++) c[i][0]=0;

    for(j=1; j<=n; j++) c[0][j]=0;

    for(i=1; i<=m; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(x[i-1]==y[j-1])
            {
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]='C';
            }
            else
            {
                if(c[i-1][j]>=c[i][j-1])
                {
                    c[i][j]=c[i-1][j];
                    b[i][j]='U';
                }
                else
                {
                    c[i][j]=c[i][j-1];
                    b[i][j]='L';
                }
            }
        }
    }
    print_lcs(b,x,m,n);



    return 0;
}

