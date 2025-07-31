#include<bits/stdc++.h>
using namespace std;

class Student{
public:

   string name;
   float cgpa;


 void getRes(){
   cout<<name<<endl;

 }

};

int main() 
{
   Student s1;
   s1.name = "Shakib";
   s1.cgpa = 3.4;

   cout<<s1.name<<endl;
   cout<<s1.cgpa<<endl;

   s1.getRes();

   return 0;
}
