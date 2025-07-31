#include<iostream>
#include<vector>
using namespace std;

int maxActivities(vector<int> &start, vector<int> &end){
    //sort on end time based
    //A0 select
    cout<<"Selecting Activity A0\n";
    int count = 1;
    int curEnd = end[0];

    for(int i=1; i<start.size(); i++){
        if(start[i] >= curEnd){ //non - overlaping
            cout<<"Selecting Activity A"<<i<<endl;
            count++;
            curEnd = end[i]; 
        }
    }
    return count;
}

int main() 
{
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9}; //ans -> 4
   cout<<maxActivities(start, end)<<endl;
   
    return 0;
}
