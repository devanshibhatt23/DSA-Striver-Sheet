#include <bits/stdc++.h>
#include <queue>
using namespace std;

int minimumMultiplications(vector<int> &arr, int start, int end) {
    const int k = 100000;

    queue<pair<int,int>> q;
    q.push({0,start});
    vector<int> dis(k,INT_MAX);
    dis[start] = 0;
    
    while(!q.empty()) {
        auto [steps, i] = q.front();
        q.pop();
        
        if(i == end) return steps;

        for(int &node : arr) {
            long long val = (i * 1LL * node) % k;
            if(steps+1 < dis[val]) {
                q.push({steps+1, val});
                dis[val] = steps + 1;
                if(val == end) return steps+1;
            }
        }
    }

    return -1;
}