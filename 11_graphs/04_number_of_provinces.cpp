#include <bits/stdc++.h>
#include <queue>
#define ll long long
using namespace std;

void dfs(int start, vector<vector<int>> &v, vector<int> &visited) {
    visited[start] = 1;

    for(int node : v[start]) {
        if(!visited[node]) {
            dfs(node,v,visited);
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();

    vector<int> visited(n+1,0);
    vector<vector<int>> adj_list(n+1, vector<int> (0));

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(isConnected[i][j] == 1 && i != j) {
                adj_list[i+1].push_back(j+1);
                adj_list[j+1].push_back(i+1); 
            }
        }
    }

    int ct = 0;

    for(int i=1; i<=n; i++) {
        if(visited[i] == 0) {
            ct++;
            dfs(i,adj_list,visited);
        }
    }
    
    return ct;
}