#include <bits/stdc++.h>
using namespace std;

int func(int i, int j, int n, int m, unordered_map<pair<int,int>,int> &mp) {
    if(i == 0 && j == 0) return 1;

    int up = 0, left = 0;
    if(i >= 1) if(mp.find({i-1,j}) == mp.end()) up = func(i-1,j,n,m,mp);
    if(j >= 1) if(mp.find({i,j-1}) == mp.end()) left = func(i,j-1,n,m,mp);
    
    return up + left;
}

int memoization(int i, int j, int n, int m, vector<vector<int>> &dp, unordered_map<pair<int,int>,int> &mp) {
    if(i == 0 && j == 0) {
        dp[0][0] = 1;
        return 1;
    }
    
    if(dp[i][j] != -1) return dp[i][j];
    
    int up = 0, left = 0;

    if(i >= 1) if(mp.find({i-1,j}) == mp.end()) up = memoization(i-1,j,n,m,dp,mp);
    if(j >= 1) if(mp.find({i,j-1}) == mp.end()) left = memoization(i,j-1,n,m,dp,mp);
    
    return dp[i][j] = up + left;
}

int tabulation(int n, int m, vector<vector<int>> &dp, unordered_map<pair<int,int>,int> &mp) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(i == 0 && j == 0) {
                dp[0][0] = 1;
                continue;
            }

            int up = 0, left = 0;

            if(i >= 1) if(mp.find({i-1,j}) == mp.end()) up = dp[i-1][j];
            if(j >= 1) if(mp.find({i,j-1}) == mp.end()) left = dp[i][j-1];

            dp[i][j] = up + left;
        }
    }

    return dp[n-1][m-1];
}

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int n = obstacleGrid.size(), m = obstacleGrid[0].size();

    vector<vector<int>> dp(n, vector<int> (m,-1));

    unordered_map<pair<int,int>,int> mp;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(obstacleGrid[i][j]) mp[{i,j}] = 1;
        }
    }

    if(mp.find({0,0}) != mp.end() || mp.find({n-1,m-1}) != mp.end()) return 0;
    
    return tabulation(n,m,dp,mp); 
}