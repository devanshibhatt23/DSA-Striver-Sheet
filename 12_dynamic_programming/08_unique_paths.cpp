#include <bits/stdc++.h>
using namespace std;

int func(int i, int j, int n, int m) {
    if(i == 0 && j == 0) return 1;

    int up = 0, left = 0;
    if(i >= 1) up = func(i-1,j,n,m);
    if(j >= 1) left = func(i,j-1,n,m);
    
    return up + left;
}

int memoization(int i, int j, int n, int m, vector<vector<int>> &dp) {
    if(i == 0 && j == 0) {
        dp[0][0] = 1;
        return 1;
    }
    
    if(dp[i][j] != -1) return dp[i][j];
    
    int up = 0, left = 0;

    if(i >= 1) up = memoization(i-1,j,n,m,dp);
    if(j >= 1) left = memoization(i,j-1,n,m,dp);
    
    return dp[i][j] = up + left;
}

int tabulation(int n, int m, vector<vector<int>> &dp) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(i == 0 && j == 0) {
                dp[0][0] = 1;
                continue;
            }

            int up = 0, left = 0;

            if(i >= 1) up = dp[i-1][j];
            if(j >= 1) left = dp[i][j-1];

            dp[i][j] = up + left;
        }
    }

    return dp[n-1][m-1];
}

int space_optimization(int n, int m) {
    vector<int> prev(n,0);
    
    for(int i=0; i<n; i++) {
        vector<int> temp(n,0);
        for(int j=0; j<m; j++) {
            if(i == 0 && j == 0) continue;
            else {
                temp[j] = prev[j];
                if(j != 0) temp[j] += temp[j-1];
            }
        }

        prev = temp;
    }

    return prev[m-1];
}

int uniquePaths(int m, int n) {
    return space_optimization(m,n); 
}