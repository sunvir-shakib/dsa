#include<iostream>
#include<stack>
using namespace std;

void pushAtBottom(stack<int>&s, int val){
    if(s.empty()){
        s.push(val); //push at top = push at bottom
        return; 
    }

    int tmp = s.top();
    s.pop();
    pushAtBottom(s, val);
    s.push(tmp);
}

void revStack(stack<int> &s){
    if(s.empty())
    return;

    int tmp = s.top();
    s.pop();
    revStack(s);
    pushAtBottom(s, tmp);
}

void printStack(stack<int>s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

int main() 
{
    stack<int> s;
    s.push(3);
    s.push(2);
    s.push(1);

    printStack(s);
    revStack(s);
    printStack(s);

    return 0;
}
