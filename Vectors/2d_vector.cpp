#include<iostream>
#include<vector>


using namespace std;
int main() 
{
    vector<vector<int>> matrix = {{1,2,3}, {4,5}, {6}};
    for(int i=0; i<matrix.size(); i++){ //for row
        for(int j=0; j<matrix[i].size(); j++){ //col
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
   
    return 0;
}
