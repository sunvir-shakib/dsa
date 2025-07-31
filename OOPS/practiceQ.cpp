#include<bits/stdc++.h>
#include<string>
using namespace std;

class User{
private:
    int id;
    string pass;
public:
    string name;

    User(int id){
        this->id = id;
    }

void GetSetter(string newpass){
    pass = newpass;
}

string GetterPass(){
    return pass;
}

};

int main() 
{
   User u1(12323);
   u1.name = "Sunvir";
   u1.GetSetter( "37sjslfj437" );

   cout<<u1.name<<endl;
   cout<<u1.GetterPass()<<endl;
   
    return 0;
}
