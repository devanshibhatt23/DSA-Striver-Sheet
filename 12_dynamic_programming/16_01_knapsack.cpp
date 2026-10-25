#include <bits/stdc++.h>
using namespace std;

// tc - O(2^n), sc - O(1)
int recursion(int idx, int w, vector<int> &val, vector<int> &wt) {
    if(idx == 0) {
        if(wt[0] <= w) {
            return val[0];
        }
        else return 0;
    }

    int take = INT_MIN;
    if(wt[idx] <= w) {
        take = val[idx] + recursion(idx-1,w-wt[idx],val,wt);
    }

    int notTake = recursion(idx-1,w,val,wt);

    return max(take,notTake);
}

// TC, SC - O(n*m)
int memoisation(int idx, int w, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp) {
    if(idx == 0) {
        if(wt[0] <= w) {
            return val[0];
        }
        else return 0;
    }

    if(dp[idx][w] != -1) return dp[idx][w];

    int take = INT_MIN;
    if(wt[idx] <= w) {
        take = val[idx] + memoisation(idx-1,w-wt[idx],val,wt,dp);
    }

    int notTake = memoisation(idx-1,w,val,wt,dp);

    return dp[idx][w] = max(take,notTake);
}

int tabulation(int idx, int w, vector<int> &val, vector<int> &wt) {
    int n = val.size();
    vector<vector<int>> dp(n, vector<int> (w+1,0));

    for(int i=wt[0]; i<=w; i++) {
        dp[0][i] = val[0];
    }

    for(int i=1; i<n; i++) {
        for(int j=0; j<=w; j++) {
            if(wt[i] > j) {
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[idx-1][j-wt[i]]);
            }
        }
    }

    return dp[n-1][w];
}