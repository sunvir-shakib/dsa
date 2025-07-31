#include <bits/stdc++.h>
using namespace std;

//class 
class Car {
    // Private attributes
    string name;
    string colour;

public:
    // Default constructor
    Car() {
        cout << "Constructor without parameters called.\n";
    }

    // Parameterized constructor
    Car(string name, string colour) {
        cout << "Constructor with parameters called.\n";
        this->name = name;
        this->colour = colour;
    }

// Setter for car name
    void SetName(string newName) {
        name = newName;
    }

    void SetColour(string newColour) {
        colour = newColour;
    }

// Getter for car name
     string GetName() {
        return name;
    }

    string GetColour() {
        return colour;
    }
};

int main() {
    Car c1;
    Car c2("Bugatti", "Blue");

    cout << "\nBefore update:\n";
    cout << "Name: " << c2.GetName() << "\n";
    cout << "Colour: " << c2.GetColour() << "\n";

    // Updating using setters
    c2.SetName("Lamborghini");
    c2.SetColour("Yellow");

    cout << "\nAfter update:\n";
    cout << "Name: " << c2.GetName() << "\n";
    cout << "Colour: " << c2.GetColour() << "\n";

    return 0;
}
