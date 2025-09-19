#include<iostream>
using namespace std;

void printArr(int *ar, int n){
    for(int i=0; i<n; i++){
        cout<<ar[i]<<" ";
    }
    cout<<endl;
}

void changeArr(int *ar, int n, int i){
    if(i==n){
    printArr(ar,n);
        return;
    }
    ar[i] = i+1;
    changeArr(ar, n, i+1);
    ar[i] -= 2;  //backtrack
}

int main() 
{
    int ar[5]={0};
    int n = 5;
    changeArr(ar, n, 0);
    printArr(ar,n);
   
    return 0;
}
