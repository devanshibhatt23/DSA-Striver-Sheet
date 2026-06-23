#include <bits/stdc++.h>
#include <queue>
#define ll long long
using namespace std;

void bfs(int st, int s, vector<vector<int>> &adj_list, vector<int> &ct, int call_id, vector<int> &visited) {
    int n = adj_list.size()-1;

    ct[st]++;
    visited[st] = call_id;
    queue<pair<int,int>> q;
    q.push({st,0});

    while(!q.empty()) {
        auto [i,wt] = q.front();
        q.pop();

        for(auto node : adj_list[i]) {
            if(visited[node] != call_id && wt + 1 <= s) {
                visited[node] = call_id;
                ct[node]++;
                q.push({node,wt+1});
            }
        }
    }
}

void solve() {
    int n,m,k;
    cin >> n >> m >> k;

    vector<vector<int>> adj_list(n+1);

    while(m--) {
        int x,y;
        cin >> x >> y;

        adj_list[x].push_back(y);
        adj_list[y].push_back(x);
    }

    vector<int> ct(n+1,0);
    vector<int> visited(n+1,0);

    int call_id = 0;

    while(k--) {
        int node, soldiers;
        cin >> node >> soldiers;

        call_id++;
        bfs(node,soldiers,adj_list,ct,call_id,visited);
    }

    for(int i=1; i<=n; i++) {
        if(ct[i] > 1 || ct[i] == 0) {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}