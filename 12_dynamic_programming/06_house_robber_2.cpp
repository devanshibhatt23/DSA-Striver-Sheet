#include <bits/stdc++.h>
using namespace std;

int memoization(int idx, vector<int> &nums, vector<int> &dp) {
    if(idx == 0) {
        dp[0] = nums[0];
        return nums[0];
    }

    if(idx < 0) return 0;

    if(dp[idx] != -1) return dp[idx];

    int pick = nums[idx] + memoization(idx-2,nums,dp);
    int not_pick = 0 + memoization(idx-1,nums,dp);

    return dp[idx] = max(pick,not_pick);
}

int tabulation(int n, vector<int> &nums, vector<int> &dp) {
    dp[0] = nums[0];
    if(1 < n) {
        dp[1] = max(nums[1],dp[0]);
    }

    for(int i=2; i<n; i++) {
        int pick = nums[i] + dp[i-2];
        int not_pick = 0 + dp[i-1];

        dp[i] = max(pick,not_pick);
    }

    return dp[n-1];
}

int space_optimization(int n, vector<int> &nums) {
    int prev2 = nums[0];
    if(n == 1) return prev2;

    int prev = max(nums[1],prev2);

    for(int i=2; i<n; i++) {
        int pick = nums[i] + prev2;
        int not_pick = 0 + prev;

        prev2 = prev;
        prev = max(pick,not_pick);
    }

    return prev;
}

int rob(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n,-1);

    vector<int> temp1, temp2;
    for(int i=0; i<n; i++) {
        if(i != 0) temp1.push_back(nums[i]);
        if(i != n-1) temp2.push_back(nums[i]);
    }

    return max(space_optimization(n-1,temp1), space_optimization(n-1,temp2));
}