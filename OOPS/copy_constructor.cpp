#include<bits/stdc++.h>
using namespace std;

class Car{
public:
    string name;
    string colour;

    Car(string Name, string Colour){
        name = Name;
        colour = Colour;
    }

    Car(Car &original){ //custom copy constructor

        cout<<"Copy of original"<<endl;
        name = original.name;
        colour = original.colour;
    }

};

int main() 
{
    Car c1("Bugatti", "Blue");
    Car c2(c1);
   
    cout<<c2.name<<endl;
    cout<<c2.colour<<endl;
   
    return 0;
}
