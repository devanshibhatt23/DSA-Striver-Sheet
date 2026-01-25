// brute solution
#include <bits/stdc++.h>
using namespace std;

void rotatebyone(int d,vector<int> &nums) {
    int n = nums.size();
    d %= n;

    vector<int> temp;
    for(int i=0; i<d; i++) temp.push_back(nums[i]);

    for(int i=d; i<n; i++) nums[i-d] = nums[i];

    for(int i=n-d; i<n; i++) {
        nums[i] = temp[i-(n-d)];
    }
}

int main() {
    int n,d;
    cin >> n >> d;
    vector<int> arr(n);

    for(int i=0; i<n; i++) cin >> arr[i];

    rotatebyone(d,arr);

    for(int i=0; i<n; i++) cout << arr[i] << " ";
}