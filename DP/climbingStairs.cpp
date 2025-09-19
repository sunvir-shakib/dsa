#include<iostream>
#include<vector>
using namespace std;

int climbingStairs(int n, vector<int> &st){
    if( n==0 || n==1){
        return 1;
    }

    if(st[n] != 0){ //Memoization
        return st[n];
    }

    st[n] = climbingStairs(n-1, st) + climbingStairs(n-2, st);
    return st[n];

}

int main() 
{
    int n;
    cin>>n;

    vector<int> st(n+1, 0);

    cout<<climbingStairs(n, st);
   
   
    return 0;
}
