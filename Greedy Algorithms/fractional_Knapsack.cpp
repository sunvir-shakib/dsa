#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    return  a.first/ (double)a.second > b.first/ (double)b.second; //descending, sort by ratio
}

double frKnapsack(vector<int> val, vector<int> wt, int W){
    vector<pair<int, int>> pr;
    
    for(int i=0; i<val.size(); i++){
        pr.push_back({val[i], wt[i]});
    }

    sort(pr.begin(), pr.end(), compare); //by ratio

    // sort(pr.begin(), pr.end(), [](const pair<int, int>& a, const pair<int, int>& b){
    //     return  a.first/ (double)a.second > b.first/ (double)b.second;
    // });

    double totVal = 0;

    for(auto &pair : pr){
        if(pair.second <= W){
            totVal += pair.first;
            W -= pair.second;
        }

        else{
            totVal += (pair.first*(double)W) / pair.second;
            break;
        }
    }

    cout<<"Max Val: "<<totVal<<endl;
    return totVal;
}

int main() 
{
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int W = 50;

    frKnapsack(val, wt, W);

    return 0;
}
