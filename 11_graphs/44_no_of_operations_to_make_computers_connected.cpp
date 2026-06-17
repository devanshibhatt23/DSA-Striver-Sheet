#include <bits/stdc++.h>
#include <queue>
using namespace std;

int makeConnected(int n, vector<vector<int>> &connections) {
    class DisjointSet {
        public:
        vector<int> rank,parent,size;
        DisjointSet(int n) {
            rank.resize(n+1,0);
            size.resize(n+1,1);
            parent.reserve(n+1);

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

    DisjointSet ds(n);
    int extra_edges = 0;
    int components = 0;

    for(auto &it : connections) {
        int u = it[0], v = it[1];

        int ultparent_u = ds.findUltimateParent(u);
        int ultparent_v = ds.findUltimateParent(v);

        if(ultparent_u == ultparent_v) extra_edges++;
        else ds.unionByRank(u,v);
    }

    for(int i=0; i<n; i++) {
        if(ds.parent[i] == i) components++;
    }

    if(extra_edges >= components-1) return components-1;
    return -1;
}