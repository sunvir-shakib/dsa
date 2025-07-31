#include<iostream>
using namespace std;
#include<vector>


int main() 
{
    vector<int>vec1(10, -1);
    cout<<vec1.size()<<endl;

    for(int i=0; i<vec1.size(); i++){
        cout<<vec1[i]<<" ";
    }

    cout<<endl;
   
    return 0;
}
