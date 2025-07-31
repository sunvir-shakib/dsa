#include<bits/stdc++.h>
using namespace std;

class Shape{
public:

    virtual void draw() = 0; //abstract func, pure virtual func
};

class Circle : public Shape{
public:
    void draw(){
        cout<<"Draw Circle\n";
    }
};

class Square : public Shape{
public:
    void draw(){
        cout<<"Draw Square\n";
    }
};

int main() 
{
   Circle c1;
   c1.draw();

   Square s1;
   s1.draw();
   
    return 0;
}
