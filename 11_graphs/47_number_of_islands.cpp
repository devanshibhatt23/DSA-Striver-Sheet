#include <bits/stdc++.h>
#include <queue>
using namespace std;

bool valid(int x, int y, int n, int m) {
    if(x >= 0 && x < n && y >= 0 && y < m) return true;
    return false;
}

vector<int> numOfIslands(int n, int m, vector<vector<int>> &matrix) {
    class DisjointSet {
        public:
        vector<int> rank,parent,size;
        DisjointSet(int n) {
            rank.resize(n+1,0);
            size.resize(n+1,1);
            parent.resize(n+1);

            for(int i=0; i<=n; i++) {
                parent[i] = i; 
            }
        }

        int findUltimateParent(int node) {
            if(node == parent[node]) {
                return node;
            }
            return parent[node] = findUltimateParent(parent[node]);
        }

        void unionByRank(int u, int v) {
            int ultparent_u = findUltimateParent(u);
            int ultparent_v = findUltimateParent(v);

            if(ultparent_u == ultparent_v) return;

            if(rank[ultparent_u] < rank[ultparent_v]) {
                parent[ultparent_u] = ultparent_v;
            }
            else if(rank[ultparent_v] < rank[ultparent_u]) {
                parent[ultparent_v] = ultparent_u;
            }
            else {
                parent[ultparent_u] = ultparent_v;
                rank[ultparent_u]++;
            }
        }

        void unionBySize(int u, int v) {
            int ultparent_u = findUltimateParent(u);
            int ultparent_v = findUltimateParent(v);

            if(ultparent_u == ultparent_v) return;

            if(size[ultparent_u] < size[ultparent_v]) {
                parent[ultparent_u] = ultparent_v;
                size[ultparent_v] += size[ultparent_u];
            }
            else {
                parent[ultparent_v] = ultparent_u;
                size[ultparent_u] += size[ultparent_v];
            }
        }
    };
       
    vector<int> ans(0);

    vector<vector<int>> visited(n, vector<int> (m,0));
    DisjointSet ds(n*m);

    int ct = 0;

    for(auto &vec : matrix) {
        int i = vec[0], j = vec[1];
        int node = i*m + j*n;

        if(visited[i][j]) {
            ans.push_back(ct);
            continue;
        }

        ct++;
        visited[i][j] = 1;

        int arr[] = {1,0,-1,0,1};
        for(int k=0; k<4; k++) {
            int x = i + arr[k];
            int y = j + arr[k+1];

            if(valid(x,y,n,m) && visited[x][y]) {
                int adj_node = x*m + y*n;

                if(ds.findUltimateParent(adj_node) != ds.findUltimateParent(node)) {
                    ds.unionByRank(adj_node,node);
                    ct--;
                }
            }
        }

        ans.push_back(ct);
    }

    return ans;
}