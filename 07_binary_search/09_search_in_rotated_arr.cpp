#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool search(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0, high = n-1;
    bool ans = 0;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(nums[mid] == target) {
            ans = 1;
            break;
        }
        if(nums[low] == nums[mid] && nums[mid] == nums[high]) {
            low++, high--;
        }
        else if(nums[low] <= nums[mid]) {
            if(target >= nums[low] && target <= nums[mid]) high = mid - 1;
            else low = mid + 1;
        }
        else {
            if(mid != (high-low) && target >= nums[mid+1] && target <= nums[high]) {
                low = mid + 1;
            }
            else high = mid - 1;
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {-1,4,5,6,6,6,9,10};
    int target = 6;

    cout << search(nums,target);
}