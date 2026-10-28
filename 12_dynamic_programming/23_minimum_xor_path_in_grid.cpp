#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
    int tabulation(int m, int n, vector<vector<int>>& grid) {
        vector<vector<vector<bool>>> dp(m, vector<vector<bool>> (n, vector<bool> (1024,0)));

        dp[0][0][grid[0][0]] = true;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                for(int x=0; x<1024; x++) {
                    if(dp[i][j][x] == false) continue;

                    if(i<m-1) dp[i+1][j][x ^ grid[i+1][j]] = true;
                    if(j<n-1) dp[i][j+1][x ^ grid[i][j+1]] = true;
                }
            }
        }

        for(int i=0; i<1024; i++) {
            if(dp[m-1][n-1][i]) return i;
        }

        return -1;
    } 

public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        return tabulation(m,n,grid);
    }
};