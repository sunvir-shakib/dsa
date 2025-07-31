#include<bits/stdc++.h>
using namespace std;

//compile time polymorphism

class Complex {
    int real;
    int img;

public:

    Complex ( int r, int i){
        real = r;
        img = i;
    }

    void showNum(){
        cout<<real << "+"<<img<<"i\n";
    }

    //operator overloading
    Complex operator + (Complex &c2){
        int resReal = real  + c2.real;
        int resImg = img + c2.img;
        Complex c3(resReal, resImg);
        return c3;
        // cout<<"Res: ";
        // c3.showNum();
    }


};

int main() 
{
    Complex c1(1,2);
    Complex c2(3,4);
    c1.showNum();
    c2.showNum();

    Complex c3 = c1+c2;
    c3.showNum();
   
    return 0;
}
