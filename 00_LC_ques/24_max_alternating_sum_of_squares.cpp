#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++) {
            if(nums[i] < 0) nums[i] = -nums[i];
        }

        sort(nums.begin(), nums.end());

        long long ans = 0;

        for(int i=0; i<n; i++) {
            if(i < n/2) ans -= (nums[i] * 1LL * nums[i]);
            else ans += (nums[i] * 1LL * nums[i]);
        }

        return ans;
    }
};