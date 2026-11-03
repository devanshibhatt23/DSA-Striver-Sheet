#include <bits/stdc++.h>
using namespace std;

class TimeMap {
public:
    unordered_map<string, vector<pair<int,string>>> mp;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        auto &vec = mp[key];

        int n = vec.size();
        int l = 0, r = n-1;

        string ans = "";

        while(l <= r) {
            int mid = l + (r-l)/2;
            int time = vec[mid].first;

            if(time <= timestamp) {
                ans = vec[mid].second;
                l = mid+1;
            }
            else {
                r = mid-1;
            }
        }

        return ans;
    }
};