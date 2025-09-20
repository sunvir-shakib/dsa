#include<iostream>
#include<vector>
using namespace std;

int mcmMemo(vector<int> ar, int i, int j, vector<vector<int>> &dp){
    if(i==j){
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int ans = INT_MAX;
    for(int k=i; k<j; k++){
        //(i,k)
        int cost1 = mcmMemo(ar, i, k, dp);

        //(k+1, j)
        int cost2 = mcmMemo(ar, k+1, j, dp);

        //curr partition cost
        int currCost = cost1 + cost2 + ar[i-1] * ar[k] * ar[j];
        ans = min(ans, currCost);
    }
    return dp[i][j] = ans;
    
}

int main() 
{
    vector<int> ar = {1, 2, 3, 4, 3};
    int n = ar.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    cout<< mcmMemo(ar, 1, n-1, dp);
      
    return 0;
}
