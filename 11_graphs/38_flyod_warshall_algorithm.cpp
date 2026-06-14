#include <bits/stdc++.h>
#include <queue>
using namespace std;

vector<vector<int>> flyod_warshall(int n, vector<vector<int>> &edges) {
    vector<vector<int>> dis(n,vector<int> (n,INT_MAX));

    for(int i=0; i<n; i++) dis[i][i] = 0;

    for(auto &vec : edges) {
        dis[vec[0]][vec[1]] = vec[2];
    }

    for(int via=0; via<n; via++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][via] + dis[via][j]);
            }
        }
    }

    for(int i=0; i<n; i++) if(dis[i][i] < 0) return {{-1}};
}