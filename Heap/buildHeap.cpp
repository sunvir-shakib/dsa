#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Heap{
    vector<int> vec; //CBT/ max heap
public:

    void push(int val){
        //st1
        vec.push_back(val);

        //fix heap
        int x = vec.size() - 1; //child
        int parIDX = (x-1)/2;

        while(parIDX >= 0 && vec[x] > vec[parIDX]){ //O(log n)
            swap(vec[x], vec[parIDX]);
            x = parIDX;
            parIDX = (x-1)/2;
        }

    }

    // void pop(){
        
    // }

    int top(){
        return vec[0]; //highest priority element
    }

    bool empty(){
        return vec.size() == 0;
    }

};

int main() 
{
    Heap hp;
    hp.push(50);
    hp.push(10);
    hp.push(100);

    cout<<"Top: "<<hp.top()<<endl;
   
   
    return 0;
}
