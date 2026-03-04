#include <bits/stdc++.h>
#define ll long long
using namespace std;

int findMin(vector<int>& nums) {
    int n = nums.size();
    int mini = INT_MAX;
    int low = 0, high = n-1;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(nums[mid] >= nums[low]) {
            mini = min(mini,nums[low]);
            low = mid + 1;
        }
        else {
            mini = min(mini,nums[mid]);
            high = mid - 1;
        }
    }
    return mini;
}

int main() {
    vector<int> nums = {9,10,-1,4,5,6,6,6};

    cout << findMin(nums);
}