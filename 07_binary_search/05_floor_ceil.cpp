#include <bits/stdc++.h>
#define ll long long
using namespace std;

int floor_val(vector<int> &nums, int x) {
    int n = nums.size();
    int floor_idx = n;
    int low = 0, high = n-1;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(nums[mid] > x) high = mid - 1;
        else {
            floor_idx = mid;
            low = mid + 1;
        }
    }

    if(floor_idx != n) return nums[floor_idx];
    return -1;
}

int ceil_val(vector<int> &nums, int x) {
    int n = nums.size();
    int ceil_idx = n;
    int low = 0, high = n-1;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(nums[mid] < x) low = mid + 1;
        else {
            ceil_idx = mid;
            high = mid - 1;
        }
    }

    if(ceil_idx != n) return nums[ceil_idx];
    return -1;
}

vector<int> getFloorAndCeil(vector<int> nums, int x) {
    return {floor_val(nums,x), ceil_val(nums,x)};
}

int main() {
    vector<int> nums = {-1,4,5,6,9,10};
    int target = 11;

    vector<int> ans = getFloorAndCeil(nums,target);
    for(int &i : ans) cout << i << " ";
}