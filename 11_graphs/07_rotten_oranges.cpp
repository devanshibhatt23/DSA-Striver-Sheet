#include <bits/stdc++.h>
#include <queue>
#define ll long long
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> visited(n, vector<int> (m,0));
    queue<pair<pair<int,int>,int>> q;

    int ct = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(grid[i][j] == 2) {
                q.push({{i,j},0});
                visited[i][j] = 1;
            }
        }
    }

    while(!q.empty()) {
        pair<pair<int,int>,int> rotten = q.front();
        q.pop();

        int i = rotten.first.first;
        int j = rotten.first.second;

        int k = rotten.second;

        for(int diff=-1; diff<=1; diff++) {
            for(int diff2=-1; diff2<=1; diff2++) {
                if(diff * diff2) continue;

                int x = i + diff;
                int y = j + diff2;

                if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1 && !visited[x][y]) {
                    grid[x][y] = 2;
                    visited[x][y] = 1;
                    q.push({{x,y}, k+1});
                }
            }
        }
        ct = max(ct,k);
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(!visited[i][j] && grid[i][j] == 1) return -1;
        }
    }

    return ct;
}

int main() {
    int n,m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int> (m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> grid[i][j];
        }
    }

    cout << orangesRotting(grid);
}