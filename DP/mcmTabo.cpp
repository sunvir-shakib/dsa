#include<iostream>
#include<vector>
using namespace std;

int mcmTabo(vector<int> ar){
    int n = ar.size();

    vector<vector<int>> dp(n, vector<int>(n, 0));
    //initialization
    for(int i=1; i<n; i++){
        dp[i][i] = 0;
    }

    //bottom line
    for(int len = 2; len<n; len++){
        for(int i=1; i<=n-len; i++ ){
            int j = i+len-1;
            dp[i][j] = INT_MAX;

            for(int k=i; k<j; k++){
                int cost1 = dp[i][k];
                int cost2 = dp[k+1][j];
                int currCost = cost1 + cost2 + ar[i-1]*ar[k]*ar[j];
                dp[i][j] = min(dp[i][j], currCost);
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[1][n-1];
    
}

int main() 
{
    vector<int> ar = {1, 2, 3, 4, 3};
    
    cout<< mcmTabo(ar);
      
    return 0;
}
