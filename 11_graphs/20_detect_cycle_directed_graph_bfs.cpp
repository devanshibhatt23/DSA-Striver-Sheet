#include <bits/stdc++.h>
#include <queue>
using namespace std;

int kahns_algorithm(vector<vector<int>> &adj_list) {
    int n = adj_list.size()-1;
    int ct = 0;
    
    vector<int> in_degree(n+1,0);
    queue<int> q;

    for(int i=1; i<=n; i++) {
        for(int node : adj_list[i]) {
            in_degree[node]++;
        }
    }

    for(int i=1; i<=n; i++) {
        if(in_degree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int node = q.front();
        ct++;
        q.pop();

        for(auto it : adj_list[node]) {
            in_degree[it]--;

            if(in_degree[it] == 0) q.push(it);
        }
    }

    return ct;
}

bool cycle(vector<vector<int>> &adj_list) {
    int n = adj_list.size() - 1;

    if(kahns_algorithm(adj_list) != n) return true;
    return false;
}