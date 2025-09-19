#include<iostream>
using namespace std;

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
    DecToBin(37);
   
   
    return 0;
}
