#include <bits/stdc++.h>

using namespace std;

int ar[1002];

int Partition ( int low, int high);
void Quick_Sort(int low, int high);

int main()
{
    int t = 10;
    while(t--)
    {
        int n;
        cin >> n;

        for(int i = 1; i <= n; i++) cin >> ar[i];

        Quick_Sort(1, n);

        cout << "After sorting the arrray is : " << endl;
        for(int i = 1; i <= n; i++)
            cout << ar[i] << ' ';
        cout << endl;
    }
}

int Partition (int low, int high)
{
    int pivot = ar[low];

    int i = low, j = high;
    while(i < j)
    {
        do
        {
            i++;
        }
        while(ar[i] <= pivot);
        do
        {
            j--;
        }
        while(ar[j] > pivot);

        if(i < j)
            swap(ar[i], ar[j]);
    }

    swap(ar[low], ar[j]);
    return j;
}

void Quick_Sort(int low, int high)
{
    if (low < high)
    {

        int pi = Partition(low, high);

        Quick_Sort( low, pi);
        Quick_Sort( pi + 1, high);
    }
}




