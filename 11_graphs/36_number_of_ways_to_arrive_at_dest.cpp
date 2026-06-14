#include <bits/stdc++.h>
#include <queue>
using namespace std;

int countPaths(int n, vector<vector<int>> &roads) {
    const int k = 1e9+7;
    vector<vector<pair<long long,long long>>> adj_list(n);

    for(auto &vec : roads) {
        adj_list[vec[0]].push_back({vec[1],vec[2]});
        adj_list[vec[1]].push_back({vec[0],vec[2]});
    }

    priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
    vector<long long> min_time(n,2e18);
    vector<long long> ways(n,0);

    pq.push({0,0});
    min_time[0] = 0;
    ways[0] = 1;

    while(!pq.empty()) {
        auto [inital_time, src] = pq.top();
        long long src_ways = ways[src];
        pq.pop();

        if (inital_time > min_time[src]) continue;

        for(auto &pr : adj_list[src]) {
            auto [node, add_time] = pr;

            long long total_time = inital_time + add_time;

            if(min_time[node] > total_time) {
                min_time[node] = total_time;
                pq.push({total_time, node});
                ways[node] = src_ways;
                ways[node] %= k;
            }

            else if(min_time[node] == total_time) {
                ways[node] += src_ways;
                ways[node] %= k;
            }
        }
    }

    return (ways[n-1] % k);
}