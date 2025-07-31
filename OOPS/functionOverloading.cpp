//compile time polymorphism

#include<bits/stdc++.h>
using namespace std;

class Print{
public:

    void show(int x){
        cout<<"INT Func: "<<x<<endl;
    }
    
    void show(string y){
        cout<<"String Func: "<<y<<endl;
    }
};

int main() 
{
   Print obj1;
   obj1.show(55);
   obj1.show("Shakib");
   
    return 0;
}

/*
What is Function Overloading?
- Function overloading means having **multiple functions with the same name but different parameter lists** (different types or number of parameters) in the **same scope**.
- It’s resolved at **compile-time**. 
*/