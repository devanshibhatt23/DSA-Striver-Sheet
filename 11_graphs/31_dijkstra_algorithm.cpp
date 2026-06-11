#include <bits/stdc++.h>
#include <queue>
using namespace std;

vector<int> dijkshtra_algo(vector<vector<pair<int,int>>> &adj_list, int src) {
    // tc - edges * log(n)
    int n = adj_list.size();

    set<pair<int,int>> st;
    vector<int> dis(n, INT_MAX);

    st.insert({0,src});
    dis[src] = 0; 

    while(!st.empty()) {
        auto it = *(st.begin());

        int i = it.first;
        int distance = it.second;
        st.erase(it);

        for(auto it : adj_list[i]) {
            int node = it.first;
            int wt = it.second;

            if(wt + distance < dis[node]) {
                dis[node] = wt + distance;
                st.insert({dis[node],node});
            }
        }
    }

    return dis;
}