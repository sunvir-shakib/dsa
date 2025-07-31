//Run time polymorphism

#include<bits/stdc++.h>
using namespace std;

class Parent{
public:
    void show(){
        cout<<"Parent class\n";
    }

    //virtual function...dynamic in nature
    virtual void hello(){
        cout<<"Parent hello\n";
    }
};

class Child : public Parent{
public:
    void show(){
        cout<<"Child class\n";
    }

    void hello(){
        cout<<"Child hello\n";
    }
};

int main() 
{
    Child c1;
    // c1.show();
    Parent *ptr;
    ptr = &c1; //run time binding
    ptr -> hello(); //virtual function
   
    return 0;
}
