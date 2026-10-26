#include <bits/stdc++.h>
#include <queue>
using namespace std;

class Solution {
public:
    void bfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis, long long &sum) {
        int m = grid.size(), n = grid[0].size();

        queue<pair<int,int>> q;
        q.push({i,j});

        vis[i][j] = 1;

        vector<int> diff = {-1,0,1,0,-1};

        while(!q.empty()) {
            auto [a,b] = q.front();
            q.pop();

            sum += grid[a][b];

            for(int i=0; i<4; i++) {
                int x = a + diff[i];
                int y = b + diff[i+1];

                if(x>=0 && x<m && y>=0 && y<n && !vis[x][y] && grid[x][y]) {
                    q.push({x,y});
                    vis[x][y] = 1;
                }
            }
        }
    }

    long long dfs(int i, int j, vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        if(i<0 || j<0 || i>=m || j>=n) return 0;
        if(grid[i][j] == 0) return 0;

        long long sum = grid[i][j];
        grid[i][j] = 0;

        long long val1 = dfs(i+1,j,grid);
        long long val2 = dfs(i,j+1,grid);
        long long val3 = dfs(i-1,j,grid);
        long long val4 = dfs(i,j-1,grid);

        sum += (val1 + val2 + val3 + val4);

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();

        // vector<vector<int>> vis(m, vector<int> (n,0));

        int ct = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                // if(grid[i][j] && !vis[i][j]) {
                //     long long sum = 0;
                //     bfs(i,j,grid,vis,sum);

                //     if(sum % k == 0) ct++;
                // }

                if(grid[i][j]) {
                    long long sum = dfs(i,j,grid);

                    if(sum % k == 0) ct++;
                }
            }
        }

        return ct;
    }
};