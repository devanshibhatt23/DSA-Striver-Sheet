#include <bits/stdc++.h>
#define ll long long
using namespace std;

int findPeakElement(vector<int>& nums) {
    int n = nums.size();
    int low = 0, high = n-1;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(mid != 0 && mid != n-1) {
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;
            if(nums[mid] < nums[mid-1] && nums[mid] > nums[mid+1]) high = mid - 1;
            else if(nums[mid] > nums[mid-1] && nums[mid] < nums[mid+1]) low = mid + 1;
            else {
                high = mid - 1;
            }
        }
        else if(mid != 0) {
            if(nums[mid] > nums[mid-1]) return mid;
            else return mid - 1;
        }
        else if(mid != n-1) {
            if(nums[mid] < nums[mid+1]) return mid+1;
            else return mid;
        }
        else return mid;
    }
    return 0;
}

int main() {
    vector<int> nums = {9,7,3,7,8};

    cout << nums[findPeakElement(nums)];
}