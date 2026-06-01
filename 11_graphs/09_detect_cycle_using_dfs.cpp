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

bool dfs(int start, int parent, vector<vector<int>> &adj_list, vector<int> &visited) {
    visited[start] = 1;

    for(int i : adj_list[start]) {
        if(!visited[i]) {
            visited[i] = 1;
            if(dfs(i,start,adj_list,visited)) return true;
        }
        else {
            if(i == parent) continue;
            else return true;
        }
    }

    return false;
}

bool cycle(int start, vector<vector<int>> &adj_list, vector<int> &visited) {
    int n = visited.size()-1;

    for(int i=1; i<=n; i++) {
        if(!visited[i]) {
            if(dfs(start,-1,adj_list,visited)) return true;
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

    cout << cycle(start,adj_list,visited);
}