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

int main() {
    int n,m;
    cin >> n >> m;

    vector<vector<int>> v = adjacency_list(n,m);
    queue<int> q;
    vector<int> visited(n+1,0);

    int start;
    cin >> start;

    q.push(start);
    visited[start] = 1;

    while(!q.empty()) {
        int root = q.front();
        cout << root << " ";
        q.pop();

        for(int i=0; i<v[root].size(); i++) {
            int num = v[root][i];

            if(!visited[num]) {
                q.push(num);
                visited[num] = 1;
            }
        }
    }
}