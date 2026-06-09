#include <bits/stdc++.h>
#include <stack>
using namespace std;

void dfs(int i, vector<vector<pair<int,int>>> &adj_list, vector<int> &visited, stack<int> &st) {
    visited[i] = 1;
    
    for(auto pr : adj_list[i]) {
        if(!visited[pr.first]) dfs(pr.first,adj_list,visited,st);
    }

    st.push(i);
}

vector<int> topo_sort(vector<vector<pair<int,int>>> &adj_list, int src) {
    int n = adj_list.size();

    vector<int> dis(n,INT_MAX);
    dis[src] = 0;

    vector<int> visited(n,0);
    stack<int> st;

    for(int i=0; i<n; i++) {
        if(!visited[i]) dfs(i,adj_list,visited,st);
    }

    while(!st.empty()) {
        int i = st.top();
        st.pop();

        for(auto pr : adj_list[i]) {
            int node = pr.first;
            int add_wt = pr.second;
            int wt = dis[i];

            if(dis[node] > wt + add_wt) dis[node] = wt + add_wt;
        }
    }

    for(int &i : dis) {
        if(i == INT_MAX) i = -1;
    }

    return dis;
}

vector<int> shortestPath(vector<vector<pair<int,int>>> &adj_list, int n, int src) {
    return topo_sort(adj_list,src);
}