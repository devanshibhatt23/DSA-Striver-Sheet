#include <bits/stdc++.h>
using namespace std;

// tc - 2^n, sc - o(n) + o(n)
int recursion(int idx, vector<int> &heights) {
    if(idx == 0) return 0;

    int left = recursion(idx-1,heights) + abs(heights[idx] - heights[idx-1]);
    int right = INT_MAX;
    
    if(idx>1) right = recursion(idx-2,heights) + abs(heights[idx] - heights[idx-2]);

    return min(left,right);
}



// memoization - tc - o(n), sc - o(n) + o(n)
int recursion_memoization(int idx, vector<int> &heights, vector<int> &dp) {
    if(idx == 0) {
        dp[0] = 0;
        return 0;
    }

    if(dp[idx] != -1) return dp[idx];

    int left = recursion_memoization(idx-1,heights,dp) + abs(heights[idx] - heights[idx-1]);
    int right = INT_MAX;
    
    if(idx>1) right = recursion_memoization(idx-2,heights,dp) + abs(heights[idx] - heights[idx-2]);

    return dp[idx] = min(left,right);
}



// tabulation - tc - o(n), sc - o(n)
int recursion_tabulation(int n, vector<int> &heights, vector<int> &dp) {
    dp[0] = 0;

    for(int i=1; i<=n; i++) {
        int left = dp[i-1] + abs(heights[i] - heights[i-1]);
        int right = INT_MAX;

        if(i > 1) right = dp[i-2] + abs(heights[i] - heights[i-2]);

        dp[i] = min(left,right);
    }

    return dp[n];
}



// space optimization - tc - o(n), sc - o(n)
int recursion_space_optimization(int n, vector<int> &heights) {
    int prev2 = 0;
    int prev = 0;

    for(int i=1; i<=n; i++) {
        int left = prev + abs(heights[i] - heights[i-1]);
        int right = INT_MAX;

        if(i > 1) right = prev2 + abs(heights[i] - heights[i-2]);

        prev2 = prev;
        prev = min(left,right);
    }

    return prev;
}


int frogJump(vector<int>& heights) {
    int n = heights.size();

    vector<int> dp(n+1,-1);
    return recursion_space_optimization(n-1,heights);
}

int main() {
    int n;
    cin >> n;

    vector<int> heights(n);
    for(int i=0; i<n; i++) cin >> heights[i];

    cout << frogJump(heights);
}