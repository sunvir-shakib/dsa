#include<bits/stdc++.h>
using namespace std;

int partition(int *ar, int si, int ei){
    int mid = (si+ei)/2; //pivot idx at mid
    int pivot = ar[mid];
    // swap(pivot, ar[ei]); wrong bcz pivot is a local variable which is not working at swap fun.
    swap(ar[mid], ar[ei]);
    int i = si-1;

    for(int j=si; j<ei; j++){
        if(ar[j]<=pivot){
            i++;
            swap(ar[i], ar[j]);
        }    
    }

    i++;
    swap(ar[i], ar[ei]);
    return i;
}

void quickSort(int *ar, int si, int ei){
    if(si>=ei)
    return;

    int pivotIDX = partition(ar, si, ei);
    quickSort(ar, si, pivotIDX-1); // lefthalf
    quickSort(ar, pivotIDX+1, ei); // right half
}

void printAL(int *ar, int n){
    for(int i=0; i<n; i++){
        cout<<ar[i]<<" ";
    }
    cout<<endl;
}

int main() 
{
   int n;
   cin>>n;
   int ar[n];
   for(int i=0; i<n; i++){
    cin>>ar[i];
   }

   quickSort(ar, 0, n-1);
   printAL(ar, n);
   
    return 0;
}
