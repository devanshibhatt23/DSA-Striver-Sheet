#include <bits/stdc++.h>
#include <queue>
using namespace std;

vector<int> kahns_algorithm(vector<vector<int>> &adj_list) {
    int n = adj_list.size()-1;
    
    vector<int> in_degree(n+1,0);
    vector<int> sorted;
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
        sorted.push_back(node);
        q.pop();

        for(auto it : adj_list[node]) {
            in_degree[it]--;

            if(in_degree[it] == 0) q.push(it);
        }
    }

    return sorted;
}