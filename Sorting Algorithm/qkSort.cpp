#include<bits/stdc++.h>
using namespace std;

//pivot at first idx
int partition(vector<int>& ar, int si, int ei) {
    int pivot = ar[si];  
    int i = si;

    for (int j = si + 1; j <= ei; j++) {
        if (ar[j] < pivot) {  
            i++;
            swap(ar[i], ar[j]);
        }
    }

    swap(ar[i], ar[si]);  
    return i;
}


//pivot at mid type-1
int partition2(vector<int> &ar, int si, int ei){
    int pivot = ar[(si+ei)/2]; // pivot at mid
    int i = si;
    int j = ei;
    
    while(i <= j){
        while(ar[i] < pivot){
            i++;
        }
        while(ar[j] > pivot){
            j--;
        }
        
        // If we found elements to swap
        if(i <= j){
            swap(ar[i], ar[j]);
            i++;
            j--;
        }
    }
    return i; 
}

//pivot at mid idx type-2
int partition(vector<int> &ar, int si, int ei){
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

//pivot at end idx
int partition(vector<int> &arr, int si, int ei){
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
    return i; //return pivot
}

void quickSort(vector<int> &ar, int si, int ei){
    if(si>=ei)
    return;

    int pivotIDX = partition(ar, si, ei);
    quickSort(ar, si, pivotIDX-1); 
    quickSort(ar, pivotIDX+1, ei); 
}
    

int main() 
{
   int n;
   cin>>n;
   vector<int> ar(n);
   for(int i=0; i<n; i++){
    cin>>ar[i];
   }

   quickSort(ar, 0, n-1);
   
   for(int i=0; i<n; i++){
        cout<<ar[i]<<" ";
    }
    cout<<endl;

    return 0;
}
