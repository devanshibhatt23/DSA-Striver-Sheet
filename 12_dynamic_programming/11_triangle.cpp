#include <bits/stdc++.h>
using namespace std;

int recursion(int i, int j, vector<vector<int>> &grid) {
    int n = grid.size();

    if(i == n-1) return grid[i][j];

    int ans1 = INT_MAX, ans2 = INT_MAX;

    ans1 = recursion(i+1,j,grid);
    ans2 = recursion(i+1,j+1,grid);

    return grid[i][j] + min(ans1,ans2);
}

int memoization(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp) {
    int n = grid.size();

    if(i == n-1) return dp[i][j] = grid[i][j];
    if(dp[i][j] != -1) return dp[i][j];

    int ans1 = INT_MAX, ans2 = INT_MAX;

    ans1 = memoization(i+1,j,grid,dp);
    ans2 = memoization(i+1,j+1,grid,dp);

    return dp[i][j] = grid[i][j] + min(ans1,ans2);
}

int tabulation(vector<vector<int>> &grid, vector<vector<int>> &dp) {
    int n = grid.size();

    for(int j=0; j<n; j++) {
        dp[n-1][j] = grid[n-1][j];
    }

    for(int i=n-2; i>=0; i--) {
        for(int j=i; j>=0; j--) {
            int ans1 = dp[i+1][j];
            int ans2 = dp[i+1][j+1];

            dp[i][j] = grid[i][j] + min(ans1,ans2);
        }
    }

    return dp[0][0];
}

int minimumTotal(vector<vector<int>>& triangle) { 
    int n = triangle.size();

    vector<vector<int>> dp(n, vector<int> (n,0));

    return tabulation(triangle,dp);
}