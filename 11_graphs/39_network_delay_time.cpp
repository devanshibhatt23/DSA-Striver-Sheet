#include <bits/stdc++.h>
#include <queue>
using namespace std;

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<int,int>>> adj_list(n+1);
    
    for(auto &vec : times) {
        adj_list[vec[0]].push_back({vec[1],vec[2]});
    }

    // mintime, node
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    vector<int> min_time(n+1,INT_MAX);

    pq.push({0,k});
    min_time[0] = 0;
    min_time[k] = 0;

    while(!pq.empty()) {
        auto [time_taken, src] = pq.top();
        pq.pop();

        for(auto &pr : adj_list[src]) {
            auto [node, add_time] = pr;

            if(min_time[node] > time_taken + add_time) {
                min_time[node] = time_taken + add_time;
                pq.push({min_time[node], node});
            }
        }
    }

    int ans = 0;
    for(int i : min_time) ans = max(ans,i);

    if(ans == INT_MAX) return -1;
    return ans;
}