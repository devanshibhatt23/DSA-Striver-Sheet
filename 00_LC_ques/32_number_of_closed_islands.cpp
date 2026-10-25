#include <bits/stdc++.h>
#include <queue>
using namespace std;

class Solution {
public:
    bool bfs(int i, int j, int m, int n, vector<vector<int>>& grid, vector<vector<int>> &vis) {
        queue<pair<int,int>> q;
        q.push({i,j});

        bool closed = 1;

        vector<int> diff = {-1,0,1,0,-1};

        while(!q.empty()) {
            auto [x,y] = q.front();
            q.pop();

            for(int a=0; a<4; a++) {
                int r = x + diff[a];
                int c = y + diff[a+1];

                if(r<0 || r>=m || c<0 || c>=n) {
                    closed = 0;
                }
                else if(!vis[r][c] && grid[r][c] == 0) {
                    q.push({r,c});
                    vis[r][c] = 1;
                }
            }
        }

        return closed;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> vis(m, vector<int> (n));

        int ct = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 0 && !vis[i][j] && bfs(i,j,m,n,grid,vis)) {
                    ct++;
                }
            }
        }

        return ct;
    }
};