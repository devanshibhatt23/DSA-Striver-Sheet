#include <bits/stdc++.h>
#include <queue>
using namespace std;

vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
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
     
    int n = accounts.size();

    DisjointSet ds(n);
    unordered_map<string,int> mp;

    for(int i=0; i<n; i++) {
        for(int j=1; j<accounts[i].size(); j++) {
            string str = accounts[i][j];
            if(mp.find(str) == mp.end()) {
                mp[str] = i;
            }
            else {
                int parent = mp[str];
                ds.unionByRank(i,parent);
            }
        }
    }

    vector<vector<string>> merged_acc(n);
    vector<vector<string>> ans;

    for(auto &it : mp) {
        auto [mail,node] = it;

        int parent = ds.findUltimateParent(node);
        merged_acc[parent].push_back(mail);
    }

    for(int i=0; i<n; i++) {
        vector<string> vec = merged_acc[i];

        if(!vec.empty()) {
            sort(vec.begin(), vec.end());

            vector<string> temp(0);
            temp.push_back(accounts[i][0]);

            for(auto &str : vec) temp.push_back(str);

            ans.push_back(temp);
        }
    }

    return ans;
}