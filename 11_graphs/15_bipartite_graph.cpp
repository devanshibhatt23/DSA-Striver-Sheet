#include <bits/stdc++.h>
#include <queue>
#define ll long long
using namespace std;

bool dfs(int st, int col, vector<vector<int>> &graph, vector<int> &visited, vector<int> &color) {
    int n = graph.size();

    visited[st] = 1;
    color[st] = col;

    for(int k=0; k<graph[st].size(); k++) {
        int node = graph[st][k];

        if(!visited[node]) {
            if(!dfs(node,-col,graph,visited,color)) {
                return false;
            }
        }
        else {
            if(color[node] == col) return false;
        }
    }

    return true;
}

bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> visited(n,0);
    vector<int> color(n);

    bool ans = 1;

    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            ans = ans & dfs(i,1,graph,visited,color);
            if(ans == 0) return ans;
        }
    }

    return ans;
}