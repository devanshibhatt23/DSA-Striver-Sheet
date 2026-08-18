#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        if(k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        if(k == 1) {
            int ans = -1;

            unordered_map<int,int> mp;
            for(int i=0; i<n; i++) {
                mp[nums[i]]++;
            }

            for(auto [val,ct] : mp) {
                if(ct == 1) ans = max(ans,val);
            }

            return ans;
        }

        int ans = -1;

        bool a = 0, b = 0;
        for(int i=1; i<n; i++) {
            if(nums[i] == nums[0]) {
                a = 1;
                break;
            }
        }

        for(int i=n-2; i>=0; i--) {
            if(nums[i] == nums[n-1]) {
                b = 1;
                break;
            }
        }

        if(a == 0) ans = nums[0];
        if(b == 0) ans = max(ans,nums[n-1]);

        return ans;
    }
};