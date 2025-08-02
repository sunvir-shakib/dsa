#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void heapify(int i, vector<int>&vec, int n){
    int maxIDX = i; //parent idx
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && vec[left] > vec[maxIDX]){
        maxIDX = left;
    }

    if(right < n && vec[right] > vec[maxIDX]){
        maxIDX = right;
    }

    if(maxIDX != i) {
        swap(vec[i], vec[maxIDX]);
        heapify(maxIDX, vec, n);
    }  
}

void heapSort(vector<int> &vec){
    int n = vec.size();
    //st-1 (build maxHeap)
    for(int i = n/2-1; i>=0; i--){
        heapify(i, vec, n);
    }

    // st-2(taking elements to their correct pos)
    for(int i=n-1; i>=0; i--){
        swap(vec[0], vec[i]);
        heapify(0, vec, i);
    }
}

int main() 
{
    vector<int> vec = {1, 4, 2, 5, 3};
    
    heapSort(vec);

    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<< " ";
    }
   cout<<endl;
   
    return 0;
}
