#include <bits/stdc++.h>
#include <queue>
#define ll long long
using namespace std;

void dfs(int i, int j, vector<vector<char>> &board, vector<vector<int>> &visited) {
    int n = board.size();
    int m = board[0].size();

    visited[i][j] = 1;

    int diff[4] = {1,0,-1,0};
    int diff2[4] = {0,1,0,-1};

    for(int a=0, b=0; a<4, b<4; a++, b++) {
        int x = i + diff[a];
        int y = j + diff2[b];

        if(x>=0 && x<n && y>=0 && y<m && board[x][y] == 'O' && !visited[x][y]) dfs(x,y,board,visited);
    }
}

void solve(vector<vector<char>> &board) {
    int n = board.size();
    int m = board[0].size();

    vector<vector<int>> visited(n, vector<int> (m,0));

    for(int i=0; i<n; i+=(n-1)) {
        for(int j=0; j<m; j++) {
            if(board[i][j] == 'O' && !visited[i][j]) dfs(i,j,board,visited);
        }
    }

    for(int j=0; j<m; j+=(m-1)) {
        for(int i=0; i<n; i++) {
            if(board[i][j] == 'O' && !visited[i][j]) dfs(i,j,board,visited);
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(!visited[i][j] == 0 && board[i][j] == 'O') board[i][j] = 'X';
        }
    }
}