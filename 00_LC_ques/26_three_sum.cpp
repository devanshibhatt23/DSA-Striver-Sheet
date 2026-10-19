#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        set<vector<int>> ans;

        for(int i=0; i<n; i++) {
            unordered_map<int,int> mp;

            for(int j=i+1; j<n; j++) {
                if(mp.count(-nums[i]-nums[j])) {
                    int k = -nums[i]-nums[j];

                    vector<int> triplet = {nums[i],nums[j],k};
                    sort(triplet.begin(), triplet.end());

                    ans.insert(triplet);
                }
                else {
                    mp[nums[j]] = 1;
                }
            }
        }

        vector<vector<int>> v(ans.begin(), ans.end());

        return v;
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>> v;

        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;

            if(nums[i] > 0) break;

            int j = i+1, k = n-1;
            while(j < k) {
                int val = nums[i] + nums[j] + nums[k];
    
                if(val < 0) {
                    j++;
                }
                else if(val == 0) {
                    v.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;

                    while(j<n && nums[j] == nums[j-1]) j++;
                    while(k>=0 && nums[k] == nums[k+1]) k--;
                }
                else {
                    k--;
                }
            }
        }

        return v;
    }
};