#include<iostream>
#include<queue>
using namespace std;


int main(){
    //priority_queue<int> pq;  //max heap(descending-deafault)
    priority_queue<int, vector<int>, greater<int>> pq; //min heap(ascending)

    pq.push(4);
    pq.push(9);
    pq.push(1);
    pq.push(7);

    while( !pq.empty() ){
        cout<<"Top: "<< pq.top()<<endl; 


        pq.pop();
    }

    return 0;
}