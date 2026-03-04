#include <bits/stdc++.h>
#define ll long long
using namespace std;

int search(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0, high = n-1;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(nums[mid] == target) return mid;
        if(nums[mid] >= nums[low]) {
            if(target >= nums[low] && target <= nums[mid]) high = mid - 1;
            else low = mid + 1;
        }
        else {
            if(target >= nums[mid] && target <= nums[high]) low = mid + 1;
            else high = mid;
        }
    }
    return -1;
}

int main() {
    vector<int> nums = {-1,4,5,6,6,6,9,10};
    int target = 6;

    cout << search(nums,target);
}