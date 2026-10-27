#include <bits/stdc++.h>
using namespace std;

class Solution{
    int recurison(int idx, int n, vector<int> &price) {
        if(idx == 0) {
            return n*price[0];
        }

        int take = 0;
        int notTake = recurison(idx-1,n,price);

        if(idx+1 <= n) {
            take = price[idx] + recurison(idx,n-idx-1,price);
        }

        return max(take,notTake);
    }

    int memoization(int idx, int n, vector<int> &price, vector<vector<int>> &dp) {
        if(idx == 0) {
            return dp[0][n] = n*price[0];
        }

        if(dp[idx][n] != -1) return dp[idx][n];

        int take = 0;
        int notTake = memoization(idx-1,n,price,dp);

        if(idx+1 <= n) {
            take = price[idx] + memoization(idx,n-idx-1,price,dp);
        }

        return dp[idx][n] = max(take,notTake);
    }

    int tabulation(int n, vector<int> &price) {
        vector<vector<int>> dp(n, vector<int> (n+1));

        for(int j=0; j<=n; j++) {
            dp[0][j] = j*price[0];
        }

        for(int i=1; i<n; i++) {
            for(int j=0; j<=n; j++) {
                int take = 0;
                int notTake = dp[i-1][j];

                if(i+1 <= j) {
                    take = price[i] + dp[i][j-i-1];
                }

                dp[i][j] = max(take,notTake);
            }
        }

        return dp[n-1][n];
    }

public:
    int rodCutting(vector<int> price, int n) {
        // return recurison(n-1,n,price);

        // vector<vector<int>> dp(n, vector<int> (n+1,-1));
        // return memoization(n-1,n,price,dp);

        return tabulation(n,price);
    }
};