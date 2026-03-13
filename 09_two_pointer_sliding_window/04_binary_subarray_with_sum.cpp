#include <bits/stdc++.h>
#include <map>
#define ll long long
using namespace std;

int func(vector<int>& nums, int goal) {
    if(goal < 0) return 0;

    int n = nums.size();
    int left = 0, right = 0;
    int ans = 0, sum = 0;

    while(right < n) {
        sum += nums[right];

        while(sum > goal) {
            sum -= nums[left];
            left++;
        }

        ans += (right-left+1);
        right++;
    }

    return ans;
}

int numSubarraysWithSum(vector<int>& nums, int goal) {
    return func(nums,goal) - func(nums,goal-1);
}

int main() {
    vector<int> nums = {1,0,1,0,1};
    int k = 2;

    cout << numSubarraysWithSum(nums,k);
}