#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// bool comp(int a, int b){
//     return a>b ; //true
// }

bool compare(pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second; // ascending - end
    // return p1.second > p2.second; //descending - end
    // return p1.first < p2.first;   // ascending - start
}

int main()
{
   vector<int> start = {0, 1, 2};
   vector<int> end = {9, 2, 4};

   //vector<int> vec(5, 0); ..vector initialize

   vector<pair<int, int>> act(3, make_pair(0,0));
   act[0] = make_pair(0,9);
   act[1] = make_pair(1,2);
   act[2] = make_pair(2,4);

    for(int i=0; i<act.size(); i++){
    cout<<"A"<<i<<" : "<<act[i].first <<","<<act[i].second<<endl;
   }

   sort(act.begin(), act.end(), compare);
 
   cout<<"Sorted\n";

   for(int i=0; i<act.size(); i++){
    cout<<"A"<<i<<" : "<<act[i].first <<","<<act[i].second<<endl;
   }
   
    return 0;
}
