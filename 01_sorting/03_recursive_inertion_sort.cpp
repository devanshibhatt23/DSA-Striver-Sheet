#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int n, vector<int> &arr) {
    if(n==arr.size()-1) return;

    for(int i=n; i>=0; i--) {
        if(arr[i]>arr[i+1]) swap(arr[i], arr[i+1]);
    }

    int x = n+1;
    insertion_sort(x, arr);
} 

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i=0; i<n; i++) cin >> arr[i];

    insertion_sort(0, arr);

    for(int i=0; i<n; i++) cout << arr[i] << " ";
}