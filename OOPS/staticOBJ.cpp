#include<bits/stdc++.h>
using namespace std;

 class Example{
public:

    Example(){
        cout<<"Constructor\n";
    }

    ~Example(){
        cout<<"Desturctor\n";
    }

 };

int main() 
{
    int a = 0;
    if(a==0){
        static Example e1;
    }

    cout<<"Code ending\n";
   
   
    return 0;
}
