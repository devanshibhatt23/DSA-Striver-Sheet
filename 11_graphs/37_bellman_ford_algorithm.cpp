// only in directed graph, helps to determine negative cycles
#include <bits/stdc++.h>
#include <queue>
using namespace std;

vector<int> bellman_ford_algorithm(vector<vector<int>> &edges, int src, int n) {
    vector<int> dis(n,INT_MAX);
    dis[src] = 0;
    int k = n-1;

    // tc - n * m
    while(k--) {
        for(auto &vec : edges) {
            if(dis[vec[0]] != INT_MAX && dis[vec[0]] + vec[2] < dis[vec[1]]) {
                dis[vec[1]] = dis[vec[0]] + vec[2];
            }
        }
    }

    for(auto &vec : edges) {
        if(dis[vec[0]] != INT_MAX && dis[vec[0]] + vec[2] < dis[vec[1]]) {
            return {-1};
        }
    }    

    return dis;
}