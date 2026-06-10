#include <bits/stdc++.h>
#include <queue>
using namespace std;

vector<int> bfs(vector<vector<pair<int,int>>> &adj_list, int src) {
    int n = adj_list.size();
    vector<int> dis(n,INT_MAX);

    vector<int> visited(n,0);
    queue<pair<int,int>> q;

    q.push({src,0});

    while(!q.empty()) {
        int i = q.front().first;
        int wt = q.front().second;
        q.pop();

        dis[i] = min(dis[i], wt);
        visited[i] = 1;

        for(auto pr : adj_list[i]) {
            if(!visited[pr.first]) {
                q.push({pr.first, pr.second + wt});
            }
        }
    }

    for(int &i : dis) {
        if(i == INT_MAX) i = -1;
    }
    
    return dis;
}

vector<int> shortest_path(vector<vector<pair<int,int>>> &adj_list, int src) {
    return bfs(adj_list,src);
}