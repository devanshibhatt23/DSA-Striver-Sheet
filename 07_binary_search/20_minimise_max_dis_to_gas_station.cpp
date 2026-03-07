#include <bits/stdc++.h>
#include <queue>
#define ll long long
using namespace std;

double minMaxDist(vector<int> &stations, int K) {
    int n = stations.size();
    if(n == 1 && K) return 0;

    vector<int> ct(n-1,0);
    priority_queue<pair<double,int>> p;

    for(int i=1; i<n; i++) {
        p.push({stations[i] - stations[i-1], i-1});
    }

    for(int i=1; i<=K; i++) {
        auto pr = p.top();
        int idx = pr.second;

        p.pop();
        ct[idx]++;

        p.push({(stations[idx+1] - stations[idx]) / ct[idx], i-1});

        // cout << pr.first << " " << pr.second << " " << ct[idx] << "\n";
    }
    for(int i : ct) cout << i << " ";

    return (p.top()).first;
}

int main() {
    vector<int> nums = {3, 6, 12, 19, 33}, nums2 = {1,2,4,5};
    int k = 3;

    cout << minMaxDist(nums,k);
}