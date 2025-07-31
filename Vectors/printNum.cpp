#include<iostream>
#include<vector>
using namespace std;

int main() 
{
    vector<int> vec;

    for(int i = 1; i <= 9; i++) {
        vec.push_back(i);     // insert value
        cout << i << " ";     // print value
    }

    return 0;
}
