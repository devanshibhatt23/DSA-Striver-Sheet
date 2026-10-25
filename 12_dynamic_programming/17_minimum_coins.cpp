#include <bits/stdc++.h>
using namespace std;

int recursion(int idx, int amount, vector<int> &coins) {
    if(idx == 0) {
        if(amount % coins[idx] == 0) {
            return amount/coins[idx];
        }
        else return 1e9;
    }

    int notTake = recursion(idx-1,amount,coins);
    int take = 1e9;

    if(coins[idx] <= amount) {
        take = 1 + recursion(idx,amount-coins[idx],coins);
    }

    return min(take,notTake);
}

int memoization(int idx, int amount, vector<int> &coins, vector<vector<int>> &dp) {
    if(idx == 0) {
        if(amount % coins[idx] == 0) {
            return dp[idx][amount] = amount/coins[idx];
        }
        else return dp[idx][amount] = 1e9;
    }

    if(dp[idx][amount] != -2) return dp[idx][amount];

    int notTake = memoization(idx-1,amount,coins,dp);
    int take = 1e9;

    if(coins[idx] <= amount) {
        take = 1 + memoization(idx,amount-coins[idx],coins,dp);
    }

    return dp[idx][amount] = min(take,notTake);
}

int tabulation(int amount, vector<int> &coins, vector<vector<int>> &dp) {
    int n = coins.size();

    for(int amt=0; amt<=amount; amt++) {
        if(amt % coins[0] == 0) {
            dp[0][amt] = amt/coins[0];
        }
        else dp[0][amt] = 1e9;
    }

    for(int i=1; i<n; i++) {
        for(int amt=0; amt<=amount; amt++) {
            int take = 1e9;
            int notTake = dp[i-1][amt];
            
            if(coins[i] <= amt) {
                take = 1 + dp[i][amt-coins[i]];
            }

            dp[i][amt] = min(take,notTake);
        }
    }

    return dp[n-1][amount];
}

int space_optimization(int amount, vector<int> &coins) {
    int n = coins.size();
    vector<int> prev(amount+1);

    for(int amt=0; amt<=amount; amt++) {
        if(amt % coins[0] == 0) {
            prev[amt] = amt/coins[0];
        }
        else prev[amt] = 1e9;
    }

    for(int i=1; i<n; i++) {
        vector<int> curr(amount+1);

        for(int amt=0; amt<=amount; amt++) {
            int take = 1e9;
            int notTake = prev[amt];
            
            if(coins[i] <= amt) {
                take = 1 + curr[amt-coins[i]];
            }

            curr[amt] = min(take,notTake);
        }

        prev = curr;
    }

    return prev[amount];
}

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int> (amount+1));

    int ans = tabulation(amount,coins,dp);

    if(ans >= 1e9) return -1;
    return ans;
}