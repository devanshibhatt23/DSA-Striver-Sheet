#include <bits/stdc++.h>
#define ll long long
using namespace std;

int upperBound(vector<int> &nums, int x){
    int n = nums.size();
    int ans = n;

    int low = 0, high = n-1;
    while(low <= high) {
        int mid = (low + high) / 2;

        if(nums[mid] <= x) {
            low = mid + 1;
        }
        else {
            ans = mid;
            high = mid - 1;
        }
    }

    return ans;
}

int searchInsert(vector<int>& nums, int target) {
    int n = nums.size();
    int ans = -1;

    int low = 0, high = n-1;
    while(low <= high) {
        int mid = (low + high) / 2;

        if(nums[mid] == target) {
            ans = mid;
            break;
        }
        else if(nums[mid] > target) high = mid - 1;
        else low = mid + 1;
    }

    if(ans != -1) return ans;
    else {
        return upperBound(nums,target);
    }
}

int main() {
    vector<int> nums = {-1,4,5,6,9,10};
    int target = 7;

    cout << searchInsert(nums, target);
}