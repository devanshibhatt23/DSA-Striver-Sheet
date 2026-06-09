#include <bits/stdc++.h>
#include <queue>
using namespace std;

vector<int> kahns_algorithm(vector<vector<int>> &adj_list) {
    int n = adj_list.size();

    vector<int> in_degree(n,0);
    vector<int> sorted;
    queue<int> q;

    for(int i=0; i<n; i++) {
        for(int node : adj_list[i]) {
            in_degree[node]++;
        }
    }

    for(int i=0; i<n; i++) {
        if(in_degree[i] == 0) q.push(i);
    }

    while(!q.empty()) {
        int i = q.front();
        q.pop();
        sorted.push_back(i);

        for(int node : adj_list[i]) {
            in_degree[node]--;

            if(in_degree[node] == 0) q.push(node);
        }
    }

    return sorted;
}

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    
    vector<vector<int>> adj_list(n);

    for(int i=0; i<n; i++) {
        for(int node : graph[i]) {
            adj_list[node].push_back(i);
        }
    }

    vector<int> ans = kahns_algorithm(adj_list);
    sort(ans.begin(), ans.end());
    return ans;
}