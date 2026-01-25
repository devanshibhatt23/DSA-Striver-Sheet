#include <bits/stdc++.h>
using namespace std;

int f(vector<int> &arr, int low, int high) {
    int x=low;
    int i = low, j = high;

    while(i<j) {
        while(arr[i] <= arr[x] && i<high) i++;
        while(arr[j] > arr[x] && j>low) j--;
        if(i<j) swap(arr[i], arr[j]);
    }

    swap(arr[x], arr[j]);
    return j;
}

void quicksort(vector<int> &arr, int low, int high) {
    if(low<high) {
        int p = f(arr,low,high);
        quicksort(arr,low,p-1);
        quicksort(arr,p+1,high);
    }
} 

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i=0; i<n; i++) cin >> arr[i];

    quicksort(arr, 0, n-1);

    for(int i=0; i<n; i++) cout << arr[i] << " ";
}