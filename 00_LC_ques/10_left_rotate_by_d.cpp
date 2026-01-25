#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &nums, int k) {
    int n = nums.size();
    k = k % n;

    vector<int> v(n);

    for(int i=0; i<n; i++) {
        v[(i+k)%n] = nums[i];
    }

    for(int i=0; i<n; i++) nums[i] = v[i];

    for(int i=0; i<n; i++) cout << nums[i] << " ";
}

int main() {
    vector<int> v = {1,2,3,4,5,6,7};
    int k = 3;

    solve(v,k);
}

// 0 1 2 3 4 5 6
// 1 2 3 4 5 6 7 k = 3
// 5 6 7 1 2 3 4