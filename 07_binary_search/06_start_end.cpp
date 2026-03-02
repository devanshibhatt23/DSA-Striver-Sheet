#include <bits/stdc++.h>
#define ll long long
using namespace std;

int start_pos(vector<int>& nums, int target) {
    int n = nums.size();
    int st = -1;
    int low = 0, high = n-1;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(nums[mid] > target) high = mid - 1;
        else if(nums[mid] < target) low = mid + 1;
        else {
            st = mid;
            high = mid - 1;
        }
    }
    return st;
}

int end_pos(vector<int>& nums, int target) {
    int n = nums.size();
    int end = -1;
    int low = 0, high = n-1;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(nums[mid] > target) high = mid - 1;
        else if(nums[mid] < target) low = mid + 1;
        else {
            end = mid;
            low = mid + 1;
        }
    }
    return end;
}

vector<int> searchRange(vector<int>& nums, int target) {
    return {start_pos(nums,target), end_pos(nums,target)};
}

int main() {
    vector<int> nums = {-1,4,5,6,9,10};
    int target = 11;

    vector<int> ans = searchRange(nums,target);
    for(int &i : ans) cout << i << " ";
}