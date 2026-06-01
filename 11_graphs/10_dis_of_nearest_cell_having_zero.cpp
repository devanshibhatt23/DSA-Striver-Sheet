#include <bits/stdc++.h>
#include <queue>
#define ll long long
using namespace std;

void bfs(vector<vector<int>>& mat, vector<vector<int>> &updated) {
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>> visited(n, vector<int> (m,0));
    queue<pair<pair<int,int>,int>> q;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(mat[i][j] == 0) q.push({{i,j},0});
        }
    }

    while(!q.empty()) {
        int i = q.front().first.first;
        int j = q.front().first.second;
        int dis = q.front().second;
        q.pop();

        visited[i][j] = 1;
        updated[i][j] = dis;

        for(int diff=-1; diff<=1; diff++) {
            for(int diff2=-1; diff2<=1; diff2++) {
                if(diff * diff2 == 0 && diff!=diff2) {
                    int x = i + diff;
                    int y = j + diff2;
                    
                    if(x>=0 && x<n && y>=0 && y<m && !visited[x][y]) {
                        visited[x][y] = 1;
                        q.push({{x,y},dis+1});
                    }
                }
            }
        }
    }
}

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    
    vector<vector<int>> updated(n, vector<int> (m,0));
    bfs(mat,updated);

    return updated;
}