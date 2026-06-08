#include <bits/stdc++.h>
#include <queue>
using namespace std;

int kahnsalgorithm(vector<vector<int>> &adj_list) {
    int n = adj_list.size();
    int ct = 0;

    vector<int> in_degree(n,0);
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
        int st = q.front();
        q.pop();
        ct++;

        for(int node : adj_list[st]) {
            in_degree[node]--;

            if(in_degree[node] == 0) q.push(node);
        }
    }

    return ct;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    int n = numCourses;

    vector<vector<int>> adj_list(n);
    for(auto v : prerequisites) {
        adj_list[v[1]].push_back(v[0]);
    }

    if(kahnsalgorithm(adj_list) == n) return true;
    return false;
}