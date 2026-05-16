#include <bits/stdc++.h>
#define ll long long
using namespace std;

void adjacency_matrix(int n, int m) {
    // space - O(n^2)
    vector<vector<int>> v(n+1, vector<int> (n+1,0));

    while(m--) {
        int x,y;
        cin >> x >> y;

        v[x][y] = 1;
        v[y][x] = 1;
    } 
}

void adjacency_list(int n, int m) {
    // space - O(2*m)
    vector<int> arr[n+1];

    while(m--) {
        int x,y;
        cin >> x >> y;

        arr[x].push_back(y);
        arr[y].push_back(x);
    }
}

void weighted_graph_matrix(int n, int m) {
    vector<vector<int>> v(n+1, vector<int> (n+1,0));

    while(m--) {
        int x,y,weight;
        cin >> x >> y >> weight;

        v[x][y] = weight;
        v[y][x] = weight;
    }
}

void weighted_graph_list(int n, int m) {
    vector<pair<int,int>> arr[n+1];

    while(m--) {
        int x,y,weight;
        cin >> x >> y >> weight;

        arr[x].push_back({y,weight});
        arr[y].push_back({x,weight});
    }
}

int main() {
    int n,m;
    cin >> n >> m;

    adjacency_matrix(n,m);
}