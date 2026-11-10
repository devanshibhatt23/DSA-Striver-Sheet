#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long recursion(int idx, int n, vector<int> &costs) {
        if(idx >= n) {
            return 0;
        }
        
        long long dis1 = 1e9, dis2 = 1e9, dis3 = 1e9;
         
        if(idx+1 <= n) {
            dis1 = costs[idx] + 1 + recursion(idx+1,n,costs);
        }
        if(idx+2 <= n) {
            dis2 = costs[idx+1] + 4 + recursion(idx+2,n,costs);
        }
        if(idx+3 <= n) {
            dis3 = costs[idx+2] + 9 + recursion(idx+3,n,costs);
        }

        return min(dis1, min(dis2,dis3));
    }

    long long memoization(int idx, int n, vector<int> &costs, vector<int> &dp) {
        if(idx >= n) {
            return 0;
        }

        if(dp[idx] != -1) {
            return dp[idx];
        }
        
        long long dis1 = 1e9, dis2 = 1e9, dis3 = 1e9;
         
        if(idx+1 <= n) {
            dis1 = costs[idx] + 1 + memoization(idx+1,n,costs,dp);
        }
        if(idx+2 <= n) {
            dis2 = costs[idx+1] + 4 + memoization(idx+2,n,costs,dp);
        }
        if(idx+3 <= n) {
            dis3 = costs[idx+2] + 9 + memoization(idx+3,n,costs,dp);
        }

        return dp[idx] = min(dis1, min(dis2,dis3));
    }

    long long tabulation(int n, vector<int> &costs) {
        vector<int> dp(n+1,0);

        for(int idx=n-1; idx>=0; idx--) {
            long long dis1 = 1e9, dis2 = 1e9, dis3 = 1e9;

            if(idx+1 <= n) {
                dis1 = costs[idx] + 1 + dp[idx+1];
            }
            if(idx+2 <= n) {
                dis2 = costs[idx+1] + 4 + dp[idx+2];
            }
            if(idx+3 <= n) {
                dis3 = costs[idx+2] + 9 + dp[idx+3];
            }

            dp[idx] = (int)(min(dis1, min(dis2,dis3)));
        }

        return dp[0];
    }

    int climbStairs(int n, vector<int>& costs) {
        // return recursion(0,n,costs);

        // vector<int> dp(n,-1);
        // return memoization(0,n,costs,dp);

        return tabulation(n,costs);
    }
};