//time complexity---O(n^2) // space---O(1)

#include<bits/stdc++.h>
using namespace std;

void print (vector<int>&ar)
{
    for(int i = 0; i <= ar.size(); i++)
    {
        cout<<ar[i]<<" ";
    }
    cout<<endl;
}

void bubbleSort(vector<int>&ar)
{
    for(int i=0; i<ar.size()-1; i++)
    {
        for(int j=0; j<ar.size()-i-1; j++)
        {
            if(ar[j] > ar[j+1])
            swap(ar[j], ar[j+1]);
        }
    }
    print(ar);
}

int main() 
{
 int n;
 cout<<"Enter size: ";
 cin>>n;
 
 vector<int> ar(n);
 cout<<"Enter array elements: ";
 for(int i=0; i<n; i++){
    cin>>ar[i];
 }

  bubbleSort(ar);

    return 0;
}
