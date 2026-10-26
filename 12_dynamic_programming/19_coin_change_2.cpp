#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int recursion(int idx, int amount, vector<int>& coins) {
        if(idx == 0) {
            if(amount % coins[0] == 0) return 1;
            return 0;
        }

        int take = 0;
        int notTake = recursion(idx-1,amount,coins);

        if(coins[idx] <= amount) {
            take = recursion(idx,amount-coins[idx],coins);
        }

        return take + notTake;
    }

    int memoization(int idx, int amount, vector<int>& coins, vector<vector<unsigned int>> &dp) {
        if(idx == 0) {
            if(amount % coins[0] == 0) return dp[idx][amount] = 1;
            return dp[idx][amount] = 0;
        }

        if(dp[idx][amount] != -1) return dp[idx][amount];

        int take = 0;
        int notTake = memoization(idx-1,amount,coins,dp);

        if(coins[idx] <= amount) {
            take = memoization(idx,amount-coins[idx],coins,dp);
        }

        return dp[idx][amount] = take + notTake;
    }

    int tabulation(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<unsigned int>> dp(n, vector<unsigned int> (amount+1,0));

        for(int sum=0; sum<=amount; sum++) {
            if(sum % coins[0] == 0) dp[0][sum] = 1;
            else dp[0][sum] = 0;
        }

        for(int i=1; i<n; i++) {
            for(int sum=0; sum<=amount; sum++) {
                dp[i][sum] = dp[i-1][sum];

                if(coins[i] <= sum) {
                    dp[i][sum] += dp[i][sum-coins[i]];
                }
            }
        }

        return dp[n-1][amount];
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        // return recursion(n-1,amount,coins);

        // vector<vector<unsigned int>> dp(n, vector<unsigned int> (amount+1,-1));
        // return memoization(n-1,amount,coins,dp);

        return tabulation(amount,coins);   
    }
};