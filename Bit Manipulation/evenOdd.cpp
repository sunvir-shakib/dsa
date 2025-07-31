#include<bits/stdc++.h>
using namespace std;

//for odd right most bit...1
//for even right most bit...0


void evenOdd(int num){
    if( (num & 1) == 0) // !(num & 1)
    cout<<"Even"<<endl;

    else
    cout<<"Odd"<<endl;
}

int main() 
{

   evenOdd(5);
   evenOdd(8);
   
    return 0;
}
