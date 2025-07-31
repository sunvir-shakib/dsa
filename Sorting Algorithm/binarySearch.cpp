#include<bits/stdc++.h>
using namespace std;

int binSearch(int arr[], int n, int key) 
{
    int st = 0, end = n - 1;
    while (st <= end) 
    {
        int mid = (st + end) / 2; // st + (ei-si)/2

        if (arr[mid] == key) 
        return mid;

        else if (key > arr[mid]) 
        st = mid + 1;

        else 
        end = mid - 1;
    }
    return -1;
}

int main() 
{
    int n, key;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i]; 
    }
    cin >> key; 

    cout << binSearch(arr, n, key) << endl;
    
    return 0;
}
