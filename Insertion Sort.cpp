#include<bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    cin >> n;

    int ar[n+2];

    for (int i = 0; i < n ; i++ )
        cin >> ar[i];

    for(int i = 1; i < n; i++)
    {
        int x = ar[i];
        int j = i-1;
        while(j >= 0 and ar[j] > x)
        {
            ar[j+1] = ar[j];
            j--;

            for(int k = 0; k < n; k++)
                cout << ar[k] << ' ';
            cout << "Done\n" << endl;

        }
        ar[j+1] = x;
    }

    for(int i = 0; i < n; i++)
        cout << ar[i] << ' ';
    cout << endl;
}
