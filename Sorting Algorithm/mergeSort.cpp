#include<bits/stdc++.h>
#include<vector>
using namespace std;

//tc....O(nlogn)
//sc....O(n)

void merge(int *arr, int si, int mid, int ei){ //O(n)
    vector<int>temp;
    int i = si;
    int j = mid+1;

    while(i<=mid && j<=ei){
        if(arr[i]<=arr[j])
        temp.push_back(arr[i++]);
        
        else
        temp.push_back(arr[j++]);
    }

    while (i<=mid)
    {
        temp.push_back(arr[i++]);
    }

    while(j<=ei){
        temp.push_back(arr[j++]);
    }

    //vector to org arr
    int x = 0;
for(int idx = si; idx <= ei; idx++) { 
    arr[idx] = temp[x++];
}

}

void mergeSort(int *arr, int si, int ei ){ //O(nlogn)
    //base case
    if(si>=ei)
    return;

    int mid = (si+ei)/2; // si + (ei-si)/2

    //left half
    mergeSort(arr, si,mid);

    //right half
    mergeSort(arr, mid+1, ei);

    //to combined //conquer
    merge(arr, si, mid, ei);
}

void printArr(int *arr, int n){
    for(int i=0; i<n; i++)
    cout<<arr[i]<<" ";

    cout<<endl;
}

int main() 
{ 
    int n = 6;
    int arr[6]={6, 3, 7, 5, 2, 4};
    
    mergeSort(arr, 0, n-1);
    printArr(arr, n);
   
   
    return 0;
}
