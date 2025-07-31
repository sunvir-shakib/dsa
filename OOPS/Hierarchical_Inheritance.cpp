#include<bits/stdc++.h>
using namespace std;

class Animal {
    public:
        void eat() { 
            cout << "Eats\n"; 
        }
    };
    
    class Dog : public Animal {
    public:
        void bark() { 
            cout << "Barks\n"; 
        }
    };
    
    class Cat : public Animal {
    public:
        void meow() { 
            cout << "Meows\n"; 
        }
    };
    
int main() 
{
   Cat c1;
   c1.meow();
   
   c1.eat();
   
   Dog d1;
   d1.bark();
   d1.eat();
   

    return 0;
}
