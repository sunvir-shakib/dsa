// WAF to update the ith bit in a number according to given value (0 / 1)
//-- n=7, i=2, val=0;
//-- n=7, i=3, val=1;

/* 1. clar the ith bit
2. num | (val<<i)
*/

#include<bits/stdc++.h>
using namespace std;

void updateITHbit(int num, int i, int val){
    num = num & ~(1<<i); //clear ith bit
    num = num | (val<<i);
    cout<<num<<endl;
}

int main() 
{
   updateITHbit(7,2,0);
   
    return 0;
}
