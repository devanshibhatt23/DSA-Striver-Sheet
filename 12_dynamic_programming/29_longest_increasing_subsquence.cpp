#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int recursion(int idx, int prev, vector<int>& nums) {
        if(idx == nums.size()) {
            return 0;
        }

        int notTake = recursion(idx+1, prev, nums);
        int take = 0;

        if(nums[idx] > prev) {
            take = 1 + recursion(idx+1, nums[idx], nums);
        }

        return max(take, notTake);
    }

    int memoization(int idx, int prev_idx, vector<int>& nums, vector<vector<int>> &dp) {
        if(idx == nums.size()) {
            return 0;
        }

        if(dp[idx][prev_idx+1] != -1) {
            return dp[idx][prev_idx+1];
        }

        int notTake = memoization(idx+1, prev_idx, nums, dp);
        int take = 0;

        if(prev_idx == -1) {
            take = 1 + memoization(idx+1, idx, nums, dp);
        }
        else if(nums[idx] > nums[prev_idx]) {
            take = 1 + memoization(idx+1, idx, nums, dp);
        }

        return dp[idx][prev_idx+1] = max(take, notTake);
    }

    int tabulation(vector<int> &nums) {
        int n = nums.size();

        vector<vector<int>> dp(n+1, vector<int> (n+1,0));

        for(int idx=n-1; idx>=0; idx--) {
            for(int prev_idx=idx-1; prev_idx>=-1; prev_idx--) {
                int notTake = dp[idx+1][prev_idx+1];
                int take = 0;

                if(prev_idx == -1) {
                    take = 1 + dp[idx+1][idx+1];
                }
                else if(nums[idx] > nums[prev_idx]) {
                    take = 1 + dp[idx+1][idx+1];
                }

                dp[idx][prev_idx+1] = max(take, notTake);
            }
        }

        return dp[0][0];
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // return recursion(0,-1e9,nums);

        // vector<vector<int>> dp(n, vector<int> (n+1,-1));
        // return memoization(0,-1,nums,dp);

        return tabulation(nums);
    }
};