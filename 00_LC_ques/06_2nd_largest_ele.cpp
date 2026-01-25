#include <bits/stdc++.h>
using namespace std;

int second_largest(vector<int> arr) {
    int n = arr.size();

    int maxi = arr[0], maxi2 = INT_MIN;

    for(int i=1; i<n; i++) {
        if(arr[i] > maxi) {
            int temp = maxi;
            maxi = arr[i];
            maxi2 = temp;
        }
        else if(arr[i] > maxi2 && arr[i]!=maxi) maxi2 = arr[i];
    }

    if(maxi2 == INT_MIN) return -1;
    return maxi2;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i=0; i<n; i++) cin >> arr[i];

    int maxi2 = second_largest(arr);
    cout << maxi2 << endl;
}