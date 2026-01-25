#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int n, int arr[]) {
    for(int i=0; i<n; i++) {
        for(int j=i-1; j>=0; j--) {
            if(arr[j+1] < arr[j]) swap(arr[j+1], arr[j]);
            else break;
        }
    }

    for(int i=0; i<n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    int arr[n];

    for(int i=0; i<n; i++) cin >> arr[i];

    insertion_sort(n, arr);
}