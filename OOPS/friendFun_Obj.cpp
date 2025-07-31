#include<bits/stdc++.h>
using namespace std;

class A{
    string sec = "secret data";
    friend  class B;
    friend void revealSec(A &obj);
};

class B{ //becomes a friend class of A
public: 
    void showSec(A &obj){
        cout<<obj.sec<<endl;

    }
};

void revealSec(A &obj){ //becomes a friend functions of class A 
     cout<<obj.sec<<endl;
}

int main() 
{
    A a1;
    B b1;

    // b1.showSec(a1);
   revealSec(a1);
   
    return 0;
}
