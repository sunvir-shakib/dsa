#include<bits/stdc++.h>
using namespace std;

int linSear(int *arr, int n, int key)
{
    for(int i=0; i<n; i++)
    {
        if(arr[i]==key)
        return i;
    }
    return -1;
}

int main() 
{
    int arr[] = {9, 2, 7, 6, 4 };
    int n = sizeof(arr) / sizeof(int);
   
    cout<<linSear(arr, n, 66)<<endl;
   
    return 0;
}
