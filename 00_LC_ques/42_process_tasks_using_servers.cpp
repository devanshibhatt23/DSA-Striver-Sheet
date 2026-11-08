#include <bits/stdc++.h>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int m = servers.size();
        int n = tasks.size();

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> free_servers;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> busy_servers;

        for(int i=0; i<m; i++) {
            free_servers.push({servers[i], i});
        }

        long long time = 0;
        vector<int> ans;

        for(int i=0; i<n; i++) {
            time = max(time, (long long)(i));

            while(!busy_servers.empty() && busy_servers.top().first <= time) {
                auto [t,idx] = busy_servers.top();
                busy_servers.pop();

                free_servers.push({servers[idx],idx});
            }

            if(free_servers.empty()) {
                time = busy_servers.top().first;

                while(!busy_servers.empty() && busy_servers.top().first <= time) {
                    auto [t,idx] = busy_servers.top();
                    busy_servers.pop();

                    free_servers.push({servers[idx],idx});
                }
            }

            auto [t,idx] = free_servers.top();
            ans.push_back(idx);

            busy_servers.push({time+tasks[i], idx});
            free_servers.pop();          
        }

        return ans;
    }
};