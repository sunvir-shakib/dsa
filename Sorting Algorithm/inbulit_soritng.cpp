#include<bits/stdc++.h>
using namespace std;
int main() 
{
  int a[5]={5, 2, 9 ,4, 7}; 
//   sort(a, a+5);
//   sort(a+1, a+5);

  sort(a, a+5, greater<int>());

 for(int i=0; i<5; i++){
    cout<<a[i]<<" ";
 }
   cout<<endl;
    return 0;
}
