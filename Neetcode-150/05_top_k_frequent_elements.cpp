#include <bits/stdc++.h>
#include <unordered_map>
#include <queue>
using namespace std;

// TC - O(n log n), SC - O(n)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();

        for(int i : nums) {
            mp[i]++;
        }

        vector<pair<int,int>> v;
        for(auto it : mp) {
            v.push_back({it.second, it.first});
        }

        sort(v.rbegin(), v.rend());

        vector<int> ans;
        for(int i=0; i<k; i++) {
            ans.push_back(v[i].second);
        }

        return ans;
    }
};

// TC - O(n log k), SC - O(n+k)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int> mp;
        for(int i : nums) {
            mp[i]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> min_heap;

        for(auto it : mp) {
            if(min_heap.size() > k) min_heap.pop();
            min_heap.push({it.second, it.first});
        }

        while(min_heap.size() > k) min_heap.pop();

        vector<int> ans;
        while(!min_heap.empty()) {
            ans.push_back(min_heap.top().second);
            min_heap.pop();
        }

        return ans;
    }
};

// TC - O(n), SC - O(n)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int> mp;
        for(int i : nums) {
            mp[i]++;
        }

        vector<vector<int>> count(n+1);

        for(auto it : mp) {
            count[it.second].push_back(it.first);
        }

        vector<int> ans;

        for(int i=n; i>0; i--) {
            for(int ct : count[i]) {
                ans.push_back(ct);

                if(ans.size() == k) {
                    return ans;
                }
            }
        }

        return ans;
    }
};