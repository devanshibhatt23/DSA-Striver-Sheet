#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int recursion(int idx, int weight, vector<int>& wt, vector<int>& val) {
        if(idx == 0) {
            return val[0] * (weight/wt[0]);
        }

        int take = 0;
        int notTake = recursion(idx-1,weight,wt,val);

        if(wt[idx] <= weight) {
            take = val[idx] + recursion(idx,weight-wt[idx],wt,val);
        }

        return max(take,notTake);
    }

    int memoization(int idx, int weight, vector<int>& wt, vector<int>& val, vector<vector<int>> &dp) {
        if(idx == 0) {
            return dp[0][weight] = val[0] * (weight/wt[0]);
        }

        if(dp[idx][weight] != -1) return dp[idx][weight];

        int take = 0;
        int notTake = memoization(idx-1,weight,wt,val,dp);

        if(wt[idx] <= weight) {
            take = val[idx] + memoization(idx,weight-wt[idx],wt,val,dp);
        }

        return dp[idx][weight] = max(take,notTake);
    }

    int tabulation(int weight, vector<int>& wt, vector<int>& val) {
        int n = wt.size();
        vector<vector<int>> dp(n, vector<int> (weight+1));

        for(int i=0; i<=weight; i++) {
            dp[0][i] = val[0] * (i/wt[0]);
        }

        for(int i=1; i<n; i++) {
            for(int j=0; j<=weight; j++) {
                int take = 0;
                int notTake = dp[i-1][j];

                if(wt[i] <= j) {
                    take = val[i] + dp[i][j-wt[i]];
                }

                dp[i][j] = max(take,notTake);
            }
        }

        return dp[n-1][weight];
    }

    public:
    int unboundedKnapsack(vector<int>& wt, vector<int>& val, int n, int W) {
        // return recursion(n-1,W,wt,val);

        // vector<vector<int>> dp(n, vector<int> (W+1,-1));
        // return memoization(n-1,W,wt,val,dp);

        return tabulation(W,wt,val);
    }
};