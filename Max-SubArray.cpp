#include<bits/stdc++.h>

using namespace std;


int MaxCrossingSum(int arr[], int low, int mid, int high)
{
	int sum = 0;
	int leftpartsum = -1;
	for (int i = mid; i >= low; i--)
	{
		sum = sum + arr[i];
		if (sum > leftpartsum)
			leftpartsum = sum;
	}

	sum = 0;
	int rightpartsum = -1;
	for (int i = mid+1; i <= high; i++)
	{
		sum = sum + arr[i];
		if (sum > rightpartsum)
			rightpartsum = sum;
    }

	return leftpartsum + rightpartsum;
}

int MaxSubArraySum(int arr[], int low, int high)
{
	int mid;
	if (low == high)
		return arr[low];

	mid = (low + high)/2;

	return max(max(MaxSubArraySum(arr, low, mid), MaxSubArraySum(arr, mid+1, high)), MaxCrossingSum(arr, low, mid, high));
}

int main()
{
	int n;
	cout<<"Enter the number of elements in the array: ";
	cin>>n;

    int a[n+2];
    cout << "Enter the elements: ";
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
	}

	cout<< "\nMaximum sub-array sum is: " << MaxSubArraySum(a, 0, n-1);

	return 0;
}
