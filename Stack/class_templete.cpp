#include<iostream>
#include<vector>
using namespace std;

//create stack using vector

template<class T> //we can use any kind of data type in T

class Stack{
vector<T>vec;

public:
    void push(T val){ //O(1)
        vec.push_back(val);
    }

    void pop(){ //O(1)
        vec.pop_back();
    }

    T top(){ //O(1)
        int lastIDX = vec.size()-1;
        return vec[lastIDX];
    }
    bool isEmpty(){
        return vec.size()==0;
    }
};

int main() 
{
    Stack<char> s; //we have to tell the class data type
   s.push('N');
   s.push('U');
   s.push('S');
//    s.pop();

   while(!s.isEmpty()){
    cout<<s.top()<<" ";
    s.pop();
   }
   cout<<endl;
    return 0;
}
