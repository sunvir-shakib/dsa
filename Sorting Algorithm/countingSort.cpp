#include <iostream>
#include <climits>
using namespace std;

void print(int *ar, int n) {
    for(int i = 0; i < n; i++) {
        cout << ar[i] << " ";
    }
}

void countingSort(int *ar, int n) {
    int minval = INT_MAX;
    int maxval = INT_MIN;
    
    for(int i = 0; i < n; i++) {
        minval = min(minval, ar[i]);
        maxval = max(maxval, ar[i]);
    }
    
    int range = maxval - minval + 1;
    int *freq = new int[range](); 
    
    for(int i = 0; i < n; i++) {
        freq[ar[i] - minval]++;
    }
    
    int j = 0;
    for(int i = 0; i < range; i++) {
        while(freq[i] > 0) {
            ar[j++] = i + minval; 
            freq[i]--;
        }
    }
    
    delete[] freq; 
    print(ar, n);
}

int main() {
    int n;
    cin >> n;
    
    int* ar = new int[n]; 
    for(int i = 0; i < n; i++)
        cin >> ar[i];
    
    countingSort(ar, n);
    
    delete[] ar; 
    return 0;
}