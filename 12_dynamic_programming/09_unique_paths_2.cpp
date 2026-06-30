#include <bits/stdc++.h>
using namespace std;

int func(int i, int j, int n, int m, vector<vector<int>> &obstacleGrid) {
    if(i == 0 && j == 0) return 1;

    int up = 0, left = 0;
    if(i >= 1) if(obstacleGrid[i-1][j] != 1) up = func(i-1,j,n,m,obstacleGrid);
    if(j >= 1) if(obstacleGrid[i][j-1] != 1) left = func(i,j-1,n,m,obstacleGrid);
    
    return up + left;
}

int memoization(int i, int j, int n, int m, vector<vector<int>> &dp, vector<vector<int>> &obstacleGrid) {
    if(i == 0 && j == 0) {
        dp[0][0] = 1;
        return 1;
    }
    
    if(dp[i][j] != -1) return dp[i][j];
    
    int up = 0, left = 0;

    if(i >= 1) if(obstacleGrid[i-1][j] != 1) up = memoization(i-1,j,n,m,dp,obstacleGrid);
    if(j >= 1) if(obstacleGrid[i][j-1] != 1) left = memoization(i,j-1,n,m,dp,obstacleGrid);
    
    return dp[i][j] = up + left;
}

int tabulation(int n, int m, vector<vector<int>> &dp, vector<vector<int>> &obstacleGrid) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(i == 0 && j == 0) {
                dp[0][0] = 1;
                continue;
            }

            int up = 0, left = 0;

            if(i >= 1) if(obstacleGrid[i-1][j] != 1) up = dp[i-1][j];
            if(j >= 1) if(obstacleGrid[i][j-1] != 1) left = dp[i][j-1];

            dp[i][j] = up + left;
        }
    }

    return dp[n-1][m-1];
}

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int n = obstacleGrid.size(), m = obstacleGrid[0].size();

    vector<vector<int>> dp(n, vector<int> (m,-1));

    if(obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1) return 0;
    
    return tabulation(n,m,dp,obstacleGrid); 
}