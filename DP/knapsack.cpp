#include<iostream>
#include<vector>
using namespace std;

int kanpsack(vector<int> val, vector<int> wt, int w, int n){
    if( w == 0 || n == 0){
        return 0;
    }

    int itemWt = wt[n-1];
    int itemVal = val[n-1];
    //valid
    if( itemWt <= w ){ 
        //include
        int ans1 = kanpsack(val, wt, w-itemWt, n-1) + itemVal;

        //exclude
        int ans2 = kanpsack(val, wt, w, n-1);

        return max(ans1, ans2);
    }
    //invalid
    else{ //exclude
        return kanpsack(val, wt, w, n-1);

    }
}

int main() 
{
    vector<int> val = {15, 14, 10, 45, 30};
    vector<int> wt = {2, 5, 1, 3, 4};
    int w = 7;
    int n = 5;

    cout<<kanpsack(val, wt, w, n);
   
   
    return 0;
}
