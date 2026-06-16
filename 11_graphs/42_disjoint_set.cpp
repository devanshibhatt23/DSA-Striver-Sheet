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

int main() {
    DisjointSet ds(7);

    // tc - o(1)
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);

    if(ds.findUltimateParent(3) == ds.findUltimateParent(7)) {
        cout << "Same parent\n";
    }
    else cout << "Not same parent\n";

    ds.unionBySize(3,7);

    if(ds.findUltimateParent(3) == ds.findUltimateParent(7)) {
        cout << "Same parent\n";
    }
    else cout << "Not same parent\n";
}