#include <bits/stdc++.h>
using namespace std;


// memoization - tc - o(n*k), sc - o(n) + o(n)
int recursion_memoization(int k, int idx, vector<int> &heights, vector<int> &dp) {
    if(idx == 0) {
        dp[0] = 0;
        return 0;
    }

    if(dp[idx] != -1) return dp[idx];

    int ans = INT_MAX;

    for(int i=1; i<=k; i++) {
        if(idx-i >= 0) {
            int jump = recursion_memoization(k,idx-k,heights,dp) + abs(heights[idx]-heights[idx-i]);
            ans = min(ans,jump); 
        }
        else break;
    }

    dp[idx] = ans;
    return ans;
}



// tabulation - tc - o(n*k), sc - o(n)
int recursion_tabulation(int k, int n, vector<int> &heights, vector<int> &dp) {
    dp[0] = 0;

    for(int i=1; i<=n; i++) {
        int ans = INT_MAX;

        for(int j=1; j<=k; j++) {
            if(i-j >= 0) {
                int jump = dp[i-j] + abs(heights[i] - heights[i-j]);
                ans = min(ans,jump);
            }
        }

        dp[i] = ans;
    }

    return dp[n];
}