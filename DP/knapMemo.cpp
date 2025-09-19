#include<iostream>
#include<vector>
using namespace std;

int kanpsackMemo(vector<int> val, vector<int> wt, int w, int n, vector<vector<int>> &dp){
    if( w == 0 || n == 0){
        return 0;
    }

    //memoization
    if(dp[n][w] != -1){
        return dp[n][w];
    }

    int itemWt = wt[n-1];
    int itemVal = val[n-1];

    //valid
    if( itemWt <= w ){ 
        //include
        int ans1 = kanpsackMemo(val, wt, w-itemWt, n-1,dp) + itemVal;

        //exclude
        int ans2 = kanpsackMemo(val, wt, w, n-1,dp);

        dp[n][w] = max(ans1, ans2);
    }

    //invalid
    else{ 
        dp[n][w] = kanpsackMemo(val, wt, w, n-1,dp);

    } 

    return dp[n][w];
}

int main() 
{
    vector<int> val = {15, 14, 10, 45, 30};
    vector<int> wt = {2, 5, 1, 3, 4};
    int w = 7;
    int n = 5;

    vector<vector<int>> dp(n+1, vector<int> (w+1, -1)); //2d vector
    cout<<kanpsackMemo(val, wt, w, n, dp);
   
   
    return 0;
}
