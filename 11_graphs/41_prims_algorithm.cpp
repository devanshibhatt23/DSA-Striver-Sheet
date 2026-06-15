// spanning tree - tree having n nodes and n-1 edges, and each node is reachable from all other nodes
// min spanning tree - a st having min total sum of edge weights

#include <bits/stdc++.h>
#include <queue>
using namespace std;

int prims_algorithm(vector<vector<pair<int,int>>> &adj_list) {
    int n = adj_list.size();
    
    // weight, node, parent
    // sc - o(edges)
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
    vector<pair<int,int>> mst;
    vector<int> visited(n,0);

    int mst_sum = 0;

    pq.push({0,0,-1});
    visited[0] = 1;

    // tc - o(edges * log(edges))
    while(!pq.empty()) {
        auto [wt, node, parent] = pq.top();
        pq.pop();

        if(visited[node]) continue;

        mst_sum += wt;
        
        visited[node] = 1;
        if(parent != -1) mst.push_back({parent,node});

        for(auto &[i,add_wt] : adj_list[node]) {
            if(!visited[i]) pq.push({wt+add_wt,i,node});
        }
    }

    return mst_sum;
}