#include<iostream>
using namespace std;

void print(int *ar, int n){
    for(int i=0; i<n; i++){
        cout<<ar[i]<<" ";
    }
    cout<<endl;
}

int partition(int *ar, int si, int ei){
    int i = si-1;
    int pivot = ar[ei];
    for(int j=si; j < ei; j++){
        if(pivot >= ar[j] ){
            i++;
            swap(ar[i],ar[j]);
        }
    }
    i++;
    swap(ar[i],ar[ei]);
    return i;
}

void quickSort(int *ar, int si, int ei){
    //base case
    if(si >= ei){
        return;
    }

    int pivotIdx = partition(ar, si, ei);

    quickSort(ar, si, pivotIdx-1);
    quickSort(ar, pivotIdx+1, ei);
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
    print(ar, n);

    return 0;
}
