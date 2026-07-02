#include <bits/stdc++.h>
using namespace std;

int recursion(int i, int j, vector<vector<int>> &grid) {
    if(i == 0 && j == 0) return grid[i][j];

    int up = INT_MAX, left = INT_MAX;

    if(i >= 1) up = grid[i][j] + recursion(i-1,j,grid);
    if(j >= 1) left = grid[i][j] + recursion(i,j-1,grid);

    return min(up,left);
}

int memoization(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp) {
    if(i == 0 && j == 0) return dp[0][0] = grid[i][j];

    if(dp[i][j] != -1) return dp[i][j];

    int up = INT_MAX, left = INT_MAX;

    if(i >= 1) up = grid[i][j] + memoization(i-1,j,grid,dp);
    if(j >= 1) left = grid[i][j] + memoization(i,j-1,grid,dp);

    return dp[i][j] = min(up,left);
}

int tabulation(int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(i == 0 && j == 0) {
                dp[0][0] = grid[0][0];
                continue;
            }

            int up = INT_MAX, left = INT_MAX;

            if(i >= 1) up = grid[i][j] + dp[i-1][j];
            if(j >= 1) left = grid[i][j] + dp[i][j-1];

            dp[i][j] = min(up,left);
        }
    }

    return dp[n-1][m-1];
}

int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dp(n, vector<int> (m,-1));
    
    return tabulation(n,m,grid,dp);
}