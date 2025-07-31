#include <bits/stdc++.h>
using namespace std;

class Car {
public:
    string name;
    string colour;
    int* milage; // pointer to dynamically allocated memory

    // Constructor with parameters
    Car(string name, string colour) {
        this->name = name;
        this->colour = colour;
        milage = new int;      // dynamic memory allocation
        *milage = 12;          // default mileage
    }

    // Custom Copy Constructor (deep copy)
    Car(const Car& original) {
        cout << "Copy of original object\n";
        name = original.name;
        colour = original.colour;

        // Allocate separate memory and copy the value
        milage = new int;
        *milage = *original.milage;
    }

    // Destructor: deallocates memory
    ~Car() {
        cout << "Deleting object: " << name << "\n";
        if (milage != nullptr) {
            delete milage;
            milage = nullptr;
        }
    }
};

int main() {
    Car c1("Bugatti", "Blue"); // original object
    Car c2(c1);                // deep copy

    // Print details of copied object
    cout << "\nCopied Car Details:\n";
    cout << "Name: " << c2.name << endl;
    cout << "Colour: " << c2.colour << endl;
    cout << "C1 Mileage: " << *c1.milage << endl;

    return 0;
}
