#include <bits/stdc++.h>
using namespace std;

long long recursion(int i, int j, int x, int y, vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();

    if(j < 0 || j > m-1 || y < 0 || y > m-1) {
        return -1e8;
    }

    if(i == n-1) {
        if(j != y) return grid[i][j] + grid[x][y];
        else return grid[i][j];
    }

    long long ans = INT_MIN;

    for(int a=-1; a<=1; a++) {
        for(int b=-1; b<=1; b++) {
            long long val = 0;
            if(j == y) {
                val += grid[i][j];
            }
            else {
                val += (grid[i][j] + grid[x][y]);
            }

            val += recursion(i+1,j+a,x+1,y+b,grid);

            ans = max(ans,val);
        }
    }

    return ans;
}

int memoization(int i, int j, int x, int y, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp) {
    int n = grid.size(), m = grid[0].size();

    if(j < 0 || j > m-1 || y < 0 || y > m-1) {
        return -1e8;
    }

    if(dp[i][j][y] != -1) return dp[i][j][y];

    if(i == n-1) {
        if(j != y) return dp[i][j][y] = grid[i][j] + grid[x][y];
        else return dp[i][j][y] = grid[i][j];
    }

    int ans = 0;

    for(int a=-1; a<=1; a++) {
        for(int b=-1; b<=1; b++) {
            int val = 0;
            if(j == y) {
                val += grid[i][j];
            }
            else {
                val += (grid[i][j] + grid[x][y]);
            }

            val += memoization(i+1,j+a,x+1,y+b,grid,dp);

            ans = max(ans,val);
        }
    }

    return dp[i][j][y] = ans;
}

int tabulation(vector<vector<int>> &grid, vector<vector<vector<int>>> &dp) {
    int n = grid.size(), m = grid[0].size();

    for(int j=0; j<m; j++) {
        for(int y=0; y<m; y++) {
            dp[n-1][j][y] = grid[n-1][j];

            if(j != y) dp[n-1][j][y] += grid[n-1][y];
        }
    }

    for(int i=n-2; i>=0; i--) {
        for(int j=0; j<m; j++) {
            for(int y=0; y<m; y++) {
                int ans = 0;

                for(int a=-1; a<=1; a++) {
                    for(int b=-1; b<=1; b++) {
                        int val = 0;

                        if(j == y) {
                            val += grid[i][j];
                        }
                        else {
                            val += (grid[i][j] + grid[i][y]);
                        }

                        if(j+a < 0 || j+a > m-1 || y+b < 0 || y+b > m-1) {
                            val -= 1e8;
                        }
                        else val += dp[i+1][j+a][y+b];

                        ans = max(ans,val);
                    }
                }

                dp[i][j][y] = ans;
            }
        }
    }

    return dp[0][0][m-1];
}

int cherryPickup(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();

    vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (m,0)));

    return tabulation(grid,dp);
}