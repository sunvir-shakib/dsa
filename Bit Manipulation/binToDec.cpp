#include<iostream>
using namespace std;

void dec(int bin){
    int n = bin;
    int decNum = 0;
    int pow = 1; //2^0, 2^1---

    while(n>0){
        int lastdig = n%10;
        decNum = decNum + (lastdig*pow);
        pow = pow*2;
        n = n/10;        
    }
    cout<<decNum<<endl;
}

void DecToBin(int dec){
    int n = dec;
    int  pow = 1; //10^1, 10^2--
    int ans = 0;
    while(n>0){
        int rem = n%2;
        ans = ans + (rem*pow);
        pow = pow * 10;
        n = n/2;
        }
        cout << ans <<endl;
    }

int main() 
{
    dec(100101);
    DecToBin(37);
   
   
    return 0;
}
