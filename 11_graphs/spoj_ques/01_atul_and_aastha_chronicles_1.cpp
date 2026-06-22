#include <bits/stdc++.h>
#include <queue>
using namespace std;

void solve() {
    int n,m;
    cin >> n >> m;

    vector<vector<int>> adj_list(n+1);

    while(m--) {
        int x,y;
        cin >> x >> y;

        adj_list[x].push_back(y);
        adj_list[y].push_back(x);
    }

    vector<int> dis(n+1,INT_MAX);
    queue<pair<int,int>> q;
    q.push({1,0});
    dis[1] = 0;

    while(!q.empty()) {
        auto [i,distance] = q.front();
        q.pop();

        if(i == n) continue;

        for(auto node : adj_list[i]) {
            if(dis[node] > distance+1) {
                dis[node] = distance + 1;
                q.push({node,dis[node]});
            } 
        }
    }

    cout << dis[n] << "\n";
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}