#include <bits/stdc++.h>
#include <queue>
using namespace std;

vector<int> dijkshtra_algo(vector<vector<pair<int,int>>> &adj_list, int src) {
    int n = adj_list.size();

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dis(n, INT_MAX);

    pq.push({0,src});
    dis[src] = 0; 

    while(!pq.empty()) {
        int i = pq.top().first;
        int distance = pq.top().second;
        pq.pop();

        for(auto it : adj_list[i]) {
            int node = it.first;
            int wt = it.second;

            if(wt + distance < dis[node]) {
                dis[node] = wt + distance;
                pq.push({dis[node],node});
            }
        }
    }

    return dis;
}