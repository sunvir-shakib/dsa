//time complexity---O(n^2) // space---O(1)

#include<bits/stdc++.h>
using namespace std;

void print (vector<int>&ar){
    int n = ar.size();
    for(int i = 0; i < n; i++){
        cout<<ar[i]<<" ";
    }
}

void selectionSort(vector<int>&ar){
    int n = ar.size();

    for(int i=0; i<n-1; i++){
        int minIDX = i;

        for(int j=i+1; j<n; j++){
            if(ar[j] < ar[minIDX])
            minIDX = j;
        }
        swap(ar[i], ar[minIDX]);
    }
    print(ar);
}

int main() 
{
  int n;
  cin>>n;
  
  vector<int>ar(n);
  for(int i=0; i<n; i++)
  cin>>ar[i];
  
  selectionSort(ar);

    return 0;
}
