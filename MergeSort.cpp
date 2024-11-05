#include<bits/stdc++.h>

using namespace std;

void MERGE(int ar[], int left, int mid, int right)
{
    int n1 = mid-left+1;
    int n2 = right-mid;

    auto *L = new int[n1+2], *R = new int[n2+2];

    for(int i = 1; i <= n1; i++) L[i] = ar[left+i-1];
    for(int i = 1; i <= n2; i++) R[i] = ar[mid+i];

    L[n1+1] = 123456789;
    R[n2+1] = 123456789;

    int i = 1, j = 1;

    for(int k = left; k <= right; k++)
    {
        if(L[i] <= R[j])
        {
            ar[k] = L[i];
            i++;
        }
        else
        {
            ar[k] = R[j];
            j++;
        }
    }
    return;
}

void Merge_Sort(int ar[], int left, int right)
{

    int mid;
    if(left < right)
    {
        mid = left+(right-left)/2;
        Merge_Sort(ar, left, mid);
        Merge_Sort(ar, mid+1, right);

        MERGE(ar, left, mid, right);
    }

    return;
}

int main()
{
    int t = 10;
    while(t--){
    int n;
    cin >> n;

    int ar[n+2];
    for(int i = 1; i <= n; i++) cin >> ar[i];

    Merge_Sort(ar, 1, n);

    cout << "After sorting the arrray is : " << endl;
    for(int i = 1; i <= n; i++)
        cout << ar[i] << ' ';
    cout << endl;
    }

    return 0;
}



