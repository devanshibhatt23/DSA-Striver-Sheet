#include <bits/stdc++.h>
#include <queue>
#define ll long long
using namespace std;

bool bfs(int st, vector<int> &color, vector<vector<int>>& graph, vector<int> &visited) {
    int n = graph.size();

    queue<int> q;
    q.push(st);
    visited[st] = 1;
    color[st] = 1;

    while(!q.empty()) {
        int i = q.front();
        q.pop();

        for(int k=0; k<graph[i].size(); k++) {
            int node = graph[i][k];

            if(!visited[node]) {
                q.push(node);
                visited[node] = 1;
                color[node] = -color[i];
            }
            else {
                if(color[node] == color[i]) return false;
            }
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
            ans = ans & bfs(i,color,graph,visited);
            if(ans == 0) return ans;
        }
    }

    return ans;
}