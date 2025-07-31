#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void nextGreaterElement(vector<int>&ar, vector<int>&ans){
stack<int>s;
int idx = ar.size()-1;
ans[idx] = -1; //no other element on the right of this so -1
s.push(ar[idx]);

for(idx = idx-1; idx>=0; idx--){
    int curr = ar[idx];
    while(!s.empty() && curr >= s.top()){
        s.pop();
    }

    if(s.empty()){
        ans[idx] = -1;
    }
    else{
        ans[idx] = s.top();
    }
    s.push(curr); //push current element
}

//print
for(int i=0; i<ar.size(); i++){
    cout<<ans[i]<<" ";
}
cout<<endl;
}

int main() 
{
   vector<int> ar = {6, 8, 0, 1, 3};
   vector<int> ans(ar.size());
   nextGreaterElement(ar, ans);

    return 0;
}
