#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int recursion(int idx, int target, vector<int>& nums) {
        if(idx == 0) {
            int total = 0;

            if(target-nums[idx] == 0) total++;
            if(target+nums[idx] == 0) total++;

            return total;
        }

        int takeNegative = recursion(idx-1,target+nums[idx],nums);
        int takePositive = recursion(idx-1,target-nums[idx],nums);

        return takeNegative + takePositive;
    }

    int memoization(int idx, int target, vector<int>& nums, vector<unordered_map<int,int>> &dp) {
        if(idx == 0) {
            int total = 0;

            if(target-nums[idx] == 0) total++;
            if(target+nums[idx] == 0) total++;

            return dp[0][target] = total;
        }

        if(dp[idx].count(target)) return dp[idx][target];

        int takeNegative = memoization(idx-1,target+nums[idx],nums,dp);
        int takePositive = memoization(idx-1,target-nums[idx],nums,dp);

        return dp[idx][target] = takeNegative + takePositive;
    }

    int tabulation(int target, vector<int> &nums) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);

        if(abs(target) > total) return 0;

        vector<vector<int>> dp(n, vector<int> (2*total+1, 0));

        for(int sum=-total; sum<=total; sum++) {
            int s = 0;

            if(sum == nums[0]) s++;
            if(sum == -nums[0]) s++;

            dp[0][sum+total] = s;
        }

        for(int i=1; i<n; i++) {
            for(int sum=-total; sum<=total; sum++) {
                int takeNegative = 0, takePositive = 0;

                int add = sum+nums[i], sub = sum-nums[i];

                if(add <= total && add >= -total) {
                    takeNegative = dp[i-1][sum+nums[i]+total];
                }
                if(sub <= total && sub >= -total) {
                    takePositive = dp[i-1][sum-nums[i]+total];
                }

                dp[i][sum+total] = takeNegative + takePositive;
            }
        }

        return dp[n-1][target+total];
    }

    int space_optimization(int target, vector<int> &nums) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);

        if(abs(target) > total) return 0;

        vector<int> prev(2*total+1, 0);

        for(int sum=-total; sum<=total; sum++) {
            int s = 0;

            if(sum == nums[0]) s++;
            if(sum == -nums[0]) s++;

            prev[sum+total] = s;
        }

        for(int i=1; i<n; i++) {
            vector<int> curr(2*total+1, 0);

            for(int sum=-total; sum<=total; sum++) {
                int takeNegative = 0, takePositive = 0;

                int add = sum+nums[i], sub = sum-nums[i];

                if(add <= total && add >= -total) {
                    takeNegative = prev[sum+nums[i]+total];
                }
                if(sub <= total && sub >= -total) {
                    takePositive = prev[sum-nums[i]+total];
                }

                curr[sum+total] = takeNegative + takePositive;
            }

            prev = curr;
        }

        return prev[target+total];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        // return recursion(n-1,target,nums);

        // vector<unordered_map<int,int>> dp(n);
        // return memoization(n-1,target,nums,dp);

        // return tabulation(target,nums);

        return space_optimization(target,nums);
    }
};