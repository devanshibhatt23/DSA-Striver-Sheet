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

void dfs(int start, vector<vector<int>> &v, vector<int> &visited) {
    cout << start << " ";
    visited[start] = 1;

    for(int node : v[start]) {
        if(!visited[node]) {
            dfs(node,v,visited);
        }
    }
}

int main() {
    int n,m;
    cin >> n >> m;

    vector<vector<int>> v = adjacency_list(n,m);
    vector<int> visited(n+1,0);

    int start;
    cin >> start;

    dfs(start,v,visited);
}