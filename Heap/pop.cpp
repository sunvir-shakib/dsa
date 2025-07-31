/*
3 steps to pop (O(1))
- swap(root, last) (O(1))
- delete this lastIDX
- fix the heap (O(logn))
hepify

*/

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
 
    void heapify(int i){ // i = parIDX
        if(i >= vec.size()){
            return;
        }

        int left = 2*i + 1;
        int right = 2*i + 2;
        int maxIDX = i;

        if(left < vec.size() && vec[left] > vec[maxIDX]){
            maxIDX = left;
        }

        if(right < vec.size() && vec[right] > vec[maxIDX]){
            maxIDX = right;
        }

        swap(vec[i], vec[maxIDX]);
        if(maxIDX != i){
            heapify(maxIDX);
        }
    }

    void pop(){
        swap(vec[0], vec[vec.size()-1]);
        vec.pop_back();

        heapify(0); //O(logn)
    }


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

    while(!hp.empty()){
        cout<<"Top: "<<hp.top()<<endl;
        hp.pop();
    }

    return 0;
}
