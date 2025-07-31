#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void stockSpan(vector<int>&stock, vector<int>&span){
    stack<int>s;
    s.push(0);
    span[0] = 1;
    
    for(int i = 1; i < stock.size(); i++){  // Start from 1, not 0
        int currPrice = stock[i];
        while(!s.empty() && currPrice >= stock[s.top()]){
            s.pop();
        }
        
        if(s.empty()){
            span[i] = i + 1;
        }
        else{
            int prevHigh = s.top();
            span[i] = i - prevHigh;
        }
        
        s.push(i);  // Push current index to stack
    }
    
    // Print results (separate loop with different variable)
    for(int j = 0; j < stock.size(); j++){
        cout << span[j] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> stock = {100, 80, 60, 70, 60, 85, 100};
    vector<int> span(7);  // Initialize with correct size
    
    stockSpan(stock, span);
    return 0;
}