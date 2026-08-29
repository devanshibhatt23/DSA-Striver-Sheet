#include <bits/stdc++.h>
using namespace std;

bool recursion(int i, vector<int> arr, int k) {
    if(k == 0) return 1;
    if(i == 0) return arr[i] == k;

    bool not_take = recursion(i-1,arr,k), take = 0;
    if(arr[i] <= k) {
        take = recursion(i-1,arr,k-arr[i]);
    }

    return take || not_take;
}

bool memoization(int i, vector<int> &arr, int k, vector<vector<int>> &dp) {
    if(dp[i][k] != -1) return dp[i][k];

    if(k == 0) return dp[i][k] = 1;

    if(i == 0) {
        if(arr[i] == k) return dp[i][k] = 1;
        else return dp[i][k] = 0;
    }

    bool not_take = memoization(i-1,arr,k,dp), take = 0;
    if(arr[i] <= k) {
        take = memoization(i-1,arr,k-arr[i],dp);
    }

    return dp[i][k] = take || not_take;
}

bool tabulation(vector<int>arr, int k, vector<vector<int>> &dp) {
    int n = arr.size();

    for(int i=0; i<n; i++) {
        dp[i][0] = 1;
    }

    for(int j=1; j<=k; j++) {
        if(arr[0] == j) dp[0][j] = 1;
        else dp[0][j] = 0;
    }

    for(int i=1; i<n; i++) {
        for(int j=1; j<=k; j++) {
            bool not_take = dp[i-1][j];
            bool take = 0;

            if(arr[i] <= j) {
                take = dp[i-1][j-arr[i]];
            }

            dp[i][j] = take || not_take;
        }
    }

    return dp[n-1][k];
}

int minimumDifference(vector<int> &nums) {
    int n = nums.size();
    int total = 0;

    for(int i : nums) total += i;

    vector<vector<int>> dp(n, vector<int> (total+1,0));

    int mini_diff = INT_MAX;
    dp[n-1][total] = tabulation(nums,total,dp);

    int i = n-1;
    for(int j=0; j<=total; j++) {
        if(dp[i][j]) {
            int val1 = j;
            int val2 = total-j;

            mini_diff = min(mini_diff, abs(val1-val2));
        }
    }

    return mini_diff;
}