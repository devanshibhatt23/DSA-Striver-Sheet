#include <bits/stdc++.h>
#include <queue>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int,int>>> adj_list(n);
    
    for(auto vec : flights) {
        adj_list[vec[0]].push_back({vec[1], vec[2]});
    }

    queue<tuple<int,int,int>> q;
    vector<int> dis(n,INT_MAX);

    // steps dis node
    q.push({0,0,src});
    dis[src] = 0;

    while(!q.empty()) {
        auto [steps,distance,i] = q.front();
        q.pop();

        if(steps > k) continue;

        for(auto pr : adj_list[i]) {
            auto [node,wt] = pr;

            if(distance + wt < dis[node] && steps <= k) {
                dis[node] = distance + wt;
                q.push({steps+1,dis[node],node});
            }
        }
    }

    if(dis[dst] == INT_MAX) return -1;
    return dis[dst];
}