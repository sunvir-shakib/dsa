#include <bits/stdc++.h>
using namespace std;

//Base Class
class Animal {
public:
    string colour;

    void eats() {
        cout << "Animal eats.\n";
    }

    void breathes() {
        cout << "Animal breathes.\n";
    }

protected:
    void protectedFunc() {
        cout << "Protected function from Animal.\n";
    }

private:
    void privateFunc() {
        cout << "Private function from Animal.\n";
    }
};

//Public Inheritance
class Fish : public Animal {
public:
    int fins;

    void swim() {
        cout << "Fish swims.\n";
    }

    void accessProtected() {
        protectedFunc(); // ✅ allowed (protected is accessible in derived class)
        // privateFunc(); ❌ not allowed (private is never inherited)
    }
};

//Protected Inheritance
class Bird : protected Animal {
public:
    void fly() {
        cout << "Bird flies.\n";
    }

    void showAccess() {
        eats();         // ✅ still accessible inside the derived class
        breathes();     // ✅
        protectedFunc(); // ✅
        // privateFunc(); ❌ not accessible
    }
};

//Private Inheritance
class Dog : private Animal {
public:
    void bark() {
        cout << "Dog barks.\n";
    }

    void showAccess() {
        eats();         // ✅ accessible inside the class
        breathes();     // ✅
        protectedFunc(); // ✅
        // privateFunc(); ❌ not accessible
    }
};

int main() {
    Fish f1;
    f1.fins = 2;
    f1.colour = "Blue";    // ✅ public inheritance allows access to public members
    cout << "Fish fins: " << f1.fins << "\n";
    cout << "Fish colour: " << f1.colour << "\n";
    f1.swim();
    f1.eats();             // ✅ inherited publicly
    f1.breathes();         // ✅ inherited publicly

    f1.accessProtected();  // accessing protected method via public wrapper

    Bird b1;
    // b1.colour = "Red";  ❌ not allowed outside because Bird inherited Animal as protected
    b1.fly();
    // b1.eats();          ❌ not allowed outside class because it's protected now

    Dog d1;
    // d1.eats();          ❌ not allowed outside class because Dog inherited Animal privately
    d1.bark();

    return 0;
}
