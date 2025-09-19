#include<iostream>
using namespace std;

//TC -- O(2^n)
//SC--- O(n)
void subSet(string str, string sub){
    if(str.size() == 0){
        cout << sub << endl;  
        return;
    }
    char ch = str[0];

    // Choice 1: include ch
    subSet(str.substr(1), sub + ch);
    // Choice 2: exclude ch
    subSet(str.substr(1), sub);
}

int main() 
{
    string str;
    cin >> str;

    string sub = "";

    subSet(str, sub);

    return 0;
}
