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

bool check_for_each_component(vector<vector<int>> &adj_list, int start, vector<int> &visited) {
    queue<pair<int,int>> q;

    q.push({start,-1});
    visited[start] = 1;

    while(!q.empty()) {
        pair<int,int> pr = q.front();
        q.pop();

        int st = pr.first;
        int parent = pr.second;

        for(int i : adj_list[st]) {
            if(!visited[i]) {
                q.push({i,parent});
                visited[i] = 1;
            }
            else if(i == parent) continue;
            else return true;
        }
    }

    return false;
}

bool cycle(vector<vector<int>> &adj_list, int start, vector<int> &visited) {
    int n = visited.size()-1;

    for(int i=1; i<n+1; i++) {
        if(!visited[i]) {
            if(check_for_each_component(adj_list,start,visited)) return true;
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

    cout << cycle(adj_list,start,visited);
}