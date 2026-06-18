#include <bits/stdc++.h>
#include <queue>
using namespace std;

bool valid(int x, int y, int n) {
    if(x >= 0 && x < n && y >= 0 && y < n) return true;
    return false;
}

int largestIsland(vector<vector<int>> &grid) {
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
       
    int n = grid.size();

    DisjointSet ds(n*n);

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(grid[i][j]) {
                int node = i*n + j;
                int arr[] = {1,0,-1,0,1};

                for(int k=0; k<4; k++) {
                    int x = i + arr[k];
                    int y = j + arr[k+1];

                    if(valid(x,y,n) && grid[x][y]) {
                        int adj_node = x*n + y;
                        ds.unionBySize(node,adj_node);
                    }
                }
            }
        }
    }

    int ans = *max_element(ds.size.begin(), ds.size.end());

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int total_size = 1;
            if(grid[i][j] == 0) {
                set<int> visited_parents;

                int arr[] = {1,0,-1,0,1};

                for(int k=0; k<4; k++) {
                    int x = i + arr[k];
                    int y = j + arr[k+1];
                    int adj_node = x*n + y;

                    if(valid(x,y,n)) {
                        int parent = ds.findUltimateParent(adj_node);
                        if(grid[x][y] && visited_parents.find(parent) == visited_parents.end()) {
                            total_size += ds.size[parent];
                            visited_parents.insert(parent);
                        }
                    }
                }

                ans = max(ans,total_size);
            }
        }
    }

    return ans;
}