#include <bits/stdc++.h>
using namespace std;

class Car {
public:
    string name;
    string colour;
    int *milage; // Pointer to dynamically allocated memory

    // Constructor: initializes car with name, colour and dynamically allocates milage
    Car(string Name, string Colour) {
        name = Name;
        colour = Colour;
        milage = new int;     // dynamic allocation
        *milage = 12;         // default milage
    }

    // Custom Copy Constructor (Deep Copy)
    Car(Car &original) {
        cout << "Copy of original\n";
        name = original.name;
        colour = original.colour;

        // Allocate new memory and copy value (deep copy)
        milage = new int;
        *milage = *original.milage;
    }
};

int main() {
    Car c1("Bugatti", "Blue"); // original object
    Car c2(c1);                // deep copy using custom constructor

    // Printing values before change
    cout << c2.name << endl;
    cout << c2.colour << endl;
    cout << "C1 " << *c1.milage << endl;
    cout << "C2 " << *c2.milage << endl;

    // Changing c2's milage should NOT affect c1 (deep copy proof)
    *c2.milage = 10;

    // Printing values after change
    cout << "C1 " << *c1.milage << endl; // should stay 12
    cout << "C2 " << *c2.milage << endl; // should become 10

    return 0;
}

/*
    🔹 Shallow Copy (Default Copy Constructor):
    - Copies the pointer's address (not the actual data).
    - Both objects share the same memory.
    - If one changes the value, the other also gets affected.
    - Risk of double deletion (memory issues).

    🔹 Deep Copy (Custom Copy Constructor):
    - Allocates new memory and copies the actual data.
    - Each object manages its own copy.
    - Safer for classes with dynamic memory (like using `new`).

    ✅ In this code:
    - We implemented a deep copy.
    - c1 and c2 have separate `milage` memory.
    - Changing one does not affect the other.
*/
