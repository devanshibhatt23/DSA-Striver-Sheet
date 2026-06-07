#include <bits/stdc++.h>
#include <queue>
#define ll long long
using namespace std;

vector<vector<int>> adjacency_list(int n, int m) {
    vector<vector<int>> arr(n+1, vector<int> (0));

    while(m--) {
        int x,y;
        cin >> x >> y;

        arr[x].push_back(y);
        arr[y].push_back(x);
    }

    return arr;
}

bool dfs(int st, vector<vector<int>> &adj_list, vector<int> &visited, vector<int> &path_visited) {
    visited[st] = 1;
    path_visited[st] = 1;

    for(int node : adj_list[st]) {
        if(!visited[st] && dfs(node,adj_list,visited,path_visited)) return true;
        else if(path_visited[node]) return true;
    }

    path_visited[st] = 0;
    return false;
}

bool cycle(int start, vector<vector<int>> &adj_list, vector<int> &visited, vector<int> &path_visited) {
    int n = visited.size()-1;

    for(int i=1; i<=n; i++) {
        if(!visited[i]) {
            if(dfs(start,adj_list,visited,path_visited)) return true;
        }
    }

    return false;
}

int main() {
    int n,m;
    cin >> n >> m;

    int start;
    cin >> start;

    vector<vector<int>> adj_list = adjacency_list(n,m);
    vector<int> visited(n+1, 0);
    vector<int> path_visited(n+1, 0);

    cout << cycle(start,adj_list,visited,path_visited);
}