#include<bits/stdc++.h>
using namespace std;

void printArr(int *arr, int n){
    for(int i=0; i<n; i++)
    cout<<arr[i]<<" ";
    cout<<endl;
}

void countingSort(int *ar, int n){
    int count[10000]={0};
    int minval = INT_MAX, maxval = INT_MIN;

    //creating counting array to store frequency
    for(int i=0; i<n; i++){
        count[ar[i]]++;
        minval = min(minval, ar[i]);
        maxval = max(maxval, ar[i]);
    }
    
    //2nd step
    int j=0;
    for(int i = minval; i<=maxval; i++){
        while(count[i]>0){
            ar[j] = i;
            j++;
            count[i]--;
        }
    }
    printArr(ar, n);
}

int main() 
{
   int n;
   cin>>n;
   int ar[n];

   for(int i=0; i<n; i++){
    cin>>ar[i];
   }

   countingSort(ar, n);
   
    return 0;
}
