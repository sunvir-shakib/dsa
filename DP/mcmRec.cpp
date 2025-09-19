#include<iostream>
#include<vector>
using namespace std;

int mcmRec(vector<int> ar, int i, int j){
    if(i==j){
        return 0;
    }

    int ans = INT_MAX;
    for(int k=i; k<j; k++){
        //(i,k)
        int cost1 = mcmRec(ar, i, k);

        //(k+1, j)
        int cost2 = mcmRec(ar, k+1, j);

        //curr partition cost
        int currCost = cost1 + cost2 + ar[i-1] * ar[k] * ar[j];
        ans = min(ans, currCost);
    }
    return ans;
    
}

int main() 
{
    vector<int> ar = {1, 2, 3, 4, 3};
    int n = ar.size();

    cout<< mcmRec(ar, 1, n-1);
      
    return 0;
}
