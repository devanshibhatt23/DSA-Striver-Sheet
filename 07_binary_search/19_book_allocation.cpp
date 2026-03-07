#include <bits/stdc++.h>
#define ll long long
using namespace std;

int possible(vector<int>& nums, long long mid) {
    int n = nums.size();
    int ct = 1;
    long long sum = 0;

    for(int i=0; i<n; i++) {
        if(sum + nums[i] <= mid) {
            sum += nums[i];
        }
        else {
            ct++;
            sum = nums[i];
        }
    }

    return ct;
}

int splitArray(vector<int>& nums, int k) {
    int n = nums.size();
    long long low = nums[0], high = nums[0];
    long long ans = -1;

    for(int i=1; i<n; i++) high += nums[i];

    while(low <= high) {
        long long mid = (low + high) / 2;

        int x = possible(nums,mid);
        if(x <= k) {
            high = mid - 1;
        }
        else low = mid + 1; 
    }
    return low;
}

int main() {
    vector<int> nums = {1,4,4};
    int k = 3;

    cout << splitArray(nums,k);
}