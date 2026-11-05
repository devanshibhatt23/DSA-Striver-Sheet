#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int recursion(int idx, int buy, int ct, vector<int> &prices) {
        int n = prices.size();

        if(idx == n) {
            return 0;
        }

        if(ct == 0) {
            return 0;
        }

        if(buy) {
            int take = -prices[idx] + recursion(idx+1,0,ct,prices);
            int notTake = recursion(idx+1,1,ct,prices);

            return max(take,notTake);
        }
        else {
            int take = prices[idx] + recursion(idx+1,1,ct-1,prices);
            int notTake = recursion(idx+1,0,ct,prices);

            return max(take,notTake);
        }
    }

    int memoization(int idx, int buy, int ct, vector<int> &prices, vector<vector<vector<int>>> &dp) {
        int n = prices.size();

        if(idx == n) {
            return 0;
        }

        if(ct == 0) {
            return 0;
        }

        if(dp[idx][buy][ct] != -1) {
            return dp[idx][buy][ct];
        }

        if(buy) {
            int take = -prices[idx] + memoization(idx+1,0,ct,prices,dp);
            int notTake = memoization(idx+1,1,ct,prices,dp);

            return dp[idx][buy][ct] = max(take,notTake);
        }
        else {
            int take = prices[idx] + memoization(idx+1,1,ct-1,prices,dp);
            int notTake = memoization(idx+1,0,ct,prices,dp);

            return dp[idx][buy][ct] = max(take,notTake);
        }
    }

    int tabulation(int k, vector<int> &prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (k+1,0)));

        for(int idx=n-1; idx>=0; idx--) {
            for(int j=0; j<2; j++) {
                for(int m=1; m<=k; m++) {
                    if(j == 1) {
                        int take = -prices[idx] + dp[idx+1][0][m];
                        int notTake = dp[idx+1][1][m];

                        dp[idx][j][m] = max(take,notTake);
                    }
                    else {
                        int take = prices[idx] + dp[idx+1][1][m-1];
                        int notTake = dp[idx+1][0][m];

                        dp[idx][j][m] = max(take,notTake);
                    }
                }
            }
        }

        return dp[0][1][k];
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        // return recursion(0,1,k,prices);

        // vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (k+1,-1)));
        // return memoization(0,1,k,prices,dp);

        return tabulation(k,prices);
    }
};