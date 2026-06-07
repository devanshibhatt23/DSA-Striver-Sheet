#include <bits/stdc++.h>
#include <queue>
#define ll long long
using namespace std;

bool dfs(int st, vector<vector<int>> &adj_list, vector<int> &visited, vector<int> &path_visited, vector<int> &check) {
    visited[st] = 1;
    path_visited[st] = 1;
    check[st] = 0;

    for(int node : adj_list[st]) {
        if(!visited[node] && dfs(node,adj_list,visited,path_visited,check)) {
            return true;
        }
        else if(path_visited[node]) return true;
    }

    check[st] = 1;
    path_visited[st] = 0;
    return false;
}

vector<int> safe_nodes(int start, vector<vector<int>> &adj_list, vector<int> &visited, vector<int> &path_visited) {
    int n = visited.size()-1;
    vector<int> safenodes;
    vector<int> check(n+1,0);

    for(int i=1; i<=n; i++) {
        if(!visited[i]) {
            dfs(start,adj_list,visited,path_visited,check);
        }
    }

    for(int i=1; i<=n; i++) {
        if(check[i]) safenodes.push_back(i);
    }

    return safenodes;
}