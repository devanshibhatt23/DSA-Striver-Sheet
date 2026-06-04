#include <bits/stdc++.h>
#include <queue>
#define ll long long
using namespace std;

void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &visited) {
    int n = grid.size();
    int m = grid[0].size();

    visited[i][j] = 1;

    int diff[4] = {1,0,-1,0};
    int diff2[4] = {0,1,0,-1};

    for(int a=0, b=0; a<4, b<4; a++, b++) {
        int x = i + diff[a];
        int y = j + diff2[b];

        if(x>=0 && x<n && y>=0 && y<m && grid[x][y] == 1 && !visited[x][y]) dfs(x,y,grid,visited);
    }
}

int numEnclaves(vector<vector<int>> &grid) {
    int ct = 0;
    int n = grid.size();
    int m = grid[0].size();

    if(n == 1 || m == 1) return 0;

    vector<vector<int>> visited(n, vector<int> (m,0));

    for(int i=0; i<n; i+=(n-1)) {
        for(int j=0; j<m; j++) {
            if(grid[i][j] == 1 && !visited[i][j]) dfs(i,j,grid,visited);
        }
    }

    for(int j=0; j<m; j+=(m-1)) {
        for(int i=0; i<n; i++) {
            if(grid[i][j] == 1 && !visited[i][j]) dfs(i,j,grid,visited);
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(!visited[i][j] && grid[i][j] == 1) ct++;
        }
    }

    return ct;
}