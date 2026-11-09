#include <bits/stdc++.h>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = arrival.size();

        vector<int> requests(k,0);

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> busy;
        set<int> free;

        for(int i=0; i<k; i++) {
            free.insert(i);
        }

        for(int i=0; i<n; i++) {
            while(!busy.empty() && busy.top().first <= arrival[i]) {
               int idx = busy.top().second;
               busy.pop();

               free.insert(idx);
            }

            if(!free.empty()) {
                auto it = free.lower_bound(i%k);

                if(it == free.end()) {
                    it = free.begin();
                }

                int idx = *it;

                busy.push({load[i]+arrival[i], idx});
                free.erase(it);
                requests[idx]++;
            }
        }

        int max_time = *max_element(requests.begin(), requests.end());

        vector<int> ans;
        for(int i=0; i<k; i++) {
            if(requests[i] == max_time) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};