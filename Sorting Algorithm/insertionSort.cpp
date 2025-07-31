#include<bits/stdc++.h>
using namespace std;

void print (vector<int>&ar)
{
    int n = ar.size();
    for(int i = 0; i < n; i++)
    {
        cout<<ar[i]<<" ";
    }
}

void insertionSort(vector<int>&ar){
    int n = ar.size();
   
    for(int i=1; i<n; i++){
        int key = ar[i];
        int j = i-1;

        while( j>=0 && ar[j]>key ){
            ar[j+1] = ar[j];
            j--;
        }
        ar[j+1] = key;
    }
    print(ar);
}

int main() 
{
  int n;
  cin>>n;
  
  vector<int> ar(n);
  for(int i=0; i<n; i++) //{7, 3, 5, 2}
  cin>>ar[i];

  insertionSort(ar);
   
    return 0;
}
