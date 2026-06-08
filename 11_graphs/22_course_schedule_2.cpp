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

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    int n = numCourses;

    vector<vector<int>> adj_list(n);
    for(auto v : prerequisites) {
        adj_list[v[1]].push_back(v[0]);
    }

    vector<int> ans = kahns_algorithm(adj_list);

    if(ans.size() == n) return ans;
    else return {};
}