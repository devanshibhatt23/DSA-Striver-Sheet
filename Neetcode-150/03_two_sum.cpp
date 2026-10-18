#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> mp;

        for(int i=0; i<n; i++) mp[nums[i]] = i;

        for(int i=0; i<n; i++) {
            if(mp.count(target - nums[i])) {
                int j = mp[target - nums[i]];

                if(i == j) continue;

                if(i < j) return {i,j};
                return {j,i};
            }
        }

        return {};
    }
};