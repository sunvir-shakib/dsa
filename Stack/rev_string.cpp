#include<iostream>
#include<stack>
#include<string>
using namespace std;

string revString(string str){
    string ans;
    stack<char>s;
    for(int i=0; i<str.size(); i++){ //push the string in the stack
        s.push(str[i]);
    }

    while(!s.empty()){
    char top = s.top();  // Get top character
    ans += top;          // Add it to result string
    s.pop();             // Remove it from stack
    }           

    return ans;
}

int main() 
{
   string str = "abcd";
   cout<<"Reverse= "<<revString(str)<<endl;
    return 0;
}
