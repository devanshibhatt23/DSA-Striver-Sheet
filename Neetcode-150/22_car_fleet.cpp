#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        vector<pair<int,int>> time(n);
        for(int i=0; i<n; i++) {
            time[i] = {position[i], speed[i]};
        }

        sort(time.rbegin(), time.rend());

        int ans = 1;

        double prev_time = (double)(target-time[0].first) / time[0].second;
        
        for(int i=1; i<n; i++) {
            double curr_time = (double)(target-time[i].first) / time[i].second;

            if(curr_time <= prev_time) {
                continue;
            }

            prev_time = curr_time;
            ans++;
        }

        return ans;
    }
};