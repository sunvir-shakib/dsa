#include<bits/stdc++.h>
using namespace std;

int getITHbit(int num, int i){
    int bitmask = 1<<i;
    if((bitmask & num) == 0)
    return 0;

    else
    return 1;
}

int setITHbit(int num, int i){
    int bit = 1<<i;
    int ans = num | bit;
    return ans;
}

int clearITHbit(int num, int i){
    int bit = ~(1<<i);
    return num & bit;
}

void clearLastIthBits(int num, int i){
    int bitmask = (~0)<<i;
    num = num & bitmask;
    cout<<"Last: "<<num<<endl;

}

void countBits(int num){
    int count = 0;
    while(num>0){
        int lastDig = num & 1;
        count += lastDig;
        num = num>>1;
    }

    cout<<"CountBits: "<<count<<endl;
    // return count;
}

int main() 
{
  cout<<getITHbit(6,2)<<endl; 
  cout<<getITHbit(7,5)<<endl; 

  cout<<"Set: "<<setITHbit(6,3)<<endl;
  cout<<"Clear "<<clearITHbit(6,1)<<endl;
  cout<<"Clear "<<clearITHbit(29, 3)<<endl;

   clearLastIthBits(15, 2);

   countBits(10);

   
    return 0;
}
