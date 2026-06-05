#include <bits/stdc++.h>
#include <set>
using namespace std;

void dfs(int i, int j, int row0, int col0, vector<vector<int>> &grid, vector<vector<int>> &visited, vector<pair<int,int>> vec) {
    int n = grid.size();
    int m = grid[0].size();
    visited[i][j] = 1;

    vec.push_back({i-row0, j-col0});

    int diff[5] = {1,0,-1,0,1};

    for(int k=0; k<4; k++) {
        int x = i + diff[k];
        int y = j + diff[k+1];

        if(x>=0 && x<n && y>=0 && y<m && grid[x][y] == 1 && !visited[x][y]) {
            dfs(x,y,row0,col0,grid,visited,vec);
        }
    }
}

int distinctIslands(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    
    set<vector<pair<int,int>>> st;
    vector<vector<int>> visited(n, vector<int> (m,0));

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(grid[i][j] == 1 && !visited[i][j]) {
                vector<pair<int,int>> vec;
                dfs(i,j,i,j,grid,visited,vec);
                st.insert(vec);
            }
        }
    }

    return st.size();
}