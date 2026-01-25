#include <bits/stdc++.h>
using namespace std;

void selection_sort(int n, int arr[]) {
    for(int i=0; i<n-1; i++) {
        int x = arr[i];
        int k = i;
        for(int j=i; j<n ; j++) {
            if(arr[j] < x) {
                x = arr[j];
                k = j;
            }
        }
        swap(arr[i], arr[k]);
    }
    for(int i=0; i<n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    int arr[n];

    for(int i=0; i<n; i++) cin >> arr[i];

    selection_sort(n, arr);
}