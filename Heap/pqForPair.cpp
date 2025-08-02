#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

struct ComparePair{
    bool operator ()(pair <string, int> &p1, pair<string, int> &p2){
        return p1.second > p2.second;
    }
};

int main() 
{
    priority_queue < pair <string, int>, vector<pair<string, int>>, ComparePair> pq; //deafault - maxHeap; "FIRST"

    pq.push(make_pair("sunvir", 77));
    pq.push(make_pair("avi", 88));
    pq.push(make_pair("sany", 66));

        while(!pq.empty()) {
        cout << "Top: " << pq.top().first << ", " << pq.top().second << endl;
        pq.pop();
    }
   
   
    return 0;
}
