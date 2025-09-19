#include<iostream>
#include<vector>
using namespace std;

// int memoization(int n, vector<int> &fib){
//     if(n == 0 || n == 1){
//         fib[n] = n;
//         return n;
//     }

//     if(fib[n] != -1){
//         return fib[n];
//     }

//     fib[n] = memoization(n-1, fib) + memoization(n-2, fib);
//     return fib[n];
// }

int tabulation(int n, vector<int> &tab){
    
    tab[0] = 0;
    tab[1] = 1;

    for(int i=2; i<=n; i++){
        tab[i] = tab[i-1] + tab[i-2];
    }
    return tab[n];
}

int main() 
{
    int n;
    cin>>n;
    // vector<int> fib(n+1, -1);
    // cout<< memoization(n, fib)<<endl;

    vector<int> tab(n+1, 0);
    cout<<tabulation(n, tab)<<endl;

    for(int a : tab){
        cout<<a<<" ";
    }
   cout<<endl;
   
    return 0;
}
