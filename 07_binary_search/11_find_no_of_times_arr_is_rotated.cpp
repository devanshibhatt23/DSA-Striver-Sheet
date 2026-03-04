#include <bits/stdc++.h>
#define ll long long
using namespace std;

int find_min_idx(vector<int>& nums) {
    int n = nums.size();
    int low = 0, high = n-1;
    int mini = INT_MAX, idx = -1;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(nums[low] <= nums[mid]) {
            if(nums[low] < mini) {
                idx = low;
                mini = nums[low];
            }
            low = mid + 1;
        }
        else {
            if(nums[mid] < mini) {
                idx = mid;
                mini = nums[mid];
            }
            high = mid - 1;
        }
    }
    return idx;
}

int main() {
    vector<int> nums = {9,10,1,2,3,4,5,6};

    cout << find_min_idx(nums);
}