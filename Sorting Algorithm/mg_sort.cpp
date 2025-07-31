#include<iostream>
#include<vector>
using namespace std;

void printAl(vector<int>&ar){
    for(int i=0; i<ar.size(); i++){
        cout<<ar[i]<<" ";
    }
    cout<<endl;
}

void merge(vector<int>&ar, int si, int mid, int ei){
    vector<int>tmp;
    int i=si, j=mid+1;

    while(i<=mid && j<=ei){
        if(ar[i]<ar[j]){
            tmp.push_back(ar[i]);
            i++;
        }
        else{
            tmp.push_back(ar[j]);
            j++;
        }
    }

    //for remaing elements
    while(i<=mid){
        tmp.push_back(ar[i]);
        i++;
    }

    while(j<=ei){
        tmp.push_back(ar[j]);
        j++;
    }

    //copy to original array
    for(int k=si, x=0; k<=ei; k++){
        ar[k] = tmp[x];
        x++;
    }

}

void mergeSort(vector<int>&ar, int si, int ei){
    //base case
    if(si>=ei){
        return;
    }

    int mid = si + (ei-si)/2;
    mergeSort(ar, si, mid); //left 
    mergeSort(ar, mid+1, ei); //right

    merge(ar, si, mid, ei);
}

int main(){
    vector<int> ar = {6, 3, 1, 9 ,7};
    mergeSort(ar, 0, ar.size()-1);
    printAl(ar);


    return 0;
}