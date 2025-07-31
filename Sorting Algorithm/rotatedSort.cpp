#include<bits/stdc++.h>
using namespace std;

int Search(int *ar, int si, int ei, int target){
    //base case
    if(si>ei)
    return -1;

    int mid = si + (ei-si)/2;
    if(ar[mid]==target)
    return mid;

    //line one
    if(ar[si] <= ar[mid]){

        if(ar[si]<=target && target <= ar[mid]){
            //left
            return Search(ar, si, mid-1, target);
        }
        else
        {
            //right half
            return Search(ar, mid+1, ei, target);
        }
    }

    //line two
    else
    {
        if(ar[mid] <= target && target <= ar[ei]){
           //right half
            return Search(ar, mid+1, ei, target);
        }
        else
        {
            //left
            return Search(ar, si, mid-1, target);
        }
    }
}

int main() 
{
    int n  = 7;
  int ar[7]={4, 5, 6, 7, 0, 1, 2}; 
  cout<<"IDX: "<<Search(ar, 0, n-1, 2); //4
   
    return 0;
}
