#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int recursion(int idx, int buy, vector<int> &prices) {
        int n = prices.size();
        if(idx >= n) {
            return 0;
        }

        if(buy) {
            int take = -prices[idx] + recursion(idx+1,0,prices);
            int notTake = recursion(idx+1,1,prices);

            return max(take,notTake);
        }
        else {
            int take = prices[idx] + recursion(idx+2,1,prices);
            int notTake = recursion(idx+1,0,prices);

            return max(take,notTake);
        }
    }

    int memoization(int idx, int buy, vector<int> &prices, vector<vector<int>> &dp) {
        int n = prices.size();
        if(idx >= n) {
            return 0;
        }

        if(dp[idx][buy] != -1) {
            return dp[idx][buy];
        }

        if(buy) {
            int take = -prices[idx] + memoization(idx+1,0,prices,dp);
            int notTake = memoization(idx+1,1,prices,dp);

            return max(take,notTake);
        }
        else {
            int take = prices[idx] + memoization(idx+2,1,prices,dp);
            int notTake = memoization(idx+1,0,prices,dp);

            return max(take,notTake);
        }
    }

    int tabulation(vector<int> &prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int> (2,0));

        for(int i=n-1; i>=0; i--) {
            for(int j=0; j<2; j++) {
                if(j == 0) {
                    int take = prices[i] + dp[i+2][1];
                    int notTake = dp[i+1][0];

                    dp[i][j] = max(take,notTake);
                }
                else {
                    int take = -prices[i] + dp[i+1][0];
                    int notTake = dp[i+1][1];

                    dp[i][j] = max(take,notTake);
                }
            }
        }

        return dp[0][1];
    }

    int maxProfit(vector<int>& prices) {
        // return recursion(0,1,prices);

        // vector<vector<int>> dp(prices.size(), vector<int> (2,-1));
        // return memoization(0,1,prices,dp);

        return tabulation(prices);
    }
};