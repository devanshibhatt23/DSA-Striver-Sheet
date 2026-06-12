#include <bits/stdc++.h>
#include <queue>
using namespace std;

bool valid(int x, int y, int n, int m) {
    if(x >= 0 && x < n && y >= 0 && y < m) return true;
    return false;
}

int minimumEffortPath(vector<vector<int>>& heights) {
    int n = heights.size();
    int m = heights[0].size();
    
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    vector<vector<int>> dis(n, vector<int> (m,INT_MAX));

    pq.push({0, {0,0}});
    dis[0][0] = 0;

    int arr[] = {1,0,-1,0,1};

    while(!pq.empty()) {
        auto [diff, pos] = pq.top();
        pq.pop();
        auto [i,j] = pos;

        if(i == n-1 && j == m-1) return diff;

        for(int k=0; k<4; k++) {
            int x = i + arr[k];
            int y = j + arr[k+1];
            
            if(valid(x,y,n,m)) {
                int new_effort = max(diff,abs(heights[i][j]-heights[x][y]));
                if(dis[x][y] > new_effort) {
                    dis[x][y] = new_effort;
                    pq.push({dis[x][y], {x,y}});
                }
            }
        }
    }

    return dis[n-1][m-1];
}