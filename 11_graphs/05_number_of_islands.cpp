#include <bits/stdc++.h>
#include <queue>
#define ll long long
using namespace std;

void bfs(pair<int,int> st, int n, int m, vector<vector<int>> &v, vector<vector<int>> &visited) {
    queue<pair<int,int>> q;
    q.push(st);

    int x = st.first, y = st.second;
    visited[x][y] = 1;

    while(!q.empty()) {
        pair<int,int> node = q.front();
        int i = node.first, j = node.second;
        q.pop();
        
        for(int diff=-1; diff<=1; diff++) {
            for(int diff2=-1; diff2<=1; diff2++) {
                if(diff == 0 && diff2 == 0) continue;

                int row = i + diff;
                int col = j + diff2;

                if(row >= 0 && row < n && col >= 0 && col < m) {
                    if(v[row][col] && !visited[row][col]) {
                        q.push({row,col});
                        visited[row][col] = 1;
                    }
                }
            }
        }
    }
}

int number_of_islands(int n, int m, vector<vector<int>> &v) {
    vector<vector<int>> visited(n, vector<int> (m,0));

    int island_ct = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(v[i][j] && !visited[i][j]) {
                bfs({i,j},n,m,v,visited);
                island_ct++;
            }
        }
    }

    return island_ct;
}

int main() {
    int n,m;
    cin >> n >> m;

    vector<vector<int>> v(n, vector<int> (m,0));

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> v[i][j];
        }
    }

    cout << number_of_islands(n,m,v);
}