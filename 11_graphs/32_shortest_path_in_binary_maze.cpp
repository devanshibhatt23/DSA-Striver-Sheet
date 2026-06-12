#include <bits/stdc++.h>
#include <queue>
using namespace std;

bool valid(int x, int y, int n) {
    if(x >= 0 && x < n && y >= 0 && y < n) return true;
    return false;
}

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    vector<vector<int>> dis(n, vector<int> (n,INT_MAX));

    pq.push({1,{0,0}});
    dis[0][0] = 1;

    while(!pq.empty()) {
        int distance = pq.top().first;
        int i = pq.top().second.first;
        int j = pq.top().second.second;

        pq.pop();

        int arr[] = {1,0,-1,0,1,1,-1,-1,1};

        for(int k=0; k<9; k++) {
            int x = i + arr[k];
            int y = j + arr[k+1];

            if(valid(x,y,n) && grid[x][y] == 0 && (dis[x][y] > distance+1)) {
                dis[x][y] = distance+1;
                pq.push({dis[x][y], {x,y}});
            } 
        }
    }

    if(dis[n-1][n-1] == INT_MAX || grid[n-1][n-1] == 0 || grid[0][0] == 0) return -1;
    return dis[n-1][n-1];
}