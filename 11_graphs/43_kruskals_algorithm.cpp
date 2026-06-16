#include <bits/stdc++.h>
#include <queue>
using namespace std;

class DisjointSet {
    vector<int> rank,parent,size;

public:
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

int mst_by_kruskals_algorithm(vector<vector<int>> &edges, int n) {
    // o(edges * log(edges))
    sort(edges.begin(), edges.end());
    int mst_wt = 0;

    DisjointSet ds(n);

    // o(edges)
    for(auto &it : edges) {
        int wt = it[0], u = it[1], v = it[2];

        int ultparent_u = ds.findUltimateParent(u);
        int ultparent_v = ds.findUltimateParent(v);

        if(ultparent_u != ultparent_v) {
            mst_wt += wt;
            ds.unionByRank(u,v);
        }
    }

    return mst_wt;
}