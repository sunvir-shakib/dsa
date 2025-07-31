#include<iostream>
#include<stack>
using namespace std;

void pushBottom(stack<int>&s, int val){
    if(s.empty()){
        s.push(val); //at empty stack -> top = bottom
        return; 
    }

    int tmp = s.top();
    s.pop();
    pushBottom(s, val);
    s.push(tmp);
}

int main() 
{
    stack<int> s;
    s.push(3);
    s.push(2);
    s.push(1);

    pushBottom(s, 4);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();    
    }
    cout<<endl;
   
    return 0;
}
