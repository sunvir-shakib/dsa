#include<bits/stdc++.h>
using namespace std;

class Animal {
    public:
        void eat() { 
            cout << "Eats\n"; }
    };
    
    class Mammal : public Animal {
    public:
        void walk() { 
            cout << "Walks\n"; }
    };
    
    class Dog : public Mammal {
    public:
        void bark() { 
            cout << "Barks\n"; }
    };

int main() 
{
   Dog d1;

    d1.bark();
    d1.walk();
    d1.eat();


    return 0;
}

    