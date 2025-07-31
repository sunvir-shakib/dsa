#include<bits/stdc++.h>
using namespace std;

void printArr(int *arr, int n){
    for(int i=0; i<n; i++)
    cout<<arr[i]<<" ";

    cout<<endl;
}

int partition(int *arr, int si, int ei){
    int i = si-1;
    int pivot = arr[ei];
    
    for(int j = si; j<ei; j++){
        if (arr[j]<=pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    i++;
    swap(arr[i], arr[ei]);
//pivot[idx]=i
    return i; //return pivot idx
}

void quickSort(int *arr, int si, int ei){
    if(si>=ei) //base case
    return;

    int pivotIDX = partition(arr, si, ei);

    quickSort(arr, si, pivotIDX-1); //left half
    quickSort(arr, pivotIDX+1, ei); //right half

}

int main() 
{
    int n = 6;
    int arr[6]={6, 3, 7, 5, 2, 4};
    quickSort(arr, 0, n-1);
    printArr(arr,n);
   
    return 0;
}
