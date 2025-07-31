#include<bits/stdc++.h>
using namespace std;

void fun(){
    int *ptr = new int;
    *ptr = 5;
    cout<<*ptr;

    delete ptr;
}

int* fun2(){ //*int to return address
    int *ptr = new int;
    *ptr = 1200;
    //cout<<*ptr;
    return ptr;
}

int main() 
{
   int size;
   cin>>size;

   int *arr = new int [size];

//    int x = 1;

//    for(int i=0; i<size; i++){
//     arr[i] = x;
//     cout<<arr[i]<<" ";
//     x++;
//    }

   //delete [] arr;

   int *x = fun2();
   cout<<*x;

    return 0;
}
