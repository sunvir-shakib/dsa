#include <iostream>
#include <stack>
using namespace std;

int main() 
{
    stack<char> s; // using STL stack

    s.push('N');
    s.push('U');
    s.push('S');

    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}
