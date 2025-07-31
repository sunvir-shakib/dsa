#include<bits/stdc++.h>
using namespace std;

bool powOFtwo(int n){
    if( (n & (n-1)) == 0)
    return true;

    else
    return false;
}

int main() 
{
   cout<<powOFtwo(15)<<endl;
   cout<<powOFtwo(16)<<endl;
   
    return 0;
}
