#include <bits/stdc++.h>
using namespace std;

int removedupls(vector<int> &arr) {
    int n = arr.size();

    int i = 0;

    for(int j=1; j<n; j++) {
        if(arr[j] != arr[i]) {
            i++;
            arr[i] = arr[j];
        }
    }

    return i+1;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i=0; i<n; i++) cin >> arr[i];

    int k = removedupls(arr);

    for(int i=0; i<k; i++) cout << arr[i] << " ";
}