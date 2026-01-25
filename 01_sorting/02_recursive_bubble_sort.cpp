#include <bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int> &arr, int n) {
    if(n==0) return;

    int ct = 0;
    for(int i=0; i<n-1; i++) {
        if(arr[i]>arr[i+1]) {
            swap(arr[i], arr[i+1]);
            ct = 1;
        }
    }

    if(ct==0) return;
    bubble_sort(arr, n-1);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i=0; i<n; i++) cin >> arr[i];

    bubble_sort(arr, n);

    for(int i=0; i<n; i++) cout << arr[i] << " "; 
}